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
    //define the trigger and echo pins based on the true direction
    if(direction == NORTH){
        trigger = US_NORTH_TRIG;
        echo = US_NORTH_ECHO;
    } else if(direction == SOUTH){
        trigger = US_SOUTH_TRIG;
        echo = US_SOUTH_ECHO;
    } else if(direction == EAST){
        trigger = US_EAST_TRIG;
        echo = US_EAST_ECHO;
    } else {
        trigger = US_WEST_TRIG;
        echo = US_WEST_ECHO;
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
    distance = distance/58.0;

    return distance;  
}