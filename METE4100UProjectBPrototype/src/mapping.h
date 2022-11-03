#pragma once
#include <Arduino.h>


//define motors on the arduino sheild
#define DT_FL 2
#define DT_FR 4
#define DT_BL 1
#define DT_BR 3


//drivetrain constants made for SFPIDS
//found by determining slowest motor and finding the speed ratio between it and other motors
#define DT_FL_SC 1
#define DT_FR_SC 0.89876
#define DT_BL_SC 0.61573
#define DT_BR_SC 0.43335


//define motor directions of rotation
//FW = FORWARD, BW = BACKWARD

#define DT_FL_FW FORWARD
#define DT_FL_BW BACKWARD

#define DT_FR_FW BACKWARD
#define DT_FR_BW FORWARD

#define DT_BL_FW BACKWARD
#define DT_BL_BW FORWARD

#define DT_BR_FW FORWARD
#define DT_BR_BW BACKWARD


//define encoder pins
//C1 = green pin, C2 = yellow pin

#define DT_FL_EN_C1 46//31
#define DT_FL_EN_C2 47//30

#define DT_FR_EN_C1 52//23
#define DT_FR_EN_C2 53//22

#define DT_BL_EN_C1 42//27
#define DT_BL_EN_C2 43//26

#define DT_BR_EN_C1 36//35
#define DT_BR_EN_C2 37//34


//define pins for GYRO
#define GYRO_SCL A11
#define GYRO_SDA A10
#define GYRO_INT 50


//define pins for ultrasonic pinmode
//Trig pin is an output pin that shoots out a signal
//Echo is the pin that recieves the value
#define US_NORTH_TRIG 23
#define US_NORTH_ECHO 22

#define US_EAST_TRIG 31
#define US_EAST_ECHO 30

#define US_WEST_TRIG 35//8
#define US_WEST_ECHO 34//9

#define US_SOUTH_TRIG 27//10
#define US_SOUTH_ECHO 26//11


//define cartesian compass (true) directions
enum TRUE_DIRECTION { 
    NORTH, SOUTH, EAST, WEST 
};


//define reference directions
enum REF_DIRECTION {
    F, B, L, R
};


//define rotational directions
enum ROTATIONAL_DIRECTION {
    CLOCKWISE, ANTICLOCKWISE
};


