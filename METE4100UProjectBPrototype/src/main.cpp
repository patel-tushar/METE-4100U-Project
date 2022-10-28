#include <Arduino.h>
#include <Adafruit_MS_PWMServoDriver.h>
#include <Adafruit_MotorShield.h>
#include <SPI.h>
#include "mapping.h"
#include "functions.h"

void setup() {
  //initialize pins
  
}


void loop() {
  // put your main code here, to run repeatedly:
  ultrasonicRead(NORTH);
}