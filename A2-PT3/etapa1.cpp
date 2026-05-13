const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("--- Monitoramento de Temperatura: Etapa 1 ---");
}

void loop() {
  int leitura = analogRead(sensorPin);
  
  float tensao = leitura * (5.0 / 1024.0);
 
  float temperaturaC = tensao * 100.0;
  
  Serial.print("Temperatura: ");
  Serial.print(temperaturaC);
  Serial.println(" C");
  
  delay(1000);
}