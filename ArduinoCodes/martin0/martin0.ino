
#define LED 3
#define BUTTON 5

bool power;
bool first;
void setup() {


  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(LED, LOW);

  power = LOW;
  first = true;
}

void loop() {

  if(first&&digitalRead(BUTTON)==HIGH){
    power = !power;
    first = false;
    digitalWrite(LED, power);
  } else if(digitalRead(BUTTON)!=HIGH){
    first = true;
  }

delay(10);
    
  
}
