int teller=0;
void setup() {  
  Serial.begin(9600);
  
  Serial.println("microbit is ready1!");
  
  // pinMode(PIN_BUTTON_A, INPUT);
  // pinMode(PIN_BUTTON_B, INPUT);
}

void loop(){
if(!Serial) {  //check if Serial is available... if not,
Serial.end();      // close serial port
delay(100);        //wait 100 millis
Serial.begin(9600); // reenable serial again
}
  // if (! digitalRead(PIN_BUTTON_A)) {
  //   Serial.println("Button A pressed");
  // }
  // if (! digitalRead(PIN_BUTTON_B)) {
  //   Serial.println("Button B pressed");
  // }
  Serial.println(teller);
  teller++;
  delay(1000);
}
