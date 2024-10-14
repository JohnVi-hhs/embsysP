const int COL1 = 4;     // Column #1 control
const int LED = 21;     // 'row 1' led

void setup() {  

  pinMode(COL1, OUTPUT);
  digitalWrite(COL1, LOW); 
  pinMode(LED, OUTPUT);   
}

void loop(){
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}