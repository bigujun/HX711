#include "HX711.h"

// HX711.DOUT	- pin #A1
// HX711.PD_SCK	- pin #A0

#define CHANNEL_A 128
//#define CHANNEL_A 64
#define CHANNEL_B 32
#define CALIBRATION_A 9650.f
#define CALIBRATION_B 2280.f

HX711 scale(A1, A0);		// parameter "gain" is ommited; the default value 128 is used by the library


void setup() {

  Serial.begin(38400);
  Serial.println("HX711 Multi channel Demo");

  Serial.println("CHANNEL A:");
  scale.set_gain(CHANNEL_A);
  Serial.print("read average: \t\t");
  Serial.println(scale.read_average());

  scale.set_scale(CALIBRATION_A);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();				        // reset the scale to 0

  Serial.println("CHANNEL B:");
  scale.set_gain(CHANNEL_B);
  Serial.print("read average: \t\t");
  Serial.println(scale.read_average());

  scale.set_scale(CALIBRATION_B);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();
}

void loop() {
  scale.set_gain(CHANNEL_A);
  Serial.print("CHANNEL A:\t");
  Serial.print(scale.get_units(5), 3);
  Serial.print(" Kg");

  scale.set_gain(CHANNEL_B);
  Serial.print("CHANNEL B:\t");
  Serial.print(scale.get_units(5), 3);
  Serial.print(" Kg");


  scale.power_down();			        // put the ADC in sleep mode
  delay(2000);
  scale.power_up();
}
