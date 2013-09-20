// This short program will calibrate the proximity sensor.

// Definitions.
const int sensor = A0;
unsigned long sread;

// Setup.
void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

// Loop.
void loop() {
  if (Serial.read() > 0) {
    sread = analogRead(sensor);
    Serial.println(sread);
    delay(500);
  }
}
