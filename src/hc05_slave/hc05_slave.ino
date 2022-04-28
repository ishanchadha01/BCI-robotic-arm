
#include <SoftwareSerial.h>
#include <Servo.h>

// Define bluetooth variables
char message[255];
char *strings[255]; // an array of pointers to the pieces of the above array after strtok()
char *ptr = NULL;
byte index = 0;

// Define motor pwm variables
const int pwm = 3;
const int pwm2 = 5;
const int pwm3 = 6;
const int pwm4 = 9;
const int pwm5 = 10;
const int pwm6 = 11;

// Define servo variables
Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;
Servo Servo5;
Servo Servo6;


void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT); 

  Servo1.attach(pwm);
  Servo2.attach(pwm2);
  Servo3.attach(pwm3);
  Servo4.attach(pwm4);
  Servo5.attach(pwm5);
  Servo6.attach(pwm6);
}

void loop()
{
  while(strlen(message) != 25) {
    if(Serial.available() > 0)
    {
      char i = char(Serial.read());
      char* d = &message[0];
      append(d, i);
    }
  }

  if(strlen(message) == 25) // if we received some data, then light up an LED
  {  

     ptr = strtok(message, ",");  // delimiter
     while (ptr != NULL)
     {
        strings[index] = ptr;
        index++;
        ptr = strtok(NULL, ",");
     }
  
     int thumbVolts = constrain(atoi(strings[0]), 410, 570);
     int indexVolts = constrain(atoi(strings[1]), 460, 570);
     int middleVolts = constrain(atoi(strings[2]), 450, 570);  
     int ringVolts = constrain(atoi(strings[3]), 500, 600);   
     int pinkyVolts = constrain(atoi(strings[4]), 430, 570); 
     int wristVolts = atoi(strings[5]);

     int thumbAngle = map(thumbVolts, 410, 570, 0, 180);
     Serial.print(thumbAngle);
     Serial.print(",");
     int indexAngle = map(indexVolts, 460, 570, 0, 180);
     Serial.print(indexAngle);
     
     Serial.print(",");
     int middleAngle = map(middleVolts, 450, 570, 0, 180); 
     Serial.print(middleAngle);
     Serial.print(",");
     int ringAngle = map(ringVolts, 500, 600, 0, 180);
     Serial.print(ringAngle);
     Serial.print(","); 
     int pinkyAngle = map(pinkyVolts, 430, 570, 0, 180);
     Serial.print(pinkyAngle); 
     Serial.print(",");
     int wristAngle  = map(wristVolts, 100, 200, 0, 45);
     Serial.println(wristAngle);
  
     Servo1.write(middleAngle);
     Servo2.write(wristAngle);
     Servo3.write(thumbAngle);
     Servo4.write(pinkyAngle);
     Servo5.write(indexAngle);
     Servo6.write(ringAngle);
  
    memset(message, 0, sizeof message);
    memset(strings, 0, sizeof strings);
    index = 0;
 }
}

int append(char* s, char c) {
  int len = strlen(s);
  s[len] = c;
  s[len+1] = '\0';
  return 0;
}
