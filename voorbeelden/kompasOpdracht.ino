
#include <Adafruit_Microbit.h>
#include <LSM303AGR_MAG_Sensor.h>

#define DEV_I2C Wire1  

const int ROW3 = 23;        
const int COL3 = 3; 
const float Pi = 3.14159;
//const int leveled = 160;  

void kalibreer();
float bepaalHoek();

LSM303AGR_MAG_Sensor Mag(&DEV_I2C);
Adafruit_Microbit microbit;

int32_t magnetometer[3];

int32_t x, MagMinX, MagMaxX;
int32_t y, MagMinY, MagMaxY;
int32_t z, MagMinZ, MagMaxZ;

boolean calibrated = false;
long lastDisplayTime;


void setup(void) {
  // Start LED matrix driver
  pinMode(ROW3, OUTPUT);
  pinMode(COL3, OUTPUT);
  digitalWrite(COL3, LOW);

  // Initialiseer I2C bus.
  DEV_I2C.begin();

  Mag.begin();
  Mag.Enable();

  Serial.begin(9600);
  pinMode(PIN_BUTTON_A, INPUT);
 // Serial.println("Druk op knopA om te stoppen met kalibreren");

  Serial.println("");
  lastDisplayTime = millis();
  kalibreer();
}

void loop(void) {
  float hoek;
  hoek=bepaalHoek();
  if ((millis() - lastDisplayTime) > 1000)  {
     Serial.print("ondergrens:");
     Serial.print(-0.5);
     Serial.print(",");
     Serial.print("Bovengrens:");
     Serial.print(361);
     Serial.print(",");
     Serial.print("Hoek:");
     Serial.println(hoek);
     lastDisplayTime = millis();
}
  delay(10);
}

void kalibreer() {
   while (digitalRead(PIN_BUTTON_A)) {
        Mag.GetAxes(magnetometer);   // Used for compass
         x = magnetometer[0];
         y = magnetometer[1];
         z = magnetometer[2];

         if (x < MagMinX) MagMinX = x;
         if (x > MagMaxX) MagMaxX = x;

         if (y < MagMinY) MagMinY = y;
         if (y > MagMaxY) MagMaxY = y;

         if (z < MagMinZ) MagMinZ = z;
        if (z > MagMaxZ) MagMaxZ = z;
    }
    digitalWrite(ROW3, HIGH );
}

float bepaalHoek() {
  float heading;

  Mag.GetAxes(magnetometer);   // gebruik van kompas
  x = magnetometer[0];
  y = magnetometer[1];
  z = magnetometer[2];

  // Change the calibrated values to an expected range.
  x = map(x, MagMinX, MagMaxX, -1023, 1023);
  y = map(y, MagMinY, MagMaxY, -1023, 1023);
  z = map(z, MagMinZ, MagMaxZ, 0, 1023);

   // bereken de hoek aan de hand van y en x
    heading = (atan2(y, x) * 180) / Pi;
  
  if (heading < 0) {
    heading += 360;
  }
  return heading;

}
