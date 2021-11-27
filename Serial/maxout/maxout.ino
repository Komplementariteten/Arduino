bool printSerial;
long randNumber;
void setup() {
  // put your setup code here, to run once:
    randomSeed(analogRead(0));
    pinMode(LED_BUILTIN, OUTPUT);
    printSerial = false;
    Serial.begin(115200);
    while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  randNumber = random(0,255);
  Serial.print(randNumber, HEX);
}
