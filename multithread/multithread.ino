
#define SOFTWARE_VERSION "v1.1.6"

// VERSION
// *******
// version 2 B : <1.4 temperature sensor and battery indicator
// version 3 C : 1.4 same as B
// version 4 D : 1.6 need to enable LCD (pin 13) and temperature / light sensor: PE2
// version 5 E : 2.0 introduce I2C component for led control

#define VERSION 4

#define LANGUAGE en // currently only en or es

#define RED A0
#define GREEN A1
#define BLUE A2
#define UV1 A4 // 5mm

#if VERSION >= 2
#define BATTERY A3 // if battery we have also the temperature sensor
#define TEMPERATURE_ADDRESS 0b1001000
#endif

#if VERSION >= 4
#define POWER_ON_DSL237 \
  PORTE |= 1 << PE2;    \
  DDRE |= 1 << PE2;     \
  nilThdSleepMilliseconds(10);
#define POWER_OFF_DSL237 PORTE &= ~(1 << PE2);
#define BATTERY_CHARGING A5
#endif

#define DATA_SIZE 240

#define BATTERY_LEVEL 128 // not available in version A
#define TEMPERATURE 129   // not available in version A

#if VERSION == 1
byte ALL_PARAMETERS[] = {RED, GREEN, BLUE, UV1}; // all possible leds
#else
byte ALL_PARAMETERS[] = {RED, GREEN, BLUE, UV1, TEMPERATURE, BATTERY_LEVEL}; // all possible leds
#endif
#define TOTAL_NUMBER_LEDS 4

byte ACTIVE_PARAMETERS[sizeof(ALL_PARAMETERS)];

byte nbLeds;       // number of active leds
byte nbParameters; // number of parameters to record
byte dataRowSize;  // size of a data row (number of entries in data)
byte maxNbRows;    // calculate value depending the size of EEPROM dedicated to logs

#define THR_SERIAL 1

#define I2C_TIMEOUT 10
#if VERSION == 5
#define I2C_HARDWARE 0
#define SDA_PIN 7
#define SDA_PORT PORTF
#define SCL_PIN 6
#define SCL_PORT PORTF
#define I2C_FASTMODE 0
#else
#define I2C_HARDWARE 1
#define SDA_PIN 1
#define SDA_PORT PORTD
#define SCL_PIN 0
#define SCL_PORT PORTD
#define I2C_FASTMODE 1
#endif

#define THR_WIRE_MASTER 1
#define MAX_PARAM 26

#include "libino/hack.h"

void setup()
{
  setupParameters();
  checkParameters(); // setup automatically the default parameter after install boot loader
  nilSysBegin();
}

void loop() {}
