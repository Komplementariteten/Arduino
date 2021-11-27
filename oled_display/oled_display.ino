#include <math.h>
#include <SPI.h>
#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4 // not used / nicht genutzt bei diesem Display
Adafruit_SSD1306 display(OLED_RESET);

const int TRIGGER_OUT = 12; // analog input
const int ECHO_IN = 11; // digital input
const float MAX_HEIGHT = 60; // 1px margin
const int MAX_WIDTH = 120; // 1px margin
long tof = 0;
long distance = 0;

void setup() {
  // put your setup code here, to run once:

  // initialize with the I2C addr 0x3C / mit I2C-Adresse 0x3c initialisieren
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.begin(9600);

  pinMode(TRIGGER_OUT, OUTPUT);
  pinMode(ECHO_IN, INPUT); 
  display.setTextColor(WHITE);
  delay(400);
  display.clearDisplay();
}

int col_count = 0;
unsigned long value_a0 = 0;
int last_good = 0;
int displayValues[MAX_WIDTH]; 


void loop() {
  // put your main code here, to run repeatedly:
  display.setTextColor(WHITE);

  value_a0 = ping();
  
  displayValues[col_count] = normalize(value_a0);
  col_count++;

  printValues();
  delay(120);
}

unsigned long ping() {
  digitalWrite(TRIGGER_OUT, LOW);
  delayMicroseconds(3);
  digitalWrite(TRIGGER_OUT, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_OUT, LOW);
  pinMode(ECHO_IN, INPUT);
  unsigned long v = pulseIn(ECHO_IN, HIGH);
  return v;
}

void wait(int ms) {
  unsigned long start = micros();
  unsigned long current = micros();
  while(current-start<=ms) {
    current = micros();
  }
}

int normalize(unsigned long value) {
  float normalized = MAX_HEIGHT * (MAX_HEIGHT / value);
  int rounded = (int)lroundf(normalized);
  if (rounded > 0) {
    last_good = rounded;
  } else {
    rounded = last_good;
  }
  return rounded;
}

void printValues() {
  for(int i = 0; i <= col_count; i++) {
    display.drawPixel((2 + i), displayValues[i] + 2, WHITE);
  }
  display.display();

  if(col_count == MAX_WIDTH) {
    display.clearDisplay();
    col_count--;
    for(int j = 1; j <= col_count; j++) {
      displayValues[(j-1)] = displayValues[j];
    }
  }
}
