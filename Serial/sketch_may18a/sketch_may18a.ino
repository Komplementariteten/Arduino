bool printSerial;
long randNumber;
void setup() {
  // put your setup code here, to run once:
    randomSeed(analogRead(0));
    pinMode(LED_BUILTIN, OUTPUT);
    printSerial = false;
    Serial.begin(9600);
    while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  randNumber = random(0,255);
  if (randNumber > 128) {
    printSerial = false;
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);                    
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  } else if(!printSerial) {
    printSerial = true;
  }
  if(Serial && printSerial) {
    Serial.print(randNumber, HEX);
  }
  delay(10);
}
