const int COL1 = 4;     // Column #1 control
const int LED = 21;     // 'row 1' led

void setup() {  
  Serial.begin(9600);
  
  Serial.println("microbit is ready!");

  // because the LEDs are multiplexed, we must ground the opposite side of the LED
  pinMode(COL1, OUTPUT);
  digitalWrite(COL1, LOW); 
   
  pinMode(LED, OUTPUT);   
}

void loop(){
  Serial.println("blink!");
  
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}