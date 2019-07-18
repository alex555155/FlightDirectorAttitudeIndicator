#define XYE_EN  PD6
#define X_STEP  PD7
#define X_DIR   PC5
#define PORTa 0
#define PORTb 1
#define PORTc 2
#define PORTd 3

#define stepperDwellTime 1//in milliseconds

uint8_t IO[3];//controls the IO

void enableXYE(){
  //we must turn PD6 low. 2^6=64. and with 191
  IO[PORTd] &= 191;
  refreshPortD();  
  
}
void disableXYE(){
  //we must turn PD6 high. 2^6=64. or with 64
  IO[PORTd] |= 64;
  refreshPortD();  
}
void setXdir(uint8_t dir){
  //X dir is pin PC5. 2^5=32
  if(dir){//if dir positive, assert high
    IO[PORTc]|=32;    
  }
  else{
    IO[PORTc]&=223;
  }
  refreshPortC();
}
void singleStepX(){
  //X step is pin PD7. 2^7=128
  //The Plan: turn on, wait, turn off
  IO[PORTd] |= 128;//Turn ON
  refreshPortD();
  delay(stepperDwellTime);//wait
  IO[PORTd] &= 127;//Turn Off
  refreshPortD();  
}
void stepX(long n, uint8_t dly){
  while(n>0){
    singleStepX();
    delay(dly);
    n--;
  }
}
uint8_t refreshPortA(){//writes to port from IO array
  uint8_t val = IO[PORTa];
  portWrite(PORTa,val);
  return val;
}
uint8_t refreshPortB(){//writes to port from IO array
  uint8_t val = IO[PORTb];
  portWrite(PORTb,val);
  return val;
}
uint8_t refreshPortC(){//writes to port from IO array
  uint8_t val = IO[PORTc];
  portWrite(PORTc,val);
  return val;
}
uint8_t refreshPortD(){//writes to port from IO array
  uint8_t val = IO[PORTd];
  portWrite(PORTd,val);
  return val;
}
void refreshAll(){
  refreshPortA();
  refreshPortB();
  refreshPortC();
  refreshPortD();  
}
void setup() {
  //Initialize Ports C and D
  portMode(PORTc,OUTPUT);
  portMode(PORTd,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  enableXYE();
  stepX(100,10);
  disableXYE();
  delay(1000);


}
