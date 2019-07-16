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


// Bounce.pde
// -*- mode: C++ -*-
//
// Make a single stepper bounce from one limit to another
//
// Copyright (C) 2012 Mike McCauley
// $Id: Random.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper(1,X_STEP,X_DIR);//initialise accelstepper for a two wire board, pin 1 step, pin 0 dir

void setup()
{  
  pinMode(XYE_EN,OUTPUT); // Enable
  digitalWrite(XYE_EN,LOW); // Set Enable low
  // Change these to suit your stepper if you want
  stepper.setMaxSpeed(100);
  stepper.setAcceleration(20);
  stepper.moveTo(500);
}

void loop()
{
    // If at the end of travel go to the other end
    if (stepper.distanceToGo() == 0)
      stepper.moveTo(-stepper.currentPosition());

    stepper.run();
}
