#include <SoftwareSerial.h>
#include <String.h>
#include <Servo.h>

#define BT_SERIAL_RX 0
#define BT_SERIAL_TX 1

SoftwareSerial BluetoothSerial(BT_SERIAL_RX, BT_SERIAL_TX);

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

const int flex1 = A0;
const int flex2 = A1;
const int flex3 = A2;
const int flex4 = A3;
const int flex5 = A4;

void setup() {
  // attach servos to PWM outputs
  Servo1.attach(pwm);
  Servo2.attach(pwm2);
  Servo3.attach(pwm3);
  Servo4.attach(pwm4);
  Servo5.attach(pwm5);
  Servo6.attach(pwm6);

  // set input pins for flex sensors
  pinMode(flex1, INPUT);
  pinMode(flex2, INPUT);
  pinMode(flex3, INPUT);
  pinMode(flex4, INPUT);
  pinMode(flex5, INPUT);
  
  Serial.begin(38400);
  BluetoothSerial.begin(38400);
}

void loop() {

  //BluetoothSerial.write("test");
  //BluetoothSerial.println("test");

  // send flex sensor data over bluetooth
//  Serial.print((int) analogRead(flex1));
//  Serial.print(",");
//  Serial.print((int) analogRead(flex2));
//  Serial.print(",");
//  Serial.print((int) analogRead(flex3));
//  Serial.print(",");
//  Serial.print((int) analogRead(flex4));
//  Serial.print(",");
  Serial.print(0);
  Serial.print(",");
  Serial.print(0);
  Serial.print(",");
  Serial.print(0);
  Serial.print(",");
  Serial.print(0);
  Serial.print(",");
  Serial.println((int) (analogRead(flex5) > 700));
}
