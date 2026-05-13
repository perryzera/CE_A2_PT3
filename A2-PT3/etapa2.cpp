const int sensorPin = A0;
const int ledAzul = 13;
const int ledVerde = 12;
const int ledVermelho = 11;

void setup() {
  Serial.begin(9600);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  int leitura = analogRead(sensorPin);
  float temperaturaC = (leitura * 5.0 / 1024.0) * 100.0;

  digitalWrite(ledAzul, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);

  if (temperaturaC < 20.0) {
    digitalWrite(ledAzul, HIGH);
    Serial.print("[FRIO] ");
  } else if (temperaturaC >= 20.0 && temperaturaC <= 30.0) {
    digitalWrite(ledVerde, HIGH);
    Serial.print("[IDEAL] ");
  } else {
    digitalWrite(ledVermelho, HIGH);
    Serial.print("[QUENTE] ");
  }

  Serial.print("Temp: ");
  Serial.print(temperaturaC);
  Serial.println(" C");

  delay(1000);
}