#define XYE_EN  PD6
#define Z_EN    PA5
#define X_STEP  PD7
#define X_DIR   PC5
#define Y_STEP  PC6
#define Y_DIR   PC7
#define Z_STEP  PB3
#define Z_DIR   PB2
#define E_STEP  PB1
#define E_DIR   PB0
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(XYE_EN,OUTPUT);
//pinMode(PA4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("LO");
digitalWrite(XYE_EN,LOW);
//digitalWrite(PA4,LOW);
delay(1000);
  Serial.println("HI");

digitalWrite(XYE_EN,HIGH);
//digitalWrite(PA4,HIGH);
delay(1000);
}
