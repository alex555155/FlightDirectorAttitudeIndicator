#define pitch 0
#define yaw 1
#define roll 2
//system states
#define idle 0
#define calibrating 1
#define indicating 2
#include <AccelStepper.h>

//top needle is roll, bottom is yaw

//Hey future self! here is your reminder that modular code is better.
//I should be able to interface this to anything by changing interface code only

/*System State
0 idle: just sitting, not connected to game, but not calibrating either. should disable motors for power and thermal purposes. Should attempt to connect to game 
1 calibrating: runs the calibration routine at startup. involves reading last ball position from nonvolatile memory, then putting on a show. when done, everything at origin, then go idle
2 indicating: Once connected to game, enter this state to actively indicate. if connection is lost go to idle */
uint8_t SystemState =calibrating;//start in calibration routine

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
AccelStepper pitchMot(1,15,21);//X
AccelStepper yawMot(1,22,23);//Y
AccelStepper rollMot(1,1,0);//E
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

void loop() {//update all motors here. we need to keep this main loop short and sweet
 
  
}
void enableMotors(){
  //we must turn PD6 low. 2^6=64. and with 191
  portWrite(3, (portRead(3) & 191));  
}
void disableMotors(){
  //we must turn PD6 high. 2^6=64. or with 64
  portWrite(3, (portRead(3) | 64));}

//Stepper Algorithms
//takes incoming attitude commands and computes appropriate stepper action. reads from float attitude[] and updates long steps[]
//should make use of prevAttitude[], and maybe distanceToGo (from accelstepper), and maybe rates
void pitchAlgo(){
  
}
void yawAlgo(){
  
}
void rollAlgo(){
  
}

//Servo Algorithms
//I dont know if rates will be readily available (simpit doesnt seem to have them, I may end up using KRPC). I may have to compute rates from attitude data.

void flyToAlgo(){//should account for commanded attitude (from game) stored in float attitude[], game commanded flyto in float flyTo[], servo calibration data,
                 //and potentially a live ball position from accelstepper
  
}
void rateAlgo(){//should account for game commanded rates. If game is unable to provide rate data, it must be computed from commanded attitude (current and previous). Remember calib data
  
}

//Super Special and Extra Fancy, Pretty Damn Sexy, Flashy yet still Tasteful "calibration" routine (SSaEFPDSFysTCR)
//Moves all motors in ball, should put the servos in min, max, and middle positions. Move all three steppers at once, 
//then give a show. If possible move to origin based on a last position stored in non volatile memory
void calibrationRoutine(){
  //remember, top needle is roll, bottom is yaw
  //simultaneously Move fly to needles to origin

  //simultaneously move roll (top) to the righthand limit, pitch to bottom limit, and yaw (bottom) to lefthand limit

  //simultaneously move all flyto needles to their opposite limits

  //simultaneously move all flyto needles to origin

  //Time for rate needles
  //simultaneously move all rate needles to origin

  //simultaneously, move roll (top) to right limit, pitch to lower limit, and yaw (bottom) to left limit

  //simultaneously move rate needles to opposite limits

  //bump each needle along incrementally, hitting each scale marker, once at limit, start moving next needle. the idea is to create a clockwise moving wave effect, like a needle contagion

  //simultaneously move rate needles to origin

  //time for ball calib
  //hide flyto needles
  
  //move ball to origin based on position stored in nonvolatile memory

  //pitch 360 degrees

  //yaw 360 degrees

  //roll 360 degrees

  //return flyto needles to origin

  //calib done!
}
