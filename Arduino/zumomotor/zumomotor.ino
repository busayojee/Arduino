#include <ZumoShield.h>

#include <ZumoMotors.h>

#define LEDPIN 13
ZumoMotors motors;

//int sp=200;
//int sp2=100;
//int sp3=0;

void setup() {
  // put your setup code here, to run once:
    pinMode(LEDPIN, OUTPUT);
//    motors.flipLeftMotor(true);
//    motors.flipRightMotor(true);
//  cow();
//  cir();
//right();
//left();
digitalWrite(LEDPIN, HIGH);
cow();
delay(1000);
digitalWrite(LEDPIN, LOW);
right();
delay(1000);
digitalWrite(LEDPIN, HIGH);
right();
delay(1000);

digitalWrite(LEDPIN, LOW);
right();
delay(1000);
digitalWrite(LEDPIN, HIGH);
back();
delay(1000);
digitalWrite(LEDPIN, LOW);
cir();
delay(5800);
motors.setSpeeds(0,0);



}
void cow(){
    motors.setSpeeds(200,200);
    delay(1000);
    motors.setSpeeds(0,0);
}
void back(){
    motors.setSpeeds(-200,-200);
    delay(1000);
    motors.setSpeeds(0,0);
}
void cir(){
//    for(int l=0;l<200;l++){
//      for(int k = 0; k>-200; k--){
      motors.setRightSpeed(250);
      motors.setLeftSpeed(150);  
      delay(5800);
      
      
      
      
//      }  
//    }
}
void curve(){
//    for(int l=0;l<200;l++){
//      for(int k = 0; k>-200; k--){
      motors.setRightSpeed(200);
      motors.setLeftSpeed(100);  
      delay(5000);
     
}
void right(){
   motors.setRightSpeed(0);
  motors.setLeftSpeed(100);
  delay(1600);
  motors.setSpeeds(0,0);
  cow();
  }
void left(){
     motors.setRightSpeed(100);
  motors.setLeftSpeed(0);
  delay(1600);
  motors.setSpeeds(0,0);
  cow();  
}
void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(LEDPIN, HIGH);
////
////   for(int speed = 0; speed<= 50; speed++){
//  motors.setRightSpeed(0);
//    motors.setLeftSpeed(200);
//    delay(2000);
////    }
////   for(int speed = 0; speed= 200; speed++){
////    motors.setLeftSpeed(speed);
////    delay(200);
////    }
//
//    digitalWrite(LEDPIN, LOW);
////   for(int speed = 0; speed>= -20; speed++){
////    motors.setLeftSpeed(speed);
////    delay(200);
////    }B
////   for(int speed = 200; speed<= 0; speed++){
////    motors.setLeftSpeed(speed);
////    delay(200);
////    }
////    digitalWrite(LEDPIN, HIGH);
////    delay(200);
////
////  for(int speed = 0; speed<= 200; speed++){
////    motors.setRightSpeed(speed);
////    delay(200);
////    }
////   for(int speed = 200; speed>= 0; speed--){
////    motors.setRightSpeed(speed);
////    delay(200);
////    }
//
////    digitalWrite(LEDPIN, LOW);
////    delay(200);
//    
////  for(int speed = 0; speed<= 200; speed++){
//  motors.setLeftSpeed(0);
//    motors.setRightSpeed(200);
//    delay(2000);
////    }
////   for(int speed = -200; speed<= 0; speed++){
////    motors.setRightSpeed(speed);
////    delay(200);
////    }
//  digitalWrite(LEDPIN, HIGH);
//  motors.setSpeeds(200,200);
//  delay(1000);
//  digitalWrite(LEDPIN, LOW);
//  motors.setLeftSpeed(0);
//  motors.setRightSpeed(100);
//  delay(4500);
//  digitalWrite(LEDPIN,HIGH);
//  motors.setRightSpeed(0);
//  motors.setLeftSpeed(-100);
//  delay(4500);
//  digitalWrite(LEDPIN,LOW);
//  motors.setSpeeds(200,200);
//  delay(2000);
  }
