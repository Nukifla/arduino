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
void setup() {
  for (byte i = 2; i <= 9; ++i) {
    pinMode(i, OUTPUT); 
  }
}
byte i = 9;
void loop() {
    skrivTal(i);
    delay(1000);
    i = (i == 0)? 9 : i - 1;
}
void skrivTal(byte tal) {
  for (byte i = 0; i < 7 ; ++i) {
    byte mode = numre[tal][i];
    byte pin = i + 2;
    byte vendtMode = (mode == 0)? 1 : 0;
    digitalWrite(pin, vendtMode);
  }
}

