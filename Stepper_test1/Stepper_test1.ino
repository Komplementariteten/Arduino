#define PIN1  9
#define PIN2  10
#define PIN3  11
#define PIN4  12
#define delay_between_steps 800

int step_number = 0;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIN1, OUTPUT); 
  pinMode(PIN2, OUTPUT); 
  pinMode(PIN3, OUTPUT); 
  pinMode(PIN4, OUTPUT); 
  digitalWrite(PIN1, HIGH); 
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN3, LOW);
  digitalWrite(PIN4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 8000; i++) {
    dostep(true);
  }
  delay(1000);
  delay("wait");
  for(int i = 0; i < 8000; i++) {
    dostep(false);
  }
  delay(1000);
  delay("wait");
}

void dostep(bool direction) {
  unsigned long current, start;
  start=micros();
  current=micros();
  while(current-start<=delay_between_steps) {
      current=micros();
  }
    switch(step_number) {
     case 0:
       digitalWrite(PIN1, LOW); 
       digitalWrite(PIN2, LOW);
       digitalWrite(PIN3, LOW);
       digitalWrite(PIN4, HIGH);
     break; 
     case 1:
       digitalWrite(PIN1, LOW); 
       digitalWrite(PIN2, LOW);
       digitalWrite(PIN3, HIGH);
       digitalWrite(PIN4, HIGH);
     break; 
     case 2:
       digitalWrite(PIN1, LOW); 
       digitalWrite(PIN2, LOW);
       digitalWrite(PIN3, HIGH);
       digitalWrite(PIN4, LOW);
     break; 
     case 3:
       digitalWrite(PIN1, LOW); 
       digitalWrite(PIN2, HIGH);
       digitalWrite(PIN3, HIGH);
       digitalWrite(PIN4, LOW);
     break; 
     case 4:
       digitalWrite(PIN1, LOW); 
       digitalWrite(PIN2, HIGH);
       digitalWrite(PIN3, LOW);
       digitalWrite(PIN4, LOW);
     break; 
     case 5:
       digitalWrite(PIN1, HIGH); 
       digitalWrite(PIN2, HIGH);
       digitalWrite(PIN3, LOW);
       digitalWrite(PIN4, LOW);
     break; 
     case 6:
        digitalWrite(PIN1, HIGH); 
        digitalWrite(PIN2, LOW);
        digitalWrite(PIN3, LOW);
        digitalWrite(PIN4, LOW);
      break; 
      case 7:
        digitalWrite(PIN1, HIGH); 
        digitalWrite(PIN2, LOW);
        digitalWrite(PIN3, LOW);
        digitalWrite(PIN4, HIGH);
      break; 
      default:
         digitalWrite(PIN1, LOW); 
         digitalWrite(PIN2, LOW);
         digitalWrite(PIN3, LOW);
         digitalWrite(PIN4, LOW);
         
    }    
  if(direction) {
    step_number++;    
    if (step_number > 7) {
      step_number = 0;
    }
  } else {
    step_number--;
    if(step_number < 0) {
      step_number = 7;
    }
  }
}
