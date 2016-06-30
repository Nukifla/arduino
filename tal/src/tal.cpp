#include <Arduino.h>

byte hylpin = 13;
byte knappin = 10;
byte numre[10][7] = {
  {0,1,1,1,1,1,1}, //0
  {0,0,0,1,0,0,1}, //1
  {1,0,1,1,1,1,0}, //2
  {1,0,1,1,0,1,1}, //3
  {1,1,0,1,0,0,1}, //4
  {1,1,1,0,0,1,1}, //5
  {1,1,1,0,1,1,1}, //6
  {0,0,1,1,0,0,1}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}  //9
};
byte talSidst = 10;
void skrivTal(byte tal) {
  for (byte i = 0; i < 7 ; ++i) {
    byte mode = numre[tal][i];
    byte pin = i + 2;
    byte vendtMode = (mode == 0)? 1 : 0;
    digitalWrite(pin, vendtMode);
  }
  talSidst = tal;
}

unsigned long nu = millis();
unsigned long skiftede = nu;
void telned() {
  // gæm tid
  //tjek om tiden er gået
  if (talSidst == 0) {
    digitalWrite(hylpin, HIGH);
    delay(100);
    digitalWrite(hylpin, LOW);
    delay(100);
  }
  else  if((nu - skiftede) >= 1000) {
    skrivTal(talSidst - 1);
    skiftede = nu;
  }
  // vis ja skriv tal
}
void setup() {
  for (byte i = 2; i <= 9; ++i) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
  pinMode(hylpin, OUTPUT);
  pinMode(knappin, INPUT);
}
bool on = true;
void loop() {
  nu = millis();
  if (on) telned();
  if(digitalRead(knappin)) {
    talSidst = 10;
    on = !on;
  }
}
