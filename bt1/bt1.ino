#include <SoftwareSerial.h>
#define ledPin 13
#define rxPin 10
#define txPin 11
SoftwareSerial btSerial(rxPin, txPin);
String btData;
void setup() {
  btSerial.begin(9600);
  btSerial.println("bluetooth available");
  pinMode(ledPin,OUTPUT);
}
void loop() {
  if (btSerial.available()){
    btData = btSerial.readString();
      if(btData=="on"){
        digitalWrite(ledPin,1);
        btSerial.println("LED on Pin 13 is on");
      }
      if (btData=="off"){
        digitalWrite(ledPin,0);
        btSerial.println("LED on Pin 13 is off");
      }
    }
    delay(100);
}

