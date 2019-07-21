#define pitch 0
#define yaw 1
#define roll 2
#include <AccelStepper.h>

//incoming data
float attitude[3];
float flyTo[3];
float rate[3];
float prevAttitude[3];

//control array(s)
long steps[3];//array of stepper steps. should be the end all be all of stepper command
//all pathfinding and algorithms happen before this point




// Define steppers
AccelStepper X(1,15,21);
AccelStepper Y(1,22,23);
AccelStepper E(1,1,0);
void setup() {
    portMode(3,OUTPUT); // Enable

  enableMotors();
  X.setMaxSpeed(500);
  X.setAcceleration(200);
  Y.setMaxSpeed(500);
  Y.setAcceleration(200);
  E.setMaxSpeed(500);
  E.setAcceleration(200);
  
  X.moveTo(400);
  Y.moveTo(400);
  E.moveTo(400);
}

void loop() {
  if (X.distanceToGo() == 0)X.moveTo(-X.currentPosition());
  if (Y.distanceToGo() == 0)Y.moveTo(-Y.currentPosition());
  if (E.distanceToGo() == 0)E.moveTo(-E.currentPosition());
  X.run();
  Y.run();
  E.run();
  
}
void enableMotors(){
  //we must turn PD6 low. 2^6=64. and with 191
  portWrite(3, (portRead(3) & 191));  
}
void disableMotors(){
  //we must turn PD6 high. 2^6=64. or with 64
  portWrite(3, (portRead(3) | 64));}
