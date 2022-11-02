#include <Arduino.h>
#include "mapping.h"
#include "ultrasonic.h"
#include "functions.h"
#include <Ultrasonic.h>

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