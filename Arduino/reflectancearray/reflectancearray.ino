#include <Wire.h>

#include <ZumoShield.h>
#define sensors 6 
unsigned int val[sensors];
ZumoMotors motors;

ZumoReflectanceSensorArray zumo;

void setup() {
  // put your setup code here, to run once:
  zumo.init();
  
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  int i;
  for(i = 0; i<250; i++){
    if((i>50 && i<=100)||(i>150 && i<=200)){
      motors.setSpeeds(-100,100);
      }
      else{
        motors.setSpeeds(100,-100);
        }
    
    zumo.calibrate();
    delay(50);
    }
   motors.setSpeeds(0,0);
   digitalWrite(13, LOW);
   Serial.begin(9600);
//   for(byte i = 0; i<sensors; i++){
//    Serial.print(zumo.calibratedMinimumOn[i]);
//    Serial.print(' ');
//}
//Serial.print('\n');
//  for(byte i = 0; i<sensors; i++){
//    Serial.print(zumo.calibratedMaximumOn[i]);
//    Serial.print(' ');
//}
//Serial.print('\n');
 
 for(byte i = 0; i<sensors; i++){
  
  Serial.print(val[i]);
  Serial.print(' ');
 }







//Serial.println();
//Serial.println();
delay(1000);
}
void loop() {
  // put your main code here, to run repeatedly:
  unsigned int position = zumo.readLine(val);
  Serial.print('\n');
  Serial.println(position);
  

}
