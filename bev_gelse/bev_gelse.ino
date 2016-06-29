int inputpin = 2;
bool bevagelse = false;
void setup() {
  pinMode(inputpin, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  bevagelse = digitalRead(inputpin);
  if (bevagelse) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }

}
