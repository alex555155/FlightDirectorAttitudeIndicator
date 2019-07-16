void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(PD7,OUTPUT);
pinMode(PA4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("LO");
digitalWrite(PD7,LOW);
digitalWrite(PA4,LOW);
delay(1000);
  Serial.println("HI");

digitalWrite(PD7,HIGH);
digitalWrite(PA4,HIGH);
delay(1000);
}
