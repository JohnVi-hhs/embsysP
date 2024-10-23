#include <LSM303AGR_ACC_Sensor.h>


#define DEV_I2C Wire1   // Wire1 is voor de interne I2C bus 
#define LED ROW1 


// Nodig voor de accelerator 
LSM303AGR_ACC_Sensor Acc(&DEV_I2C);


const int COL1 = 4;   
const int ROW1 = 21;   

void setup() {
  // Led.
 
  pinMode(COL1, OUTPUT);
  digitalWrite(COL1, LOW);
  pinMode(ROW1, OUTPUT);

  
  // Initialisatie van de serieele.
  Serial.begin(9600);
  
  // Initialisate I2C bus (wordt veel gebruikt om sensors).
  DEV_I2C.begin();

  // Initialisatie van de accelarator.
  Acc.begin();
  Acc.Enable();

  uint8_t a;
  Acc.IO_Read(&a,0x0F,1);
  Serial.print("Ik ben: ");
  Serial.println(a);
}

void loop() {
  // Led blinking.
  digitalWrite(LED, HIGH);
  delay(250);
  digitalWrite(LED, LOW);
  delay(250);

  // Lees de accelerometer van de LSM303AGR uit.
  int32_t accelerometer[3];
  Acc.GetAxes(accelerometer);

  // Output data.
  Serial.print("| Acc[x/y/z] ");
  Serial.print(accelerometer[0]);
  Serial.print(" ");
  Serial.print(accelerometer[1]);
  Serial.print(" ");
  Serial.print(accelerometer[2]);
  Serial.println(" |");
}
