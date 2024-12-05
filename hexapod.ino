#include <Adafruit_PWMServoDriver.h>
#include "constants_hexapod.h"
#include <math.h>
#include "hexapod.h"
#include "hexapod_structs.h"

using namespace Enum;

Hexapod hexapod;

static int mode = Enum::Standby;

unsigned long previousMillis = 0; // Tempo da última execução da ação
const unsigned long intervalMillis = 200; // min 200

void setup() {

  //hexapod.init();
  previousMillis = millis(); 
}

void loop() {
  unsigned long currentMillis = millis(); // Obtém o tempo atual
 
  if (currentMillis - previousMillis >= intervalMillis) {
    previousMillis = currentMillis;
    hexapod.init(); 
  }
}

