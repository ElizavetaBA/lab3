#include <Arduino.h>
#include <Servo.h>

const int pinTrig = 8;
const int pinEcho = 9;
const int pinServo = 10;

long distance = 0;
int angle = 0;
// Чтение значения УЗ датчика

Servo servo;
float getDistance(){
    digitalWrite(pinTrig,LOW);
    delayMicroseconds(2);
    digitalWrite(pinTrig,HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig,LOW);
    return pulseIn(pinEcho,HIGH,30000)/58.0;
}

void setup() {
  pinMode(pinTrig,OUTPUT);
  pinMode(pinEcho, INPUT);
  servo.attach(pinServo);
  Serial.begin(9600);
}

void loop() {

   angle += 5;  
   if (angle > 180)
   {
     angle = 0;
     servo.write(angle);
     delay(500);
   }
   else
   { 
     servo.write(angle);
     delay(200);
   }
   distance = getDistance();
   Serial.print(angle);
   Serial.print(' ');
   Serial.println(distance);
}