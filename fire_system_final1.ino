#include <Servo.h>
Servo myservo;
int servopin = 6;
int gasSensorA = A5;
int sensorValue = 0;
int pos=0;
void setup()
{
  pinMode(A5, INPUT);
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  myservo.attach(servopin); 
}
void loop()
{
   sensorValue = analogRead(gasSensorA);
   if (sensorValue > 20)
   {
     sensorValue = analogRead(A5);
     digitalWrite(7, HIGH);
     tone(7,500,1000);  
   }
  if(digitalRead(7)==HIGH)
  {
    myservo.write(90);
  }
  else
  {
    myservo.write(0);
  }
  delay(1000);
}