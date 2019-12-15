#define ENABLE 5
#define DIRA 4
#define DIRB 3

#define BAUD 9600
#define DELAY_TIME 100

String receivedString;
void setup() {

  Serial.begin(BAUD);
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  
  digitalWrite(ENABLE,LOW);
  digitalWrite(DIRA,LOW);
  digitalWrite(DIRB,LOW);

}

void loop() {
  
  if (Serial.available() > 0){
    receivedString = Serial.readStringUntil('\n');

  if(receivedString=="TURN_ON"){
    digitalWrite(ENABLE,HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
  } else if(receivedString=="TURN_OFF"){
    digitalWrite(ENABLE,LOW);
    digitalWrite(LED_BUILTIN, LOW);
  } else if(receivedString=="FORWARDS"){
    digitalWrite(DIRA,HIGH);
    digitalWrite(DIRB,LOW);
  } else if(receivedString=="BACKWARDS"){
    digitalWrite(DIRA,LOW);
    digitalWrite(DIRB,HIGH);
  }
  }
  
}
