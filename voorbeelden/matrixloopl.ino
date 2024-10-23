#include <Adafruit_Microbit.h>

Adafruit_Microbit_Matrix matrixMbit; //maak een LED matrix aan.

uint8_t matrixje[] =
  { B00000,
    B00000,
    B00000,
    B00000,
    B00000, };

void setup() {
  Serial.begin(9600);
  Serial.println("Welkom bij embedded!");

  matrixMbit.begin();
  matrixMbit.show(matrixje);
  delay(1000);  
}

uint8_t nr=0;
uint8_t hulpje;
  
void loop() {

   hulpje = 1 << nr; //schuif 1 nr plaatsen op naar links.
   matrixje[0]=hulpje; //De bovenste rij van de matrix krijgt de 
   matrixMbit.show(matrixje);
   delay(1000);
   nr++;
   if (nr == 5) {
          nr=0;
   }        
}
