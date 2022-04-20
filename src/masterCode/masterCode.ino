#include <SoftwareSerial.h>
#define BT_SERIAL_RX 0
#define BT_SERIAL_TX 1
SoftwareSerial BluetoothSerial(BT_SERIAL_RX, BT_SERIAL_TX);

void setup() {
    Serial.begin(38400);
    BluetoothSerial.begin(38400);
}

void loop() {

  BluetoothSerial.write("test");
  BluetoothSerial.println("test"); 
  Serial.println("test"); 
  delay(100); // prepare next data
}
