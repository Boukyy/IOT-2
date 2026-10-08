const int ldrPin = A0;
const int ledD3 = 3;
const int ledD5 = 5;
const int ledD6 = 6;


bool weinigLicht(int waarde) {
  return waarde < 500;
}

void lichtControle(int waarde) {
  if (waarde >= 500 && waarde < 700) {
    digitalWrite(ledD5, HIGH);
    digitalWrite(ledD6, LOW);
  } else if (waarde >= 700) {
    digitalWrite(ledD5, LOW);
    digitalWrite(ledD6, HIGH);
  } else {
    digitalWrite(ledD5, LOW);
    digitalWrite(ledD6, LOW);
  }
}

void setup() {
  pinMode(ledD3, OUTPUT);
  pinMode(ledD5, OUTPUT);
  pinMode(ledD6, OUTPUT);
}

void loop() {
  int ldr_value = analogRead(ldrPin);

  if (weinigLicht(ldr_value)) {
    digitalWrite(ledD3, HIGH);
  } else {
    digitalWrite(ledD3, LOW);
  }

  lichtControle(ldr_value);

  delay(200);
}
