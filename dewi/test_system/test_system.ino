

#include "compass.h"
#include <Wire.h>
#include "utils.h"
#include "configure.h"

#define COMPASS
#define WIND_DIRECTION

#define WIND_SENSOR  A1

void setup(){

  Serial.begin(9600);
  Serial.println("Starting up");
#ifdef COMPASS
  Serial.println("Initialising Compass");
  delay(200);
  Compass.initialise(); 
#endif

#ifdef WIND_DIRECTION
  pinMode(WIND_SENSOR, INPUT);
#endif
}

void loop(){
  test_compass();
  test_windsensor();
}

void test_compass(){
#ifdef COMPASS
  Serial.println("\nReading compass");
  Compass.poll_data();
  Serial.print("Heading: ");
  Serial.println(Compass.get_bearing());
#endif
}

void test_windsensor(){
#ifdef WIND_DIRECTION
  Serial.print("\nWindsensor: ");
  Serial.println(analogRead(WIND_SENSOR));
#endif
}
