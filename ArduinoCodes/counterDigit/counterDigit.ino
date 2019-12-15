
#define SER 3
#define PRINT 4
#define SHIFT 5


#define BAUD 9600
#define DELAY_TIME 100

bool number[10][8] = {  {0,0,1,1,1,1,1,1},  //zero
                        {0,0,0,0,0,1,1,0},  //one
                        {0,1,0,1,1,1,0,1},  //two
                        {0,1,0,0,1,1,1,1},  //three
                        {0,1,1,0,0,1,1,0},  //four
                        {0,1,1,0,1,0,1,1},  //five
                        {0,1,1,1,1,1,0,1},  //six
                        {0,0,0,0,0,1,1,1},  //seven
                        {0,1,1,1,1,1,1,1},  //eight
                        {0,1,1,0,1,1,1,1}   //nine
                      };
                        

int counter;

void setup() {
  
  Serial.begin(BAUD);
  
  pinMode(SER, OUTPUT);
  pinMode(PRINT, OUTPUT);
  pinMode(SHIFT, OUTPUT);

 

  for(int i = 0; i < 8; i++){
    
    digitalWrite(SER, number[0][i]);
    digitalWrite(SHIFT, HIGH);
    digitalWrite(SHIFT, LOW);
    
  }
  
    digitalWrite(PRINT, HIGH);

    counter = 0;
  
}





void loop() {


  String receivedString;

  if (Serial.available() > 0)
    receivedString = Serial.readStringUntil('\n');
  
  if(receivedString.length()==1){
      counter = receivedString.toInt();
  
  digitalWrite(PRINT, LOW);
    
  for(int i = 0; i < 8; i++){
    
    digitalWrite(SER, number[counter][i]);
    
    digitalWrite(SHIFT, HIGH);
    digitalWrite(SHIFT, LOW);
    
  }
  
  digitalWrite(PRINT, HIGH);
  }
}
