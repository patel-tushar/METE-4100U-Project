#include <Arduino.h>
#include "mapping.h"
#include "ultrasonic.h"
#include "functions.h"
#include <Ultrasonic.h>
#include <MPU6050.h>
#include <Wire.h>

//initialize gyro object
MPU6050 gyroscope;
vector_t gyro;

//current used trigger and echo pins
int trigger;
int echo;

//reads the value of an ultrasonic sensor
//returns the distance detected from the sensor in cm
//"direction" is the direction of 
float ultrasonicRead(TRUE_DIRECTION direction){
    double slope;
    double constant;
    
    //define the trigger and echo pins based on the true direction as well as sensor linear interpolation
    if(direction == NORTH){
        trigger = US_NORTH_TRIG;
        echo = US_NORTH_ECHO;
        slope = 0.0179;
        constant = -1.9758;
    } else if(direction == SOUTH){
        trigger = US_SOUTH_TRIG;
        echo = US_SOUTH_ECHO;
        slope = 1;
        constant = 0;
    } else if(direction == EAST){
        trigger = US_EAST_TRIG;
        echo = US_EAST_ECHO;
        slope = 0.0152;
        constant = 2.3894;
    } else {
        trigger = US_WEST_TRIG;
        echo = US_WEST_ECHO;
        slope = 1;
        constant = 0;
    }

    //send wave out from trigger pin
    digitalWrite(trigger, LOW);       
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    //retrieve data from echo pin
    float distance = pulseIn(echo, HIGH);

    //function for translating the pulse value to the distance in cm
    distance = (distance*slope) + constant;

    return distance;  
}

//gyroscope code

//used to initialize gyro
void initializeGyro(){
    gyroscope.begin();

    if(!gyroscope.available())
    {
        Serial.print("Unable to connect to MPU!");
        while(1);
    }

    // set the scaling registers
    gyroscope.setAccConfig(MPU6050_ACC_FULL_SCALE_2_G);
    gyroscope.setGyroConfig(MPU6050_GYRO_FULL_SCALE_500_DPS);

    // run the self calibration function, must not move the MPU during this function call!
    gyroscope.calibrate();
}

//return the X angle for the gyroscope
double gyroReadX(){
    gyroscope.update();
    gyro = gyroscope.getGyro();
    return gyro.x;
}

//return the Y angle for the gyroscope
double gyroReadY(){
    gyroscope.update();
    gyro = gyroscope.getGyro();
    return gyro.y;
}

//return the Z angle for the gyroscope
double gyroReadZ(){
    gyroscope.update();
    gyro = gyroscope.getGyro();
    return gyro.z;
}