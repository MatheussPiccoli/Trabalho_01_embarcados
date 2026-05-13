const int TRIG = 3, ECHO = 2, buzzer = 7;
const int POT = A0;
unsigned int intervalo, distancia;
int limiar;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  limiar = map(analogRead(POT), 0, 1023, 20, 150);

  distancia = sensor_morcego(TRIG, ECHO);

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm | Limiar: ");
  Serial.println(limiar);

  if (distancia <= 10) {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    tone(buzzer, 1750);
  }
  else if (distancia > limiar) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    noTone(buzzer);
  }
  else {
    int faixa = limiar / 5;

    if (distancia <= faixa * 1) {
      digitalWrite(13, LOW); digitalWrite(12, HIGH); digitalWrite(11, HIGH);
      digitalWrite(10, HIGH); digitalWrite(9, HIGH); digitalWrite(8, HIGH);
      intervalo = 100;
    }
    else if (distancia <= faixa * 2) {
      digitalWrite(13, LOW); digitalWrite(12, LOW); digitalWrite(11, HIGH);
      digitalWrite(10, HIGH); digitalWrite(9, HIGH); digitalWrite(8, HIGH);
      intervalo = 150;
    }
    else if (distancia <= faixa * 3) {
      digitalWrite(13, LOW); digitalWrite(12, LOW); digitalWrite(11, LOW);
      digitalWrite(10, HIGH); digitalWrite(9, HIGH); digitalWrite(8, HIGH);
      intervalo = 200;
    }
    else if (distancia <= faixa * 4) {
      digitalWrite(13, LOW); digitalWrite(12, LOW); digitalWrite(11, LOW);
      digitalWrite(10, LOW); digitalWrite(9, HIGH); digitalWrite(8, HIGH);
      intervalo = 250;
    }
    else {
      digitalWrite(13, LOW); digitalWrite(12, LOW); digitalWrite(11, LOW);
      digitalWrite(10, LOW); digitalWrite(9, LOW); digitalWrite(8, HIGH);
      intervalo = 300;
    }
    tone(buzzer, 1750);
    delay(intervalo);
    noTone(buzzer);
    delay(intervalo);
  }
}

int sensor_morcego(int pinotrig, int pinoecho) {
  digitalWrite(pinotrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig, LOW);
  return pulseIn(pinoecho, HIGH) / 58;
}