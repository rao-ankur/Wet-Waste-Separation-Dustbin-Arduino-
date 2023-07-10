#include<Servo.h>
Servo servo1;
int pos;

int IRSensor = 4; // connect ir sensor to arduino pin 4
int LED = 9; // connect Led to arduino pin 13
int led2=8;
int moisture = A4;  

const int trigPinR = 47;
const int echoPinR = 45;
const int trigPinG = 32;
const int echoPinG = 34;
const int led_green = 13;
const int led_red = 12;
const int buzzer=51;
float durationR=0, distanceR=0,durationG=0, distanceG=0;

void setup() 
{
  // ultrasonic
 pinMode(trigPinR, OUTPUT);
 pinMode(trigPinG, OUTPUT);
 pinMode(echoPinR, INPUT);
 pinMode(echoPinG, INPUT);
 pinMode(led_green, OUTPUT);
 pinMode(led_red, OUTPUT);
 Serial.begin(9600);

  // ir and moisture
  servo1.attach(2);
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (led2, OUTPUT);
  pinMode (LED, OUTPUT); // Led pin OUTPUT
  pinMode (moisture, INPUT);
}

void loop()
{
   
   // ultrasonic
   digitalWrite(trigPinG, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPinG, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPinG, LOW);
   durationG = pulseIn(echoPinG, HIGH);
   distanceG = (durationG*.0343)/2;
   delay(10);
   digitalWrite(trigPinR, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPinR, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPinR, LOW);
   durationR = pulseIn(echoPinR, HIGH);
   distanceR = (durationR*.0343)/2;
   delay(10);
   
     if(distanceG<=10 || distanceR<=10 ){
       tone(buzzer, 10);
      // Serial.println(distanceR);
         if(distanceG<=10){
          digitalWrite(led_green,HIGH);
         } else {
          digitalWrite(led_green,LOW);
         }
          if(distanceR<=10){
          digitalWrite(led_red,HIGH);
         } else{
          digitalWrite(led_red,LOW);
         }
         delay(10);
      }
      
     else if(distanceG>10 && distanceR>10){
      digitalWrite(led_red,LOW);
      digitalWrite(led_green,LOW);
      noTone(buzzer);
        //   int value = analogRead(moisture);
         //  Serial.println(value);
           //delay(2000);
           int statusSensor = digitalRead (IRSensor);
           
           if (statusSensor == 0){
            delay(1000);
              int value = analogRead(moisture);
              Serial.println(value);
              delay(100);
               if (value>15) {
                   digitalWrite(led2, LOW);
                   digitalWrite(LED, HIGH); 
                   servo1.write(90); // resets to initial position
                   delay(1000);
                   servo1.write(170);
                   delay(1000);
                   servo1.write(90);
                   delay(1000);
                } else if (value<15){
                  digitalWrite(LED, LOW);
                  digitalWrite(led2, HIGH);
                  servo1.write(90); // resets to initial position
                  delay(1000);
                  servo1.write(-70);
                  delay(1000);
                  servo1.write(90);
                  delay(1000);
                }
           }
  
           
      }
    
   delay(100);
  
}