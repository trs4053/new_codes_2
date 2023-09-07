/*
Enter value between 1000 and 2000 to control the motor...
And Select No Line Ending
*/

#include "Motor.h"

#define LPWM PA1
#define RPWM PA2


const byte interruptPin1 = PA8; //interrupt pin 
const byte interruptPin2 = PA9;
const byte interruptPin3 = PA10;
const byte interruptPin4 = PA11;

int speedVal1 = 1900;
int speedVal2 = 1900;
int speedVal3 = 1900;
int speedVal4 = 1900;

Motor wheel(LPWM,RPWM);

void setup() {
  Serial.begin(57600);

  pinMode(interruptPin1, INPUT_PULLUP);
  pinMode(interruptPin2, INPUT_PULLUP);
  pinMode(interruptPin3, INPUT_PULLUP);
  pinMode(interruptPin4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), stop, LOW);  
  attachInterrupt(digitalPinToInterrupt(interruptPin2), stop, LOW); 
  attachInterrupt(digitalPinToInterrupt(interruptPin3), stop, LOW); 
  attachInterrupt(digitalPinToInterrupt(interruptPin4), stop, LOW); 

  Serial.println("Enter value between 1000 and 2000 to control the motor...");
  Serial.println("And Select No Line Ending");

  delay(4000);
}

void loop() {
  if(Serial.available())
  {
    Serial.println("got data from serial");
    speedVal = Serial.parseInt();
    
    speedVal = constrain(speedVal, 1000, 2000);
    // speedVal = map(speedVal, -100, 100, -resolution, resolution);  
  }
  
  wheel.rotate(speedVal);

  Serial.println(speedVal);
  delay(1000);
}

void stop(){
  speedVal1=0;
  speedVal2=0;
  speedVal3=0;
  speedVal4=0;  
}
