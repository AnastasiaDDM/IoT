
#define MQPIND1 8
#define SOUNDPIND 12

void setup() {
  Serial.begin(9600);
  
  pinMode (MQPIND1, INPUT);
  pinMode (SOUNDPIND, INPUT);

}

void loop(){

  if (digitalRead(MQPIND1) == HIGH) {
    Serial.print("\r\nGas level exceeded");
  }
  
  if (digitalRead(SOUNDPIND) == HIGH) {
    Serial.print("\r\nNoise level exceeded");
  }
}
