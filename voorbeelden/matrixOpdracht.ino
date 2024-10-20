#include <Adafruit_Microbit.h>

Adafruit_Microbit_Matrix ledDisplay;  //definieer de led display

uint8_t led_matrix[] =
  { B00001, // bovenste rij met waarde 1.
    B00010,  //tweede rij  met waarde 2.
    B00100,  //derde rij  met waarde 4.
    8,       //vierde rij  met waarde B01000
    0x10,    //onderste rij met waarde B10000  of terwijl 16
  };

void setup() {
  ledDisplay.begin(); 
  ledDisplay.drawPixel(2, 3, 1);  // Zet de LED op positie (2, 3) aan.
  delay(2000);  
  ledDisplay.clear();  
  delay(2000);  
  ledDisplay.show(led_matrix);
}

void loop() {

}
