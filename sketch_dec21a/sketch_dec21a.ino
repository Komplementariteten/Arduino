#define PIN_LED 13
#define PIN_BUTTON 12
#define PIN1  8
#define PIN2  9
#define PIN3  10
#define PIN4  11
#define delay_between_steps 800

int step_number = 0;
int trigger_button = 0;
bool apply_changes = true;
bool was_high = false;

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
  
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(PIN_BUTTON) == HIGH) {  // Wenn auf der Eingangsleitung des Tasters HIGH anliegt ...
    Serial.print(trigger_button); 
    Serial.print(apply_changes);     
    if (trigger_button == 0 && apply_changes) {
      trigger_button = 1;        // LED anschalten,
      apply_changes = false;
      was_high = true;
    } else if (apply_changes) {
      trigger_button = 0;         // LED anschalten,
      apply_changes = false;
      was_high = true;
    }
  }
  
  if (digitalRead(PIN_BUTTON) == LOW && was_high)
  {
    apply_changes = true;
    was_high = false;   
  }
  if (trigger_button == 1) {
    run_active();
  } else {
    run_stop();
  }
}

void run_active() {
    digitalWrite(PIN_LED, HIGH);
    dostep(true);  
}

void run_stop() {
    digitalWrite(PIN_LED, LOW);  
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
