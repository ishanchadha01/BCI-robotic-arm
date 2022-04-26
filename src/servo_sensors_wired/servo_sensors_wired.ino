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

const int ring = A0;
const int thumb = A1;
const int index = A2;
const int middle = A3;
const int pinky = A4;


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
  pos = map(thumb, 450, 550, 0, 180);
  Servo1.write(pos);
  pos = map(thumb, 500, 600, 0, 180);
  Servo2.write(pos);
  pos = map(thumb, 450, 600, 0, 180);
  Servo3.write(pos);
  pos = map(thumb, 450, 600, 0, 180);
  Servo4.write(pos);
  pos = map(thumb, 400, 560, 0, 180);
  Servo4.write(pos);
  
  Serial.print(analogRead(thumb));
  Serial.print(",");
  Serial.print(analogRead(index));
  Serial.print(",");
  Serial.print(analogRead(middle));
  Serial.print(",");
  Serial.print(analogRead(ring));
  Serial.print(",");
  Serial.println(analogRead(pinky));
}
