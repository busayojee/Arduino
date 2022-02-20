const int button = 7;
int butt;
void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 butt = digitalRead(button);
 Serial.println(butt);
 delay(1000);
}
