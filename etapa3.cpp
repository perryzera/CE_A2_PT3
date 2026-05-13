const int sensorPin = A0;
const int leds[] = {13, 12, 11};

enum Status { FRIO, IDEAL, QUENTE };
Status statusAtual = IDEAL;
Status statusAnterior = IDEAL;

void setup() {
  Serial.begin(9600);
  for(int i=0; i<3; i++) pinMode(leds[i], OUTPUT);
  Serial.println("Sistema de Monitoramento Estável Iniciado");
}

void loop() {
  int leitura = analogRead(sensorPin);
  float temperaturaC = (leitura * 5.0 / 1024.0) * 100.0;

  if (temperaturaC < 19.5) statusAtual = FRIO;
  else if (temperaturaC >= 20.0 && temperaturaC <= 30.0) statusAtual = IDEAL;
  else if (temperaturaC > 30.5) statusAtual = QUENTE;

  if (statusAtual != statusAnterior) {
    digitalWrite(leds[0], statusAtual == FRIO);
    digitalWrite(leds[1], statusAtual == IDEAL);
    digitalWrite(leds[2], statusAtual == QUENTE);

    Serial.print("EVENTO: Mudança de Status para ");
    if (statusAtual == FRIO) Serial.println("FRIO");
    else if (statusAtual == IDEAL) Serial.println("IDEAL");
    else Serial.println("ALERTA DE CALOR");
    
    statusAnterior = statusAtual;
  }

  delay(500);
}
