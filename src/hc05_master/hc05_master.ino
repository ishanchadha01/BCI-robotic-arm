#include <Wire.h>

// Gyro address
const int MPU = 0x68;
int16_t AcX, AcY, AcZ, GyX, GyY, GyZ;
const int ringRead = A0;
const int thumbRead = A1;
const int indexRead = A2;
const int middleRead = A3;
const int pinkyRead = A4;


void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop() {

  // Gyro transmission
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 12, true);
  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  GyX = Wire.read() << 8 | Wire.read();
  GyY = Wire.read() << 8 | Wire.read();
  GyZ = Wire.read() << 8 | Wire.read();

  // proportionally control motors based on flex sensor readings
  int thumb = constrain(analogRead(thumbRead), 100, 999);

  int index = constrain(analogRead(indexRead), 100, 999);

  int middle = constrain(analogRead(middleRead), 100, 999);

  int ring = constrain(analogRead(ringRead), 100, 999);

  int pinky = constrain(analogRead(pinkyRead), 100, 999);

  int acc = map(AcZ / 256, -70, 70, 100, 200); // read one direction of gyro


  String voltages = String(thumb) + "," + String(index) + "," + String(middle) + "," + String(ring) + "," + String(pinky) + "," + String(acc);
  Serial.println(voltages);
  delay(500);
}
