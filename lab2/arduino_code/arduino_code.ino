// Arduino code for motor control.
// Created by David Zhu and Jack Fan.

// Packages.
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

// Definitions.
unsigned int pot = A3;
unsigned int pot_reading;

void setup() {
  Serial.begin(9600);
  
  
  pinMode(pot, INPUT);
  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotor->setSpeed(255);
  // myMotor->run(FORWARD);
  // turn on motor
  // myMotor->run(RELEASE);
  
}

void loop() {
  pot_reading = analogRead(pot);
  pot_reading = map(pot_reading,0,1024,0,255);
  Serial.println(pot_reading);
  myMotor->setSpeed(pot_reading);
  myMotor->run(FORWARD);
}
