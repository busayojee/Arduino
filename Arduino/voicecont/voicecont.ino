
const int threshold = 540;
const int sound = A0;
const int LED = 13;
//int sensorValue = 0;
//int sensorMin = 100;
//int sensorMax = 600;

void setup() {
  // put your setup code here, to run once:
//  pinMode(LED, OUTPUT);
  Serial.begin(9600);
//  while(millis()<5000){
//   sensorValue = analogRead(sound);
//   if(sensorValue > sensorMax){
//    sensorMax = sensorValue;
//    }
//   if(sensorValue < sensorMin){
//    sensorMin = sensorValue;
//    }
//    }
//    digitalWrite(LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorValue = analogRead(sound);
//  int mic2 = digitalRead(13);
  Serial.println(sound);
  if(sensorValue>threshold){
    digitalWrite(LED, HIGH);
    }
    else{
      digitalWrite(LED, LOW);
      }
  delay(100);
//sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
//
//  // in case the sensor value is outside the range seen during calibration
//  sensorValue = constrain(sensorValue, 0, 255);
//
//
//  // fade the LED using the calibrated value:
//  analogWrite(LED, sensorValue);
//Serial.println(sensorValue);
//  delay(100);
 

}
