//to call functions related to the system
#include <Arduino.h>
#include "mapping.h"
#include <Adafruit_MS_PWMServoDriver.h>
#include <Adafruit_MotorShield.h>

//sensor file code commands
float ultrasonicRead(TRUE_DIRECTION);

//drivetrain functions
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

void driveForward(TRUE_DIRECTION, double);

//main functions
void setReferenceDirection(REF_DIRECTION);