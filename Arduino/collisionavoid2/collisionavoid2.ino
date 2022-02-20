#include <ZumoShield.h>

#include <SharpIR.h>

//
//#define sensor 4
#define turnspeed 100
#define maxspeed  200
 ZumoMotors motor;

int distance1;
int distance2;
int maxi;
int val1;
int val2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //For a third sensor
//distance = analogRead(A5);
//int val = map(distance, 50, 400, 80, 10);

distance1 = analogRead(A1);
 val1 = map(distance1, 50, 400, 80, 10);
distance2 = analogRead(A3);
val2 = map(distance2, 50, 400, 80, 10);

// To see the values of the sensor on the serial monitor you can uncomment the print functions

//Serial.println(val);
//Serial.print(' ');
//Serial.print(val1);
//Serial.print(' ');
//Serial.print(val2);
//Serial.print('\n');
//delay(1000);

if(val2<0){  // if sensor 2 gets too close to an object 
  motor.setSpeeds(0,0);
  delay(1000);
  turnright();
  delay(2000);
  forward();
  }
 if(val1<0){ // if sensor 1 gets too close to an object
  motor.setSpeeds(0,0);
  delay(1000);
  turnleft();
  delay(2000);
  forward();
  }
  
 if(val1<0&&val2<0){ // if sensor 1 and sensor 2 gets too close to an object
    motor.setSpeeds(0,0);
    delay(2000);
   maxi =max(val1,val2); //find the maximum
  if(maxi == val1){ //if sensor 1 is the maximum

    turnright();
    delay(2000);
    forward();
    }
   else{ //if sensor 2 is the maximum
    turnleft();
    delay(2000);
    forward();
    }
  }
  if(val1>0&&val2>0){ // To keep going forward
    forward();
  }

}
void turnleft(){ // function to turn left
  motor.setRightSpeed(turnspeed);
  motor.setLeftSpeed(0);
  }
  void turnright(){ // function to turn right
  motor.setRightSpeed(0);
  motor.setLeftSpeed(turnspeed);
    }
 void forward(){ // function to move forward
  
  motor.setSpeeds(maxspeed, maxspeed);
  }
