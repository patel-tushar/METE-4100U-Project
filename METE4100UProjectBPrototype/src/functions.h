//to call functions related to the system
#include <Arduino.h>
#include "mapping.h"
#include <Adafruit_MS_PWMServoDriver.h>
#include <Adafruit_MotorShield.h>

//sensor file code commands
float ultrasonicRead(TRUE_DIRECTION);

//drivetrain functions
void initializeSheild();
int getEncoderFL();
void setEncoderFL(int);
int getEncoderFR();
void setEncoderFR(int);
int getEncoderBL();
void setEncoderBL(int);
int getEncoderBR();
void setEncoderBR(int);

void encoderEventFL();
void encoderEventFR();
void encoderEventBL();
void encoderEventBR();

void drive(TRUE_DIRECTION, int);
void diagonalStrafe(TRUE_DIRECTION, TRUE_DIRECTION, int);
void driveMotor(int, int, int);
void stop();

//main functions
void setReferenceDirection(REF_DIRECTION);
void getAllDistances();
boolean checkPointCheck();
void driveTo(TRUE_DIRECTION, double);