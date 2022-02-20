#include <ZumoShield.h>
#include <ZumoMotors.h>
#define LEDPIN 13

ZumoMotors motors;


void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LEDPIN, HIGH);
  motors.setSpeeds(200,200);
  delay(3000);
  digitalWrite(LEDPIN, LOW);
  motors.setSpeeds(0,0);
  motors.setRightSpeed(100);
  delay(3000);
  

  
  

}
