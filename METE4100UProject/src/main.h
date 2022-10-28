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

#define DT_FL_EN_C1 31
#define DT_FL_EN_C2 30

#define DT_FR_EN_C1 23
#define DT_FR_EN_C2 22

#define DT_BL_EN_C1 27
#define DT_BL_EN_C2 26

#define DT_BR_EN_C1 35
#define DT_BR_EN_C2 34


//define pins for GYRO
#define GYRO_SCL A11
#define GYRO_SDA A10
#define GYRO_INT 50


//define pins for IR
//Enable output voltage
//read is an analog input

#define IR_F_ENABLE 51
#define IR_F_READ A9

#define IR_L_ENABLE 49
#define IR_L_READ A10

#define IR_R_ENABLE 53
#define IR_R_READ A8


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