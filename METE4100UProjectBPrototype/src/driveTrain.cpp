//holds all moement systems
#include <Arduino.h>
#include <Adafruit_MS_PWMServoDriver.h>
#include <Adafruit_MotorShield.h>
#include <SPI.h>
#include "mapping.h"
#include "functions.h"

int encoderFL;
int encoderFR;
int encoderBL;
int encoderBR;

Adafruit_MotorShield drivetrain = Adafruit_MotorShield();

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

void driveForward(TRUE_DIRECTION direction, double speed){
  
  //Driving  
  if (direction == NORTH){ //Drive all wheels forwards
    drivetrain.getMotor(DT_FL)->run(DT_FL_FW);
    drivetrain.getMotor(DT_FR)->run(DT_FR_FW);
    drivetrain.getMotor(DT_BL)->run(DT_BL_FW);
    drivetrain.getMotor(DT_BR)->run(DT_BR_FW);
  } else if (direction == SOUTH){ //Drive all wheels backwards
    drivetrain.getMotor(DT_FL)->run(DT_FL_BW);
    drivetrain.getMotor(DT_FR)->run(DT_FR_BW);
    drivetrain.getMotor(DT_BL)->run(DT_BL_BW);
    drivetrain.getMotor(DT_BR)->run(DT_BR_BW);
  } else if (direction == EAST){ //Drive towards centre for right and away of centre for left
    drivetrain.getMotor(DT_FL)->run(DT_FL_FW);
    drivetrain.getMotor(DT_FR)->run(DT_FR_BW);
    drivetrain.getMotor(DT_BL)->run(DT_BL_BW);
    drivetrain.getMotor(DT_BR)->run(DT_BR_FW);
  } else if (direction == WEST){ //Drive towards centre for left and away of centre for right
    drivetrain.getMotor(DT_FL)->run(DT_FL_BW);
    drivetrain.getMotor(DT_FR)->run(DT_FR_FW);
    drivetrain.getMotor(DT_BL)->run(DT_BL_FW);
    drivetrain.getMotor(DT_BR)->run(DT_BR_BW);
  }

  //set drivetrain speeds
  drivetrain.getMotor(DT_FL)->setSpeedFine(speed);
  drivetrain.getMotor(DT_FR)->setSpeedFine(speed);
  drivetrain.getMotor(DT_BL)->setSpeedFine(speed);
  drivetrain.getMotor(DT_BR)->setSpeedFine(speed);
}

void driveMotor(int motor, int direction, int speed){
  if(direction = 1){
    drivetrain.getMotor(motor)->run(FORWARD);
  }else{
    drivetrain.getMotor(motor)->run(FORWARD);
  }

  drivetrain.getMotor(motor)->setSpeed(speed);
}