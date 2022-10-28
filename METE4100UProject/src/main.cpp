#include <Arduino.h>
#include "main.h"
#include <Adafruit_MotorShield.h>
#include <Adafruit_MS_PWMServoDriver.h>
#include <SPI.h>

//declare encoder counters
int encoderFL;
int encoderFR;
int encoderBL;
int encoderBR;


Adafruit_MotorShield drivetrain = Adafruit_MotorShield();

void driveForward(TRUE_DIRECTION direction, double speed);
void drive(REF_DIRECTION direction, double speed, double distance);
void rotate(ROTATIONAL_DIRECTION direction, int time, int speed);
//double irRead(REF_DIRECTION sensor);
void encoderEventFL();
void encoderEventFR();
void encoderEventBL();
void encoderEventBR();

void setup() {
  // put your setup code here, to run once:
  
  //set up analog resolution
  //analogReadResolution(12);
  
  // Serial.begin(9600);
  // while (! Serial) {Serial.println("sucker");}
  // Serial.println("Speed 0 to 255");

  if (!drivetrain.begin(1600, &Wire1)) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  
  pinMode(IR_L_READ, INPUT);
  pinMode(IR_R_READ, INPUT);
  pinMode(IR_F_READ, INPUT);

  delay(5000);

  //~18cm left
  driveForward(WEST,2000);
  delay(2000);
  driveForward(NORTH,0);

  delay(1000);

  //~54cm fw

  driveForward(NORTH,2000);
  delay(2000);
  driveForward(NORTH,0);
  
  //rotate(CLOCKWISE,75,2000);
  delay(75);

  driveForward(NORTH,2000);
  delay(2000);
  driveForward(NORTH,0);

  //rotate(CLOCKWISE,75,2000);
  delay(75);

  driveForward(NORTH,2000);
  delay(2000);
  driveForward(NORTH,0);
  
  delay(1000);

  //~18 right

  driveForward(EAST,2000);
  delay(2000);
  driveForward(NORTH,0);

  delay(1000);
  //~18cm forward

  driveForward(NORTH,2000);
  delay(2000);
  driveForward(NORTH,0);

  delay(1000);

  //18 cm left
  driveForward(WEST,2000);
  delay(2000);
  driveForward(NORTH,0);

  delay(1000);

  //36 cm fw

  driveForward(NORTH,2000);
  delay(2000);
  driveForward(NORTH,0);

  //rotate(CLOCKWISE,75,2000);
  delay(75);

  driveForward(NORTH,2000);
  delay(2000);
  driveForward(NORTH,0);

  delay(1000);

  //72cm to the right

  driveForward(EAST,2000);
  delay(9000);
  driveForward(NORTH, 0);

  delay(1000);

  //drive back a lot

  driveForward(SOUTH,2000);
  delay(15000);
  driveForward(NORTH, 0);

  delay(1000);


  //drive left a lot

  driveForward(WEST,2000);
  delay(10000);
  driveForward(NORTH, 0);

  delay(1000); 


  driveForward(NORTH,2000);
  delay(2000);
  driveForward(NORTH,0);
  delay(1000);
  driveForward(EAST,2000);
  delay(8000);
  driveForward(NORTH,0);
  delay(1000);
  driveForward(NORTH,2000);
  delay(10000);
  driveForward(NORTH,0);
  delay(1000);
  driveForward(WEST,2000);
  delay(2000);
  driveForward(NORTH,0);
  delay(1000);
  driveForward(SOUTH,2000);
  delay(4000);
  driveForward(NORTH,0);
  delay(1000);
  driveForward(WEST,2000);
  delay(4000);
  driveForward(NORTH,0);
  delay(1000);
  driveForward(SOUTH,2000);
  delay(4000);
  driveForward(NORTH,0);
  delay(1000);

  // rotate(CLOCKWISE, 900, 3000);

}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(irRead(L));
  // delay(1500);
}


