void processSpecificCommand(char* data, char* paramValue, Print* output) {

  switch (data[0]) {
    case 'l':
      sleepNow();
      break;
  }
}

void printSpecificHelp(Print * output) {
  output->println(F("s(l)eep"));
}
