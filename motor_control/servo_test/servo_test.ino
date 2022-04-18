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
  // put your main code here, to run repeatedly:

   Servo1.write(0);
   delay(1000); 
   Servo1.write(90);
   delay(1000); 
   Servo1.write(180); 
   delay(1000); 

   Servo2.write(0);
   delay(1000); 
   Servo2.write(90);
   delay(1000); 
   Servo2.write(180); 
   delay(1000); 

   Servo3.write(0);
   delay(1000); 
   Servo3.write(90);
   delay(1000); 
   Servo3.write(180); 
   delay(1000); 

   Servo4.write(0);
   delay(1000); 
   Servo4.write(90);
   delay(1000); 
   Servo4.write(180); 
   delay(1000); 

   Servo5.write(0);
   delay(1000); 
   Servo5.write(90);
   delay(1000); 
   Servo5.write(180); 
   delay(1000); 

   Servo6.write(0);
   delay(1000); 
   Servo6.write(90);
   delay(1000); 
   Servo6.write(180); 
   delay(1000); 

 
  
}
