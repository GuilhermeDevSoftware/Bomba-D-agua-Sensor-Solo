#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

int pinoUmidade = A0;

int ledVermelho = 8;
int ledAmarelo = 9;
int ledBomba = 10; // LED azul simulando bomba

int valorSensor = 0;
int umidadePorcentagem = 0;

// Calibracao que voce mediu
int valorSeco = 1023;
int valorMolhado = 318;

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);

  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledBomba, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Sensor Umidade");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
}

void loop() {
  valorSensor = analogRead(pinoUmidade);

  umidadePorcentagem = map(valorSensor, valorSeco, valorMolhado, 0, 100);
  umidadePorcentagem = constrain(umidadePorcentagem, 0, 100);

  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledBomba, LOW);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Umidade: ");
  lcd.print(umidadePorcentagem);
  lcd.print("%");

  lcd.setCursor(0, 1);

  if (umidadePorcentagem < 30) {
    lcd.print("Seco Bomba ON");

    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledBomba, HIGH);
  } 
  else if (umidadePorcentagem < 70) {
    lcd.print("Solo medio");

    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledBomba, LOW);
  } 
  else {
    lcd.print("Solo umido");

    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledBomba, LOW);
  }

  Serial.print("Valor bruto: ");
  Serial.print(valorSensor);
  Serial.print(" | Umidade: ");
  Serial.print(umidadePorcentagem);
  Serial.println("%");

  delay(1000);
}