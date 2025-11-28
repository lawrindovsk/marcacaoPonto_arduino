# 🕒 Batedor de Ponto Assistivo – Arduino (Wokwi)

Projeto desenvolvido para simulação no **Wokwi**, utilizando **Arduino Uno**, **Sensor Ultrassônico HC-SR04**, **LCD 16x2 I2C** e **Buzzer**. O objetivo é criar um protótipo simples de **bater ponto assistivo**, detectando presença e exibindo mensagens no display.

## 📌 Descrição do Projeto
O sistema mede a distância usando o sensor ultrassônico e, com base nisso:
- Exibe mensagens no LCD  
- Aciona um buzzer  
- Simula um registro de ponto assistivo

## 🔧 Componentes Utilizados
- Arduino Uno  
- LCD 16x2 com I2C  
- Sensor HC-SR04  
- Buzzer  
- Jumpers  

## 📐 Esquema de Ligações

### LCD 16x2 → Arduino
| LCD | Arduino |
|-----|---------|
| GND | GND |
| VCC | 5V |
| SDA | A4 |
| SCL | A5 |

### HC-SR04 → Arduino
| HC-SR04 | Arduino |
|--------|---------|
| VCC | 5V |
| GND | GND |
| TRIG | 7 |
| ECHO | 6 |

### Buzzer → Arduino
| Buzzer | Arduino |
|--------|---------|
| Sinal | 8 |
| GND | GND |

## ▶️ Como Executar no Wokwi
1. Acesse o link do projeto.  
2. Inicie a simulação.  
3. Ajuste a distância do sensor.  
4. Observe as mensagens e alerta sonoro.  

## 🚀 Possíveis Melhorias
- Registro de ponto com EEPROM  
- Relógio RTC  
- Integração com ESP32  
- Interface com botões  
