#include <ZumoShield.h>

#define maxspeed  150
ZumoMotors motor;
int distance;
int distance1;
int distance2;
int val;
int val1;
int val2;
int error;
int diff;
int leftspeed;
int rightspeed;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
distance = analogRead(A3);
val = map(distance, 50, 400, 80, 10);
//Serial.println(val);
//delay(100);
distance1 = analogRead(A1);
 val1 = map(distance1, 50, 400, 80, 10);
// Serial.println(val1);
//delay(100);
distance2 = analogRead(A0);
 val2 = map(distance2, 50, 400, 80, 10);
// Serial.println(val2);
//delay(100);
if(val1>30&&val>30&&val2>30){
  motor.setSpeeds(maxspeed,maxspeed);
  
  }
if(val1<30&&val>30&&val2>30){// the middle sensor
  error=val1;
   diff=7*error;
   leftspeed=maxspeed-diff;
   rightspeed=maxspeed+diff;
   motor.setSpeeds(leftspeed,rightspeed);
  }
 
if(val<30||val2<30){
   error=val-val2;
   diff=7*error;
   leftspeed=maxspeed-diff;
   rightspeed=maxspeed+diff;
//  if(leftspeed>300)leftspeed=300;
//if(rightspeed>300)rightspeed=300;
//if(leftspeed<0)leftspeed=0;
//if(rightspeed<0)rightspeed=0;
  motor.setSpeeds(leftspeed,rightspeed);
}



if(val1<30 && val<30 && val2<30){
  int maxi = max(val,val2);
  error=maxi - val1;
   diff=7 *error;
   leftspeed=maxspeed-diff;
   rightspeed=maxspeed+diff;
   motor.setSpeeds(leftspeed,rightspeed);
  }
  //if(val1<-20 && val<-20 &&val2<-20)motor.setSpeeds(0,0);}

  if(val1<-20 && val<-20 && val2<-20){
    motor.setSpeeds(0,0);
  }

}
