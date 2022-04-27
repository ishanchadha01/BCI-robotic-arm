
#include <SoftwareSerial.h>
#include <Servo.h>

// Define bluetooth variables
String message;
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

int pos = 0;


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
  index = 0;
  if(Serial.available() > 0)
  {
    message += char(Serial.read());
  }
  else
  {
    if(message != "") // if we received some data, then light up an LED
    {  
     char * S = new char[message.length() + 1];
     strcpy(S, message.c_str());

     ptr = strtok(S, ",");  // delimiter
     Serial.println(ptr);
     while (ptr != NULL)
     {
        strings[index] = ptr;
        index++;
        ptr = strtok(NULL, ",");
     }

      delay(500);

     int thumbAngle = atoi(strings[0]);
     Serial.println("THUMB ANGLE: " + thumbAngle);

     int indexAngle = atoi(strings[1]);
     Serial.println("INDEX ANGLE: " + indexAngle);

     int middleAngle = atoi(strings[2]);
     Serial.println("MIDDLE ANGLE: " + middleAngle);

     int ringAngle = atoi(strings[3]);
     Serial.println("RING ANGLE: " + ringAngle);

     int pinkyAngle = atoi(strings[4]);
     Serial.println("PINKY ANGLE: " + pinkyAngle);


     //Servo6.write(thumbAngle);
     //Servo2.write(indexAngle);
     //Servo3.write(middleAngle);
     //Servo4.write(ringAngle);
     //Servo5.write(pinkyAngle);
    
      }
    }

    memset(strings, 0, sizeof strings);
}
