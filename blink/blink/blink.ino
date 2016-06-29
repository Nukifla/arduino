int ledpin1 = 8;
int ledpin2 = 12;
void setup() {
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, HIGH);
  delay(2000);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, LOW);
  delay(2000);
}
