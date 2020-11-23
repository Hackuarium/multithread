
#define SOFTWARE_VERSION "v0.0.0"

#define BLINK_LED 8

#define THR_SERIAL 1

#define I2C_HARDWARE 1
#define SDA_PIN 1
#define SDA_PORT PORTD
#define SCL_PIN 0
#define SCL_PORT PORTD
#define I2C_FASTMODE 1

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
