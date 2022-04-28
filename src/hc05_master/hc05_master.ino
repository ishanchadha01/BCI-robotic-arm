
const int ringRead = A0;
const int thumbRead = A1;
const int indexRead = A2;
const int middleRead = A3;
const int pinkyRead = A4;


void setup() {
  Serial.begin(9600);
}

void loop() {
  
  // proportionally control motors based on flex sensor readings
  int thumb = constrain(analogRead(thumbRead), 100, 999);

  int index = constrain(analogRead(indexRead), 100, 999);

  int middle = constrain(analogRead(middleRead), 100, 999);

  int ring = constrain(analogRead(ringRead), 100, 999);

  int pinky = constrain(analogRead(pinkyRead), 100, 999);
  

  String voltages = String(thumb)+","+String(index)+","+String(middle)+","+String(ring)+","+String(pinky);
  Serial.println(voltages); 
  delay(500);
}
