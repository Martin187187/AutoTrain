#define ENABLE 5
#define DIRA 4
#define DIRB 3

void setup() {
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //---back and forth example
    Serial.println("One way, then reverse");
    digitalWrite(ENABLE,HIGH); // enable on
    for (int i=0;i<5;i++) {
    digitalWrite(DIRA,HIGH); //one way
    digitalWrite(DIRB,LOW);
    delay(500);
    digitalWrite(DIRA,LOW);  //reverse
    digitalWrite(DIRB,HIGH);
    delay(500);
  }
  digitalWrite(ENABLE,LOW); // disable
  delay(2000);

  Serial.println("fast Slow example");
  //---fast/slow stop example
  digitalWrite(ENABLE,HIGH); //enable on
  digitalWrite(DIRA,HIGH); //one way
  digitalWrite(DIRB,LOW);
  delay(3000);
  digitalWrite(ENABLE,LOW); //slow stop
  delay(1000);
  digitalWrite(ENABLE,HIGH); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
  delay(3000);
  digitalWrite(DIRA,LOW); //fast stop
  delay(2000);

  Serial.println("PWM full then slow");
  //---PWM example, full speed then slow
  analogWrite(ENABLE,255); //enable on
  digitalWrite(DIRA,HIGH); //one way
  digitalWrite(DIRB,LOW);
  delay(2000);
  analogWrite(ENABLE,180); //half speed
  delay(2000);
  analogWrite(ENABLE,128); //half speed
  delay(2000);
  analogWrite(ENABLE,50); //half speed
  delay(2000);
  analogWrite(ENABLE,128); //half speed
  delay(2000);
  analogWrite(ENABLE,180); //half speed
  delay(2000);
  analogWrite(ENABLE,255); //half speed
  delay(2000);
  digitalWrite(ENABLE,LOW); //all done
  delay(10000);
}
