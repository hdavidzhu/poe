int light = 13;
int buff;

void setup() {
  pinMode(light, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buff = Serial.read();
  Serial.print(buff);
  if(buff == 1) {
    digitalWrite(light, HIGH);
  }
  
  digitalWrite(light, HIGH);
}

