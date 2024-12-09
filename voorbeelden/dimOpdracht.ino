const int COL1 = 4;    
const int COL2 = 7;  
const int COL3 = 3; 
const int COL4 = 6; 
const int COL5 = 10; 
const int ROW1 = 21;     
const int ROW2 = 22;  
const int ROW3 = 23;  
const int ROW4 = 24;  
const int ROW5 = 25;  
//void initMatrix();
const int kolomen[]={4,7,3,6,10};
void setup() {  

  initMatrix();
  delay(1000);
  analogWrite(ROW3,10);

}

void loop(){
}



void initMatrix() {
  for(int i=0;i < 5; i++) {
     pinMode(kolomen[i], OUTPUT);
  }
  pinMode(ROW1, OUTPUT);
  pinMode(ROW2, OUTPUT);
  pinMode(ROW3, OUTPUT);
  pinMode(ROW4, OUTPUT);
  pinMode(ROW5, OUTPUT);
  digitalWrite(COL1, HIGH); 
  digitalWrite(COL2, HIGH);
  digitalWrite(COL3, LOW);
  digitalWrite(COL4, HIGH);
  digitalWrite(COL5, HIGH); 

}