//direction is direction of travel in the catesian space
//speed is a percentage of 4095 for the motor input
//distance is the distance required to travel
void drive(REF_DIRECTION direction, double speed, double distance){

  //determine speed value
  double speedValue = speed*4095;

  //define the driving setup for current direction of travel

  //initiate variable
  TRUE_DIRECTION fw;
  TRUE_DIRECTION bw;
  TRUE_DIRECTION left;
  TRUE_DIRECTION right;

  //define true directions based on reference  direction
  if (direction == F){
    fw = NORTH;
    bw = SOUTH;
    left = WEST;
    right = EAST;
  } else if (direction == R) {
    fw = EAST;
    bw = WEST;
    left = NORTH;
    right = SOUTH;
  } else if (direction == B) {
    fw = SOUTH;
    bw = NORTH;
    left = WEST;
    right = EAST;
  } else if (direction == L) {
    fw = WEST;
    bw = EAST;
    left = SOUTH;
    right = NORTH;
  }
  
  

}


//sets drive motors 
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
  // drivetrain.getMotor(DT_FL)->setSpeedFine(speed*DT_FL_SC);
  // drivetrain.getMotor(DT_FR)->setSpeedFine(speed*DT_FR_SC);
  // drivetrain.getMotor(DT_BL)->setSpeedFine(speed*DT_BL_SC);
  // drivetrain.getMotor(DT_BR)->setSpeedFine(speed*DT_BR_SC);

  drivetrain.getMotor(DT_FL)->setSpeedFine(speed);
  drivetrain.getMotor(DT_FR)->setSpeedFine(speed);
  drivetrain.getMotor(DT_BL)->setSpeedFine(speed);
  drivetrain.getMotor(DT_BR)->setSpeedFine(speed);

}


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

//rotate the robot a certain number of degrees
//direction is whether to rotate clockwise (right) or counterclockwise (left) from an ariel perspective
//time is the number of milliseconds to turn
void rotate(ROTATIONAL_DIRECTION direction, int time, int speed){
  if(direction == ANTICLOCKWISE){
    drivetrain.getMotor(DT_FL)->run(DT_FL_BW);
    drivetrain.getMotor(DT_FR)->run(DT_FR_FW);
    drivetrain.getMotor(DT_BL)->run(DT_BL_BW);
    drivetrain.getMotor(DT_BR)->run(DT_BR_FW);
  } else {
    drivetrain.getMotor(DT_FL)->run(DT_FL_FW);
    drivetrain.getMotor(DT_FR)->run(DT_FR_BW);
    drivetrain.getMotor(DT_BL)->run(DT_BL_FW);
    drivetrain.getMotor(DT_BR)->run(DT_BR_BW);
  }

  drivetrain.getMotor(DT_FL)->setSpeedFine(speed);
  drivetrain.getMotor(DT_FR)->setSpeedFine(speed);
  drivetrain.getMotor(DT_BL)->setSpeedFine(speed);
  drivetrain.getMotor(DT_BR)->setSpeedFine(speed);

  delay(time);

  drivetrain.getMotor(DT_FL)->setSpeedFine(0);
  drivetrain.getMotor(DT_FR)->setSpeedFine(0);
  drivetrain.getMotor(DT_BL)->setSpeedFine(0);
  drivetrain.getMotor(DT_BR)->setSpeedFine(0);
}

// double irRead(REF_DIRECTION sensor){

//   double distance = 0;

//   if(sensor == F){
//     digitalWrite(IR_F_ENABLE, HIGH);
//     distance = analogRead(IR_F_READ);
//     digitalWrite(IR_F_ENABLE, LOW);
//   } else if (sensor == L){
//     digitalWrite(IR_L_ENABLE, HIGH);
//     distance = analogRead(IR_L_READ);
//     digitalWrite(IR_L_ENABLE, LOW);
//   } else if (sensor == R){
//     digitalWrite(IR_R_ENABLE, HIGH);
//     distance = analogRead(IR_R_READ);
//     digitalWrite(IR_R_ENABLE, LOW);
//   }

//   return distance;
// }