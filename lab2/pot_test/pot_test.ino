// A simple script that tests potentiometer reads.
// Written by David Zhu.

// Declarations.
unsigned long reading;

void setup() {
  pinMode(A3, INPUT);  // Set the input read to A3.
  Serial.begin(9600);
}

void loop() {
  reading = analogRead(A3);
  Serial.println(reading);
  delay(100);
  
}
