#include <avr/sleep.h>
void sleepNow () {
  // more information about sleep: https://www.nongnu.org/avr-libc/user-manual/group__avr__sleep.html

  noInterrupts ();          // make sure we don't get interrupted before we sleep
  wdt_disable();
  sleep_enable ();          // enables the sleep bit in the mcucr register
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);

  nilThdSleepMilliseconds(2);  // smll debouncing
 // attachInterrupt (digitalPinToInterrupt (ROT_B), empty, CHANGE);

  interrupts ();           // interrupts allowed now, next instruction WILL be executed
  sleep_cpu ();            // here the device is put to sleep

  sleep_disable ();         // first thing after waking from sleep:
 // detachInterrupt (digitalPinToInterrupt (ROT_B));      // stop LOW interrupt on D2
  wdt_enable(WDTO_8S);  //reactivate the watchdog
}

void empty() {}
