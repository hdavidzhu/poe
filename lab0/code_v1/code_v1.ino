// This is the Bike Light program.
// Written by Jack Fan and David Zhu.
// This program will allow the Arduino to do the following things:

// 0. Initial off.
// 1. Blinking.
// 2. All on.
// 3. Three on.
// 4. Bounce back and forth.
// 5. Blinking by proximity.

// Definitions.

// LEDS.
const int LED1 = 9;
const int LED2 = 10;
const int LED3 = 11;
const int LED4 = 12;
const int LED5 = 13;
const int distance_reader = A0;

// button and status.
const int button = 8;
int button_state = LOW;

// Modes.
const int modetype = 6; // How many different modes are there?
int mode = 0; // Tells what mode the device is in.
int state = 0; // The state allows us to create different blinking styles.

// Time.
long int time;
long int time_start;
int moving;

// Distance.
int distance;

// Setup.
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(distance_reader, INPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

// Loop.
void loop() {
  button_state = digitalRead(button);
  //Serial.print("Button State: ");
  //Serial.println(button_state);
  if (button_state==HIGH)
  {
    delay(500);
    mode = (mode+1)%modetype;
    state = 0;
    time = millis();
    time_start = millis();
  }
  //Serial.print("Mode ");
  //Serial.println(mode);
  
  if (mode == 0) { lightoff(); }
  if (mode == 1) { blinking(300); }
  if (mode == 2) { all_on(); }
  if (mode == 3) { three_on(); }
  if (mode == 4) { bounce (); }
  if (mode == 5) { blink_distance(); }
}

// All on.
void all_on() {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
}

// Blinking.
void blinking(int blink_delay) {
  time = millis();
    if (time >= time_start + blink_delay)
    {
      state++;
      time_start = millis();
      time = millis();
    }
    if (state%2 == 0)
    {  
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
    }
    if (state%2 == 1)
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
    }
    //Serial.print("time ");
    //Serial.print(time_start);
    //Serial.println(time);
}

// Blink by distance.
void blink_distance() {
  distance = analogRead(distance_reader);
  distance = 1500 - 2.5*distance;
  blinking(distance);
}

// Bounce.
void bounce() {
  time = millis();
    if (time >= time_start + 200)
    {
      if (moving == 0)
      {
        state++;
      }
      else
      {
        state--;
      }
      time_start = millis();
      time = millis();
    }
    if (state%5 == 0)
    {
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);      
      digitalWrite(LED1, HIGH);
      moving = 0;
    }
    if (state%5 == 1)
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED2, HIGH);
    }
    if (state%5 == 2)
    {
      digitalWrite(LED2, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED3, HIGH);
    }
    if (state%5 == 3)
    {
      digitalWrite(LED3, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED4, HIGH);
    }
    if (state%5 == 4)
    {
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      moving = 1;
    }
}

// Light off.
void lightoff() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
}

// Three lights on.
void three_on() {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, HIGH);
}
