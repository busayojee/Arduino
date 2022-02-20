#include <ZumoShield.h>


#include <Wire.h>

ZumoReflectanceSensorArray zumo;
ZumoMotors motor;
#define sensor 6
#define LEDPIN 13
unsigned int val[sensor];
int lasterror=0;
int maxspeed=400;
int j=0;
int lastpos=0;
int leftspeed=maxspeed;
int rightspeed=maxspeed;
void find();
void setup() {
  // put your setup code here, to run once:
  zumo.init(); 
  pinMode(LEDPIN, OUTPUT);
  
  digitalWrite(LEDPIN, HIGH);
  for(int i = 0; i < 50; i++){
    if((i > 10 && i<=20)||(i > 40 && i<50)){
      motor.setSpeeds(-200,200);
      }
      else{
        motor.setSpeeds(200,-200);
        }
        zumo.calibrate();
        delay(50);
    }
 motor.setSpeeds(0,0);
 digitalWrite(LEDPIN, LOW);
 Serial.begin(9600);
 delay(1000);
}
void loop() {
  // put your main code here, to run repeatedly:
unsigned int pos = zumo.readLine(val);
//sine 2500 is the middle of the sensor, position would be used with 2500 to calculate the error  i.e the distance from the middle of the sensor
int error = pos-2500;
//Using PID to controll the speed for turning 
//the proprotion and derivative constant can be fine tuned
int dif=error/5+7*(error-lasterror);
lasterror=error;
leftspeed=maxspeed+dif;
rightspeed=maxspeed-dif;
if(leftspeed<0)leftspeed=0;
if(rightspeed<0)rightspeed=0;
if(leftspeed>maxspeed)leftspeed=maxspeed;
if(rightspeed>maxspeed)rightspeed=maxspeed;

if(error==2500 || error == -2500){
  j++;
  }
else{
    j=0;
}
if(j>=1000){
find();
 }
else motor.setSpeeds(leftspeed,rightspeed);

}
void find(){
   motor.setSpeeds(0,0);
delay(300);
motor.setRightSpeed(-maxspeed);
motor.setLeftSpeed(0);
delay(300);
motor.setRightSpeed(0);
motor.setLeftSpeed(-maxspeed);
delay(300);
motor.setRightSpeed(maxspeed);
motor.setLeftSpeed(0);
delay(300);
motor.setRightSpeed(0);
motor.setLeftSpeed(maxspeed);
delay(300);
}
  

    
//  if(timerstarted==false){
//    starttime = currenttime; //make the starttime be the current time which is the millis time
//    timerstarted = true;
//    
//    if(currenttime-starttime >= 3000){ // If the difference is more than 3 secs stop for 3 sec then go back
     
//      delay(3000);
//      motor.setRightSpeed(-maxspeed);
//      motor.setLeftSpeed(0);
//      delay(3000);
//      motor.setRightSpeed(0);
//      motor.setLeftSpeed(-maxspeed);
//      delay(3000);
//      }
//      }}
//      else{
//        j = 0;
//        }
//  timerstarted = false;
//  }
//  if(timerstarted == false){
//    error = 0;
//    starttime = currenttime;
//    if(currenttime-starttime > 3000){
//      motor.setSpeeds(0,0);
//    }
//    else{
//    timerstarted = true;
//    }

      
  
//else{
//  motor.setSpeeds(0,0);
//  }
//  j++;
//  if(j>=3000)motor.setSpeeds(0,0);
//}
//else j==0;
//}


  
