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
