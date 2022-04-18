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

const int flex13 = A8;
const int flex19 = A9;
const int flex8 = A10;
const int flex15 = A11;
const int flex31 = A12;


void setup() {
  // attach servos to PWM outputs
  Servo1.attach(pwm);
  Servo2.attach(pwm2);
  Servo3.attach(pwm3);
  Servo4.attach(pwm4);
  Servo5.attach(pwm5);
  Servo6.attach(pwm6);

  // read from flex sensors
  pinMode(flex13, INPUT);
  pinMode(flex19, INPUT);
  pinMode(flex8, INPUT);
  pinMode(flex15, INPUT);
  pinMode(flex31, INPUT);

  // write original servo positions
  Servo1.write(60);
  Servo2.write(60);
  Servo3.write(60);
  Servo4.write(60);
  Servo5.write(60);
  
  Serial.begin(9600);

}

void loop() {
  delay(20);

  if (analogRead(flex13) > 600) {
    Servo1.write(180);
  } else {
    Servo1.write(0);
  }

  if (analogRead(flex19) > 750) {
    Servo2.write(180);
  } else {
    Servo2.write(0);
  }

  if (analogRead(flex8) > 800) {
    Servo3.write(180);
  } else {
    Servo3.write(0);
  }

  if (analogRead(flex15) > 750) {
    Servo4.write(180);
  } else {
    Servo4.write(0);
  }

  if (analogRead(flex31) > 650) {
    Servo5.write(180);
  } else {
    Servo5.write(0);
  }
    
 
  Serial.print(analogRead(flex13));
  Serial.print(",");
  Serial.print(analogRead(flex19));
  Serial.print(",");
  Serial.print(analogRead(flex8));
  Serial.print(",");
  Serial.print(analogRead(flex15));
  Serial.print(",");
  Serial.println(analogRead(flex31));
}
