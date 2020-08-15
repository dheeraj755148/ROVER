//Before starting install the libraries required for Ultrasonic sensor and for motor driver shield for arduino.

//Happy Coding.
//If stuck use the resouces efficiently.

#include <AFMotor.h>     
#include <Servo.h>                  
#include <NewPing.h>   

#define TRIG_PIN A2
#define ECHO_PIN A3 
#define MAX_DISTANCE 300 
#define MAX_SPEED 130
#define MAX_SPEED_OFFSET 40 
#define COLL_DIST 30 
#define TURN_DIST COLL_DIST+20 
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

AF_DCMotor leftMotor1(1, MOTOR12_1KHZ); 
AF_DCMotor leftMotor2(2, MOTOR12_1KHZ); 
AF_DCMotor rightMotor1(3, MOTOR34_1KHZ);
AF_DCMotor rightMotor2(4, MOTOR34_1KHZ);
Servo myservo; 

int leftDistance, rightDistance;
int curDist = 0;
String motorSet = "";
int speedSet = 0;


void setup() {
  myservo.attach(10); 
  myservo.write(90);
  delay(1000);
 }

void loop() {
  myservo.write(90);
  delay(90);
  curDist = readPing();  
  if (curDist < COLL_DIST) {changePath();}
  moveForward(); 
  delay(500);
 }

void changePath() {
  moveStop();   
  myservo.write(36);  
    delay(500);
    rightDistance = readPing(); 
    delay(500);
    myservo.write(144); 
    delay(700);
    leftDistance = readPing(); 
    delay(500);
    myservo.write(90);
    delay(100);
    compareDistance();
  }

  
void compareDistance()   
{
  if (leftDistance>rightDistance)  
  {
    turnLeft();
  }
  else if (rightDistance>leftDistance)
  {
    turnRight();
  }
}


int readPing() { 
  delay(70);   
  unsigned int uS = sonar.ping();
  int cm = uS/US_ROUNDTRIP_CM;
  return cm;
}
void moveStop() {leftMotor1.run(RELEASE); leftMotor2.run(RELEASE); rightMotor1.run(RELEASE); rightMotor2.run(RELEASE);}  // stop the motors.

void moveForward() {
    motorSet = "FORWARD";
    leftMotor1.run(FORWARD);     
    leftMotor2.run(FORWARD);     
    rightMotor1.run(FORWARD);     
    rightMotor2.run(FORWARD);  
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2)
  {
    leftMotor1.setSpeed(speedSet);
    leftMotor2.setSpeed(speedSet);
    rightMotor1.setSpeed(speedSet); 
    rightMotor2.setSpeed(speedSet);
    delay(5);
  }
}
void moveBackward() {
    motorSet = "BACKWARD";
    leftMotor1.run(BACKWARD);     
    leftMotor2.run(BACKWARD);     
    rightMotor1.run(BACKWARD);    
    rightMotor2.run(BACKWARD);    
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) 
  {
    leftMotor1.setSpeed(speedSet);
    leftMotor2.setSpeed(speedSet);
    rightMotor1.setSpeed(speedSet); 
    rightMotor2.setSpeed(speedSet); 
    delay(5);
  }
}  
void turnRight() {
  motorSet = "RIGHT";
  leftMotor1.run(BACKWARD);     
  leftMotor2.run(BACKWARD);     
  rightMotor1.run(FORWARD);    
  rightMotor2.run(FORWARD);  
  rightMotor1.setSpeed(speedSet+MAX_SPEED_OFFSET);      
  rightMotor2.setSpeed(speedSet+MAX_SPEED_OFFSET);     
  delay(1500); 
  motorSet = "FORWARD";
  leftMotor1.run(FORWARD);     
  leftMotor2.run(FORWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);      
}  
void turnLeft() {
  motorSet = "LEFT";
  leftMotor1.run(FORWARD);     
  leftMotor2.run(FORWARD);    
    
  rightMotor1.run(BACKWARD);     
  rightMotor2.run(BACKWARD);   
  leftMotor1.setSpeed(speedSet+MAX_SPEED_OFFSET);     
  leftMotor2.setSpeed(speedSet+MAX_SPEED_OFFSET);
  delay(1500); 
  motorSet = "FORWARD";
  leftMotor1.run(FORWARD);     
  leftMotor2.run(FORWARD);     
  rightMotor1.run(FORWARD);    
  rightMotor2.run(FORWARD);    
}  
//If you want to make the above rover as two wheel drive update the coding accordingly. Additional things like back lights and headlights or tun lights can be added and the code can be changed accordingly.
