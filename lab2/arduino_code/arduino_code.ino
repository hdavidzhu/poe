// Arduino code for motor control.
// Created by David Zhu and Jack Fan.

// Packages.
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"



// Definitions.

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

int pot = A3;
int pot_reading;
int pot_pos;
int final = 500;
float error;
float porp = 2.0;
float d1 = 0;
float d2 = 0;
float diff = 0;
float coefficient_diff = 1.0;

void setup() {
  Serial.begin(9600);
  pinMode(pot, INPUT);
  AFMS.begin();  // create with the default frequency 1.6KHz
}

void loop() {
  pot_reading = analogRead(pot);
  error = pot_reading - final;
  d1 = d2;
  d2 = error;
  diff = d2 - d1;
  diff = coefficient_diff * diff;
  // pot_pos = map(pot_reading,0,1024,0,255);
  error = map(error,0,1024,0,255);
  error = error * porp ;//+ diff;
  if (error >= 0) {
    myMotor->setSpeed(error);
    myMotor->run(FORWARD);
  }
  else {
    myMotor->setSpeed(-error);
    myMotor->run(BACKWARD);
  }
}

