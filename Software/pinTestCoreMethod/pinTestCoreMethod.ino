void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
portMode(3,OUTPUT);
portMode(0,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("LO");
portWrite(3,0);
digitalWrite(0,0);
delay(1000);
  Serial.println("HI");

portWrite(3,128);
portWrite(0,16);
delay(1000);
}
