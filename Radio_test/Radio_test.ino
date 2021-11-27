#include <Arduino.h>
#include "lib/RCSwitch.h"

RCSwitch mySwitch = RCSwitch();

void setup() {
    Serial.begin(9600);
    mySwitch.enableTransmit(0);
}

void loop() {
    if(mySwitch.available()) {

        Serial.print("Received");
        Serial.print(mySwitch.getReceivedValue());
        Serial.print(" / ");
        Serial.print(mySwitch.getReceivedBitlength());
        Serial.print("bit ");
        Serial.print("Protocol: ");
        Serial.println( mySwitch.getReceivedProtocol() );

        mySwitch.resetAvailable();
    }
    delay(200);
}