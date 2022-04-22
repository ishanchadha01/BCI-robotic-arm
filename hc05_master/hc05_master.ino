#include <SoftwareSerial.h>

#define BT_NAME   "BT_Master"

#define SLAVE_ADDRESS "98d3,31,8095c3"  //98d3:31:8095c3

SoftwareSerial mySerial(0, 1); // RX, TX

void setup()
{
  Serial.begin(38400);
}

void loop()
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}
