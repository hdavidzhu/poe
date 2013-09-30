// Lab 1.
// LIDAR Project.

// Declarations
#include <Servo.h>
Servo base_servo;    // create servo objects to control servos
Servo sensor_servo;

int base_servo_pos;               // variables to sotre the servo position
int sensor_servo_pos;
const int distance_reader = A0;  // analog input A0 for infrared sensor
int distance;                    // distance of sensor to obstacle
char readinchar;
char readinstr[3];
int readinint;

// Setup.
void setup() {
  Serial.begin(9600);    // start serial communiation
  base_servo.attach(7);   // attaches the servo on pin 7 to the base_servo object
  sensor_servo.attach(4);   // attaches the servo on pin 8 to the sensor_servo object
  pinMode(distance_reader, INPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
}

// Loop.
void loop() {
  base_servo_pos = Readin();
  base_servo.write(base_servo_pos);
  sensor_servo_pos = Readin();
  sensor_servo.write(sensor_servo_pos);
  delay(3);
  distance = analogRead(distance_reader);
  delay(3);
  distance = distance + analogRead(distance_reader);
  delay(3);
  distance = distance + analogRead(distance_reader);
  Serial.println(distance/3);

}

int Readin(){
  int i = 0;
  while (1){
    while (Serial.available() ==0);
    readinchar = Serial.read();
    if (readinchar == 'a'){
      readinint = atoi(readinstr);
      //readinstr[0] = '\n';
      //Serial.println(readinint);
      return readinint;
    }
    readinstr[i] = readinchar;
    i++;
  }
}
