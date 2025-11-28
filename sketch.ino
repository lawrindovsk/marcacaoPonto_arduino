/* PROJETO: Batedor de Ponto Assistivo
  PLATAFORMA: Wokwi Simulator
  POR: Gustavo Laurindo dos Santos (lawrindovsk)
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// 1. CONFIGURAÇÃO DO LCD
// Endereço 0x27 é o padrão para displays I2C no Wokwi.
LiquidCrystal_I2C lcd(0x27, 16, 2);

// 2. PINOS DO HARDWARE
const int pinoTrig = 7;
const int pinoEcho = 6;
const int pinoBuzzer = 8;

// 3. VARIÁVEIS DE CONTROLE
bool pontoRegistrado = false;

void setup() {
  // Inicia o LCD
  lcd.init();
  lcd.backlight(); // Acende a luz de fundo
  
  // Configura Pinos
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  
  // Tela de Boot
  lcd.setCursor(0,0);
  lcd.print("SISTEMA DE PONTO");
  lcd.setCursor(0,1);
  lcd.print("INICIANDO...");
  delay(2000);
  mostrarTelaEspera();
}

void loop() {
  // --- LEITURA DO SENSOR ---
  long duracao, distancia;
  
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);
  
  duracao = pulseIn(pinoEcho, HIGH);
  distancia = (duracao / 2) / 29.1; // Conversão padrão para cm
  
  // --- LÓGICA DO SISTEMA ---
  
  // Se aproximou (Braço robótico encostou - menos de 10cm)
  if (distancia < 10 && distancia > 0) {
    
    if (!pontoRegistrado) {
      registrarPonto();
      pontoRegistrado = true; // Trava para não marcar repetido
    }
    
  } else {
    // Se afastou (mais de 15cm), destrava o sistema
    if (distancia > 15 && pontoRegistrado) {
      pontoRegistrado = false;
      mostrarTelaEspera();
    }
  }
  
  delay(100); // Estabilidade
}

// --- FUNÇÕES DE APOIO ---

void mostrarTelaEspera() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("APROXIME O BRACO");
  lcd.setCursor(0, 1);
  lcd.print(">>> Aguardando");
}

void registrarPonto() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PONTO MARCADO!");
  lcd.setCursor(0, 1);
  lcd.print("Horario: 08:00"); // horário ficticio
  
  // Som de deu certo
  tone(pinoBuzzer, 1800, 200); // 1800Hz por 200ms
  delay(250);
  tone(pinoBuzzer, 2200, 400); // 2200Hz por 400ms
  delay(2000); // Mantém a mensagem na tela
}