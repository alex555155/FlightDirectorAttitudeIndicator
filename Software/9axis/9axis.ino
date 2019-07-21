#define pitch 0
#define yaw 1
#define roll 2

#include <AccelStepper.h>

//incoming data
float attitude[3];
float flyTo[3];
float rate[3];
float prevAttitude[3];

//control array(s). these should be fast, and the final say. positioning for main loop

long steps[3];//array of stepper steps. should be the end all be all of stepper command. all pathfinding and algorithms happen before this point
uint16_t flyTo_position[3];//servo positions
uint16_t rate_position[3];//servo positions

//Servo Calibration Arrays
uint16_t flyTo_lo[3];uint16_t flyTo_middle[3];uint16_t flyTo_hi[3];
uint16_t rate_lo[3];uint16_t rate_middle[3];uint16_t rate_hi[3];




// Define steppers
AccelStepper pitchMot(1,15,21);
AccelStepper yawMot(1,22,23);
AccelStepper rollMot(1,1,0);
void setup() {
  //Stepper inits VvvvvvV
  portMode(3,OUTPUT);
  pitchMot.setMaxSpeed(500);
  pitchMot.setAcceleration(200);
  yawMot.setMaxSpeed(500);
  yawMot.setAcceleration(200);
  rollMot.setMaxSpeed(500);
  rollMot.setAcceleration(200);
  
}

void loop() {
  
 
  
}
void enableMotors(){
  //we must turn PD6 low. 2^6=64. and with 191
  portWrite(3, (portRead(3) & 191));  
}
void disableMotors(){
  //we must turn PD6 high. 2^6=64. or with 64
  portWrite(3, (portRead(3) | 64));}
void
