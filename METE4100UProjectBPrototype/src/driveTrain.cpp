//holds all moement systems
#include <Arduino.h>
#include <Adafruit_MS_PWMServoDriver.h>
#include <Adafruit_MotorShield.h>
#include <SPI.h>
#include <Wire.h>
#include "mapping.h"
#include "functions.h"

int encoderFL;
int encoderFR;
int encoderBL;
int encoderBR;

Adafruit_MotorShield drivetrain = Adafruit_MotorShield();

void initializeSheild(){
  //set up analog resolution
  //analogReadResolution(12);
  if (!drivetrain.begin(1600, &Wire)) {   // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
  Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
}

//getters and setters for encoders
int getEncoderFL(){
  return encoderFL;
}

void setEncoderFL(int val){
  encoderFL = val;
}

int getEncoderFR(){
  return encoderFR;
}

void setEncoderFR(int val){
  encoderFR = val;
}

int getEncoderBL(){
  return encoderBL;
}

void setEncoderBL(int val){
  encoderBL = val;
}

int getEncoderBR(){
  return encoderBR;
}

void setEncoderBR(int val){
  encoderBR = val;
}


//encoder events

//front left encoder counter event
void encoderEventFL(){
  if (digitalRead(DT_FL_EN_C1) == HIGH) {
    if (digitalRead(DT_FL_EN_C2) == LOW) {
      encoderFL++;
    } else {
      encoderFL--;
    }
  } else {
    if (digitalRead(DT_FL_EN_C2) == LOW) {
      encoderFL--;
    } else {
      encoderFL++;
    }
  }
}


//front right encoder counter event
void encoderEventFR(){
  if (digitalRead(DT_FR_EN_C1) == HIGH) {
    if (digitalRead(DT_FR_EN_C2) == LOW) {
      encoderFR++;
    } else {
      encoderFR--;
    }
  } else {
    if (digitalRead(DT_FR_EN_C2) == LOW) {
      encoderFR--;
    } else {
      encoderFR++;
    }
  }
}


//back left encoder counter event
void encoderEventBL(){
  if (digitalRead(DT_BL_EN_C1) == HIGH) {
    if (digitalRead(DT_BL_EN_C2) == LOW) {
      encoderBL++;
    } else {
      encoderBL--;
    }
  } else {
    if (digitalRead(DT_BL_EN_C2) == LOW) {
      encoderBL--;
    } else {
      encoderBL++;
    }
  }
}

//back right encoder counter event
void encoderEventBR(){
  if (digitalRead(DT_BR_EN_C1) == HIGH) {
    if (digitalRead(DT_BR_EN_C2) == LOW) {
      encoderBR++;
    } else {
      encoderBR--;
    }
  } else {
    if (digitalRead(DT_BR_EN_C2) == LOW) {
      encoderBR--;
    } else {
      encoderBR++;
    }
  }
}

void drive(TRUE_DIRECTION direction, int speed){
  
  //Driving  
  if (direction == NORTH){ //Drive all wheels forwards
    driveMotor(DT_FL, 2, speed);
    driveMotor(DT_FR, 1, speed);
    driveMotor(DT_BL, 2, speed);
    driveMotor(DT_BR, 1, speed);
  } else if (direction == SOUTH){ //Drive all wheels backwards
    driveMotor(DT_FL, 1, speed);
    driveMotor(DT_FR, 2, speed);
    driveMotor(DT_BL, 1, speed);
    driveMotor(DT_BR, 2, speed);
  } else if (direction == EAST){ //Drive towards centre for right and away of centre for left
    driveMotor(DT_FL, 2, speed);
    driveMotor(DT_FR, 2, speed);
    driveMotor(DT_BL, 1, speed);
    driveMotor(DT_BR, 1, speed);
  } else if (direction == WEST){ //Drive towards centre for left and away of centre for right
    driveMotor(DT_FL, 1, speed);
    driveMotor(DT_FR, 1, speed);
    driveMotor(DT_BL, 2, speed);
    driveMotor(DT_BR, 2, speed);
  }
}

//diagonal strafe based on a north and south direction and an east and west direction
void diagonalStrafe(TRUE_DIRECTION direction1, TRUE_DIRECTION direction2, int speed){
  if(direction1 == NORTH && direction2 == EAST){
    driveMotor(DT_FL, 2, speed);
    driveMotor(DT_BR, 1, speed);
  } else if (direction1 == NORTH && direction2 == WEST){
    driveMotor(DT_FR, 1, speed);
    driveMotor(DT_BL, 2, speed);
  } else if (direction1 == SOUTH && direction2 == EAST){
    driveMotor(DT_FR, 2, speed);
    driveMotor(DT_BL, 1, speed);
  } else if (direction1 == SOUTH && direction2 == WEST){
    driveMotor(DT_FL, 2, speed);
    driveMotor(DT_BR, 1, speed);
  }
}

//rotate the motors in a certain direction

void rotate(int direction, int speed){
  if(direction == 1){
    driveMotor(DT_FL, 2, speed);
    driveMotor(DT_FR, 2, speed);
    driveMotor(DT_BL, 2, speed);
    driveMotor(DT_BR, 2, speed);
  } else {
    driveMotor(DT_FL, 1, speed);
    driveMotor(DT_FR, 1, speed);
    driveMotor(DT_BL, 1, speed);
    driveMotor(DT_BR, 1, speed);
  }
}

//function used to drive a motor
void driveMotor(int motor, int direction, int speed){
  if(direction == 1){
    drivetrain.getMotor(motor)->run(FORWARD);
  }else{
    drivetrain.getMotor(motor)->run(BACKWARD);
  }
  drivetrain.getMotor(motor)->setSpeed(speed);
}

//stop the robot
void stop(){
  drivetrain.getMotor(DT_FL)->setSpeed(0);
  drivetrain.getMotor(DT_FR)->setSpeed(0);
  drivetrain.getMotor(DT_BL)->setSpeed(0);
  drivetrain.getMotor(DT_BR)->setSpeed(0);
}

