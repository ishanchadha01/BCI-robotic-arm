String message; //string that stores the incoming message
void setup()
{
  Serial.begin(38400); //set baud rate
  pinMode(2, OUTPUT); 
}

void loop()
{
  while(Serial.available())
  {
    message+=char(Serial.read());
  }
  if(!Serial.available())
  {
    if(message != "") // if we received some data, then light up an LED
    {   
      digitalWrite(2, HIGH);    
      Serial.println(message);
          message="";
    }
  }
  delay(200);
}
