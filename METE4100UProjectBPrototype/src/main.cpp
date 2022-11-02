#include <Arduino.h>
#include <Adafruit_MS_PWMServoDriver.h>
#include <Adafruit_MotorShield.h>
#include <SPI.h>

#include "mapping.h"
#include "functions.h"

//setting variable for current direction of the robot
TRUE_DIRECTION front;
TRUE_DIRECTION left;
TRUE_DIRECTION right;
TRUE_DIRECTION back;

//standard robot drive speed
int standardSpeed = 150;

//current distances
float frontDistance;
float leftDistance;
float rightDistance;
float backDistance;

//checkpoints are points that are intermintently met to see if we have reached a point
boolean checkPointReached; //determines if we have reached our current checkpoint
int checkPointCounter; //keeps track of which check point we are on
int totalCheckPoints; //number of checkpoints to reach

void setup() {
  Serial.begin(9600);
  while (! Serial) {Serial.println("sucker");}
  Serial.println("Speed 0 to 255");
  //initialize the motor sheild
  initializeSheild();
  
  //inilialize encoder pins - all input pins
  pinMode(DT_FL_EN_C1, INPUT);
  pinMode(DT_FL_EN_C2, INPUT);
  pinMode(DT_FR_EN_C1, INPUT);
  pinMode(DT_FR_EN_C2, INPUT);
  pinMode(DT_BL_EN_C1, INPUT);
  pinMode(DT_BL_EN_C2, INPUT);
  pinMode(DT_BR_EN_C1, INPUT);
  pinMode(DT_BR_EN_C2, INPUT);

  //initialize ultrasonic pins - tring pins output, echo pin input
  pinMode(US_NORTH_TRIG, OUTPUT);
  pinMode(US_NORTH_ECHO, INPUT);
  pinMode(US_EAST_TRIG, OUTPUT);
  pinMode(US_EAST_ECHO, INPUT);
  pinMode(US_WEST_TRIG, OUTPUT);
  pinMode(US_WEST_ECHO, INPUT);
  pinMode(US_SOUTH_TRIG, OUTPUT);
  pinMode(US_SOUTH_ECHO, INPUT);
}


void loop() {
  Serial.println(ultrasonicRead(WEST));
  delay(5000);

}

//sets the 
void setReferenceDirection(REF_DIRECTION direction){
  if(direction == F){
    front = NORTH;
    left = WEST;
    right = EAST;
    back = SOUTH;
  } else if (direction == B){
    front = SOUTH;
    left = EAST;
    right = WEST;
    back = NORTH;
  } else if (direction == L){
    front = WEST; 
    left = NORTH;
    right = SOUTH;
    back = EAST;
  } else if (direction == R){
    front = EAST;
    right = SOUTH;
    left = NORTH;
    back = WEST;
  }
}

//reads all distances on the ultrasonic sensors
void getAllDistances(){
  frontDistance = ultrasonicRead(front);
  leftDistance = ultrasonicRead(left);
  rightDistance = ultrasonicRead(right);
  backDistance = ultrasonicRead(back);
}



//determines if we have reached our current checkpoint
//also inurements the checkpoint counter
boolean checkPointCheck(){
  if(checkPointCounter == 1){
    if(frontDistance <= 6 && frontDistance >= 3){
      if(leftDistance <= 7  && frontDistance >= 2){
        if(rightDistance <= 8 && leftDistance >= 2){
          if(backDistance <= 3 && backDistance >= 2){
            checkPointCounter++;
            return true;
          }
        }
      }
    }
  } else if(checkPointCounter == 2){
    if(frontDistance <= 6 && frontDistance >= 3){
      if(leftDistance <= 7  && frontDistance >= 2){
        if(rightDistance <= 8 && leftDistance >= 2){
          if(backDistance <= 3 && backDistance >= 2){
            checkPointCounter++;
            return true;
          }
        }
      }
    }
  } else if(checkPointCounter == 3){
    if(frontDistance <= 6 && frontDistance >= 3){
      if(leftDistance <= 7  && frontDistance >= 2){
        if(rightDistance <= 8 && leftDistance >= 2){
          if(backDistance <= 3 && backDistance >= 2){
            checkPointCounter++;
            return true;
          }
        }
      }
    }
  } else if (checkPointCounter == 4){
    if(frontDistance <= 6 && frontDistance >= 3){
      if(leftDistance <= 7  && frontDistance >= 2){
        if(rightDistance <= 8 && leftDistance >= 2){
          if(backDistance <= 3 && backDistance >= 2){
            return true;
          }
        }
      }
    }
  }
  return false;
}

//drives until a certain distance
void driveTo(TRUE_DIRECTION direction, double distance){
  double reading = 1000;
  drive(direction, standardSpeed);

  do{
    reading = ultrasonicRead(direction);
    delay(25);
  } while(reading > distance + 0.75 && reading < distance - 0.75);

  stop();
}