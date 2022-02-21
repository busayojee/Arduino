
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int val =  analogRead(A1); // I connected each sensor to A1 on the Arduino uno
Serial.println(val);

}
