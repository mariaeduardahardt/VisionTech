#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

float Distancia = 0;

float getDistance(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo,HIGH,30000)/58.0;
}

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  pinMode(2,OUTPUT);
  pinMode(9,OUTPUT);
  while(1) {
      Distancia = getDistance(3,4);
      if((Distancia > 50)  &&  (Distancia < 80)){
        tone(2,2349,0.1*1000);
        delay(0.1*1000);
        digitalWrite(9,0);
        _delay(1.5);
        tone(2,2349,0.1*1000);
        delay(0.1*1000);
        digitalWrite(9,1);
        _delay(1.5);

      }
      if((Distancia > 30)  &&  (Distancia < 50)){
        tone(2,2349,0.1*1000);
        delay(0.1*1000);
        digitalWrite(9,1);
        _delay(1);
        tone(2,2349,0.1*1000);
        delay(0.1*1000);
        digitalWrite(9,0);
        _delay(1);

      }
      if((Distancia > 10)  &&  (Distancia < 30)){
        tone(2,2349,0.1*1000);
        delay(0.1*1000);
        digitalWrite(9,1);
        _delay(0.7);
        tone(2,2349,0.1*1000);
        delay(0.1*1000);
        digitalWrite(9,0);
        _delay(0.7);

      }
      if(Distancia < 10){
        tone(2,2349,0.1*1000);
        delay(0.1*1000);
        digitalWrite(9,1);
        _delay(0.1);
        tone(2,2349,0.1*1000);
        delay(0.1*1000);
        digitalWrite(9,0);
        _delay(0.1);

      }

      _loop();
  }

}

void _loop() {
}

void loop() {
  _loop();
}