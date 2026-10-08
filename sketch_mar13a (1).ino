void setup() {
  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
}

void loop() {
  int A = random(999);
  int B = random(999);
  int C = random(999);
  int D = random(999);
  delay(10000);

  if (D > A && D > B && D > C) {
    // D is highest: blink all LEDs 3 times then exit
    for (int i = 0; i < 3; i++) {
      digitalWrite(D3, HIGH);
      digitalWrite(D5, HIGH);
      digitalWrite(D6, HIGH);
      delay(500);
      digitalWrite(D3, LOW);
      digitalWrite(D5, LOW);
      digitalWrite(D6, LOW);
      delay(500);
    }
  } else {
    digitalWrite(D3, (A > B || A > C) ? HIGH : LOW);
    digitalWrite(D5, (C > A || A < B) ? HIGH : LOW);
    digitalWrite(D6, (B > C || B > A || C < A) ? HIGH : LOW);
  }
}
