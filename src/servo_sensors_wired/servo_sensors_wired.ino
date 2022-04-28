#include <Servo.h>

const int pwm = 3;
const int pwm2 = 5;
const int pwm3 = 6;
const int pwm4 = 9;
const int pwm5 = 10;
const int pwm6 = 11;

Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;
Servo Servo5;
Servo Servo6;

const int ringRead = A0;
const int thumbRead = A1;
const int indexRead = A2;
const int middleRead = A3;
const int pinkyRead = A4;

int pos = 0;


void setup() {
  // put your setup code here, to run once:
  Servo1.attach(pwm);
  Servo2.attach(pwm2);
  Servo3.attach(pwm3);
  Servo4.attach(pwm4);
  Servo5.attach(pwm5);
  Servo6.attach(pwm6);

  Serial.begin(9600);

}

void loop() {
  // proportionally control motors based on flex sensor readings
  int thumb = constrain(analogRead(thumbRead), 100, 999);
  int pos1 = map(thumb, 450, 600, 0, 180);
  Servo6.write(pos1);

  int index = analogRead(indexRead);
  int pos2 = map(index, 500, 650, 0, 180);
  Servo2.write(pos2);

  int middle = analogRead(middleRead);
  int pos3 = map(middle, 450, 600, 0, 180);
  Servo3.write(pos3);

  int ring = analogRead(ringRead);
  int pos4 = map(ring, 450, 600, 0, 180);
  Servo4.write(pos4);

  int pinky = analogRead(pinkyRead);
  int pos5 = map(pinky, 400, 560, 0, 180);
  Servo5.write(pos5);
  
  Serial.print(analogRead(thumb));
  Serial.print(",");
  Serial.print(analogRead(index));
  Serial.print(",");
  Serial.print(analogRead(middle));
  Serial.print(",");
  Serial.print(analogRead(ring));
  Serial.print(",");
  Serial.println(analogRead(pinky));

  delay(500);

}
