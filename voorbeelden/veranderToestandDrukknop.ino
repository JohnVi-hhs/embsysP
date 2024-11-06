const int COL1 = 4; 
const int ROW1 = 21;
const int knopA = 5;     // Knop A is aangesloten op poortnummer 5
const int knopB = 11;    // Knop B is aangesloten op poortnummer 11

boolean isKnopIngedrukt(int);

int knopTeller = 0;  
boolean knopToestand = false;
boolean vorigeKnopToestand = false;
int ledStatus = LOW;

void setup() {  
  Serial.begin(9600);
  Serial.println("microbit is ready!");
  pinMode(COL1, OUTPUT);
  pinMode(ROW1, OUTPUT);
  pinMode(knopA, INPUT);  
  pinMode(knopB, INPUT);   
}

void loop(){
  knopToestand = isKnopIngedrukt(knopA);
  if(knopToestand != vorigeKnopToestand)  //heeft er een verandering plaatsgevonden?
        if (knopToestand == true) {
            knopTeller++;
            ledStatus = !ledStatus;
            Serial.println(knopTeller);
        }
   delay(50);
   vorigeKnopToestand = knopToestand;
   digitalWrite(ROW1, ledStatus);
}

boolean isKnopIngedrukt( int knop) {
    if (! digitalRead(knop)) {  //Is de knop soms ingedrukt ?
           delay(2);      //wacht 2 milliseconde 
           if (! digitalRead(knop)) { //Is knop nog steeds ingedrukt
                return true;
           }
    }
    return false;
}
