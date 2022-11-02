#include <Arduino.h>
#include <Adafruit_MS_PWMServoDriver.h>
#include <Adafruit_MotorShield.h>
#include <SPI.h>
#include "mapping.h"
#include "functions.h"

TRUE_DIRECTION front;
TRUE_DIRECTION left;
TRUE_DIRECTION right;
TRUE_DIRECTION back;

void setup() {
  //inilialize encoder pins - all input pins
  pinMode(DT_FL_EN_C1, INPUT);
  pinMode(DT_FL_EN_C2, INPUT);
  pinMode(DT_FR_EN_C1, INPUT);
  pinMode(DT_FR_EN_C2, INPUT);
  pinMode(DT_BL_EN_C1, INPUT);
  pinMode(DT_BL_EN_C2, INPUT);
  pinMode(DT_BR_EN_C1, INPUT);
  pinMode(DT_BR_EN_C2, INPUT);

  //initialize ultrasonic pins - tring pins output, echo pin input
  pinMode(US_NORTH_TRIG, OUTPUT);
  pinMode(US_NORTH_ECHO, INPUT);
  pinMode(US_EAST_TRIG, OUTPUT);
  pinMode(US_EAST_ECHO, INPUT);
  pinMode(US_WEST_TRIG, OUTPUT);
  pinMode(US_WEST_ECHO, INPUT);
  pinMode(US_SOUTH_TRIG, OUTPUT);
  pinMode(US_SOUTH_ECHO, INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  driveMotor(DT_FL, 1, 100);

}

//sets the 
void setReferenceDirection(REF_DIRECTION direction){
  if(direction == F){
    front = NORTH;
    left = WEST;
    right = EAST;
    back = SOUTH;
  } else if (direction == B){
    front = SOUTH;
    left = EAST;
    right = WEST;
    back = NORTH;
  } else if (direction == L){
    front = WEST; 
    left = NORTH;
    right = SOUTH;
    back = EAST;
  } else if (direction == R){
    front = EAST;
    right = SOUTH;
    left = NORTH;
    back = WEST;
  }

}