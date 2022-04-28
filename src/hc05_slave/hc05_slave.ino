
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
  
     int thumbVolts = atoi(strings[4]);
     int indexVolts = atoi(strings[2]);
     int middleVolts = atoi(strings[3]);  
     int ringVolts = atoi(strings[1]);  
     int pinkyVolts = atoi(strings[0]);
     int wristVolts = atoi(strings[5]);

     int thumbAngle = map(thumbVolts, 450, 550, 0, 180);
     Serial.print(thumbVolts);
     Serial.print(",");
     Serial.println(thumbAngle);
     int indexAngle = map(indexVolts, 450, 600, 0, 180);
     //Serial.println(indexAngle);
     int middleAngle = map(middleVolts, 450, 600, 0, 180); 
     //Serial.println(middleAngle);
     int ringAngle = map(ringVolts, 500, 600, 0, 180);
     //Serial.println(ringAngle); 
     int pinkyAngle = map(pinkyVolts, 420, 560, 0, 180);
     //Serial.println(pinkyAngle); 
     int wristAngle  = map(wristVolts, 100, 200, 0, 30);
  
     Servo1.write(thumbAngle);
     Servo2.write(indexAngle);
     Servo3.write(middleAngle);
     Servo4.write(ringAngle);
     Servo5.write(pinkyAngle);
  
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
