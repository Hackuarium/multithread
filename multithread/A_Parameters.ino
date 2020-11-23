/*********************************************
   This file is used to declare the parameters
   table used by the program.

   We use the EEPROM for saving the parameters
   changed by the user during the functionment
   of the Bioreactor.

   The parameter are loaded during the boot.

   All change to important parameters are saved
   to the EEPROM
 *********************************************/

// define parameters that are index in the parameters array. 

#define PARAM_COLOR_1 0
#define PARAM_COLOR_2 1
#define PARAM_COLOR_3 2
#define PARAM_COLOR_4 3
#define PARAM_COLOR_5 4

#define PARAM_BATTERY 18      // battery voltage (hundredths of volt)
#define PARAM_TEMPERATURE 19  // temperature (hundredths of degree)
#define PARAM_CHARGING 20     // battery charging



void resetParameters() {
  setAndSaveParameter(PARAM_COLOR_1, 2);
  setAndSaveParameter(PARAM_COLOR_2, 10);
  setAndSaveParameter(PARAM_COLOR_3, 10);
}

void checkParameters() {
  if (getParameter(PARAM_COLOR_1) < 0) {
    resetParameters();
  }
}
