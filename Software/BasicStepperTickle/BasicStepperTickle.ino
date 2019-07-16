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
//portMode(0,OUTPUT);//Init outputs (ports A thru D... which is all of them)
//portMode(1,OUTPUT);
//portMode(2,OUTPUT);
//portMode(3,OUTPUT);
XYEen(1);//enable steppers
Xdir(0);//Arbitrary (for now), just needs to be asserted
  
}

void loop() {
  // put your main code here, to run repeatedly:
Xstep(0);
delay(50);//delay between steps
Xstep(1);
delay(5);//driver pulse time
}

void Xstep(uint8_t i){//PD7
  if(i)
    {
    portWrite(3,(portRead(3) | 128));
    }
  else
  {
    portWrite(3,(portRead(3) & 127));
  }
}
void XYEen(uint8_t i){//PD6
  if(i)
    {
    portWrite(3,(portRead(3) | 64));
    }
  else
  {
    portWrite(3,(portRead(3) & 191));
  }
}
void Xdir(uint8_t i){//PC5
  if(i)
    {
    portWrite(2,(portRead(2) | 32));
    }
  else
  {
    portWrite(2,(portRead(2) & 223));
  }
}
