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
  //initialize pins
  
}


void loop() {
  // put your main code here, to run repeatedly:
  ultrasonicRead(NORTH);
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