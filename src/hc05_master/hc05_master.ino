#include <SoftwareSerial.h>
#define BT_SERIAL_RX 0
#define BT_SERIAL_TX 1

void setup() {
    Serial.begin(9600);
}

void loop() {

  String turn = String(180)+","+String(180)+","+String(180)+","+String(180)+","+String(180);
  Serial.println(turn); 
  delay(2000);
  String back = String(0)+","+String(0)+","+String(0)+","+String(0)+","+String(0);
  Serial.println(back); 
  delay(2000);
}
