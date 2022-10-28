// defines pins numbers
const int trigF = 2; // front sensor
const int echoF = 3;

const int trigB = 4; // back sensor
const int echoB = 5;

const int trigR = 6; // right sensor
const int echoR = 7;

const int trigL = 8; // left sensor
const int echoL = 9;

// defines variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

int get_Right_Distance() {
  // Clears the trigPin
  digitalWrite(trigR, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigR, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoR, HIGH);
  
  // Calculating the distance
  distanceR = duration * 0.034 / 2;

  return d_R;
}


int get_Left_Distance(){
  // Clears the trigPin
  digitalWrite(trigL, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigL, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoL, HIGH);
  
  // Calculating the distance
  distanceL = duration * 0.034 / 2;

  return d_L;
}

void center_straight (){
  
  distanceR = int get_Right_Distance();
  distanceL = int get_Left_Distance();

  if (distanceR < r_min){
    // move diagonally left to center 
  }

  if (distanceL < l_min){
    // move diagonally right to center 
  } 
}


void center_strafe (){
  
  distanceR = int get_Right_Distance();
  distanceL = int get_Left_Distance();

  if (distanceR < r_min){
    // strafe left to center 
  }

  if (distanceL < l_min){
    // strafe right to center 
  } 
}


f_min = 0;

void forward (){

  while (distanceF > f_min){
    // drive forward

    void center_strafe(){
      
  }
 }
}




void left(){
}

void right(){
}

void back(){
}


void turn_right(){
}

void turn_left(){
}
