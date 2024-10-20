
void setup() {
  Serial.begin(9600);
  Serial.println("start");
}
int teller=0;

void loop() {
  Serial.println(teller);
  delay(1000);
  teller++;
}

