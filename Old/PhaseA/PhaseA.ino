//first you need to open the serial monitor and enter a number as speed 

//drive train motor initialization. The directional vectors represent the clock wise rotation is positive and anticlockwise is negative

//drive train front right and direction polarity value
int DTFR = 5;
int DTFR_P = 1;

//drive train front left and direction polarity value
int DTFL = 6;
int DTFL_P = 1;

//drive train back right and direction polarity value
int DTBR = 7;
int DTBR_P = 1;

//drive train back left and direction polarity value
int DTBL = 8;
int DTBL_P = 1;

void setup() 
{ 
  pinMode(DTFR, OUTPUT);
  pinMode(DTFL, OUTPUT);
  pinMode(DTBR, OUTPUT);
  pinMode(DTBL, OUTPUT);

  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{ 
//  if (Serial.available())
  {
    int speed = Serial.parseInt();
  //  if (speed >= 0 && speed <= 255)
    {
      analogWrite(motorPin, 240);
    }
  }
} 

//Speed is the speed at which to go in direction
void driveForward(double speed){
    analogWrite(DTFR, speed * DTFR_P);
    analogWrite(DTFL, speed * DTFL_P * -1);
    analogWrite(DTBR, speed * DTBR_P);
    analogWrite(DTBL, speed * DTBL_P * -1);
}

//Speed is the speed at which to go in direction
void driveBackward(double speed){
    analogWrite(DTFR, speed * DTFR_P * -1);
    analogWrite(DTFL, speed * DTFL_P);
    analogWrite(DTBR, speed * DTBR_P * -1);
    analogWrite(DTBL, speed * DTBL_P);
}

//Speed is the speed at which to go in direction
void strafeRight(double speed){
    analogWrite(DTFR, speed * DTFR_P * -1);
    analogWrite(DTFL, speed * DTFL_P * -1);
    analogWrite(DTBR, speed * DTBR_P);
    analogWrite(DTBL, speed * DTBL_P);
}

//Speed is the speed at which to go in direction
void strafeLeft(double speed){
    analogWrite(DTFR, speed * DTFR_P);
    analogWrite(DTFL, speed * DTFL_P);
    analogWrite(DTBR, speed * DTBR_P * -1);
    analogWrite(DTBL, speed * DTBL_P * -1);
}

//diagonal strafe forward right
void diagonalforwardright(double speed){
    analogWrite(DTFR, speed * DTFR_P * 0);
    analogWrite(DTFL, speed * DTFL_P * -1);
    analogWrite(DTBR, speed * DTBR_P * 1);
    analogWrite(DTBL, speed * DTBL_P * 0);
}

//diagonal strafe backward right
void diagonalbackwardright(double speed){
    analogWrite(DTFR, speed * DTFR_P * -1);
    analogWrite(DTFL, speed * DTFL_P * 0);
    analogWrite(DTBR, speed * DTBR_P * 0);
    analogWrite(DTBL, speed * DTBL_P * 1);
}

//diagonal strafe forward left
void diagonalforwardleft(double speed){
    analogWrite(DTFR, speed * DTFR_P * 1);
    analogWrite(DTFL, speed * DTFL_P * 0);
    analogWrite(DTBR, speed * DTBR_P * 0);
    analogWrite(DTBL, speed * DTBL_P * -1);
}
  
//diagonal strafe backward left
void diagonalbackwardleft(double speed){
    analogWrite(DTFR, speed * DTFR_P * 0);
    analogWrite(DTFL, speed * DTFL_P * 1);
    analogWrite(DTBR, speed * DTBR_P * -1);
    analogWrite(DTBL, speed * DTBL_P * 0);
}