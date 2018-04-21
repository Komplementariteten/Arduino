int buzzerPin = 8;
int potPin1 = 1;
int potPin2 = 2;
int toneHeight, lfo;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
}
void play(int myToneHeight) {
  digitalWrite(buzzerPin, HIGH);
  delayMicroseconds(myToneHeight);
  digitalWrite(buzzerPin, LOW);
  delayMicroseconds(myToneHeight);
}

void loop() {
  // put your main code here, to run repeatedly:
  toneHeight=analogRead(potPin1);
  lfo=analogRead(potPin2);
  for(int i = (lfo/10); i > 0; i--){
    play(i);
  }
  delayMicroseconds(lfo);
  for(int i = 0; i < lfo/10; i++){
    play(i);
  }
}
