//#include "HardwareSerial.h"
#include "legs.h"
#include "constants_hexapod.h"
#include "hexapod_structs.h"
#include <math.h>
#include "servo.h"

Legs::Legs(int legIndex, int initialPort) : 
servos { Servo(legIndex, initialPort), Servo(legIndex, initialPort + 1), Servo(legIndex, initialPort + 2)} {

}

void Legs::move(Vector3 position) {
  double angles[3];

  _inverseKinematics(position, angles);

  for(int i = 0; i < 3; i++) {
    servos[i].setAngle(angles[i]);
  }
}

void Legs::_inverseKinematics(Vector3 position, double angles[3]) {

  double X = position.x;
  double Y = position.y + Y_REST;
  double Z = position.z + Z_REST;

  double L = sqrt(pow(Y, 2) + pow(Z, 2));
  double L_term = (pow(L, 2) + pow(FEMUR, 2) - pow(TIBIA, 2)) / (2 * L * FEMUR);

  if(L_term < -1 || L_term > 1) {
    Serial.println("Erro: argumento inválido para acos de L_Term\n");
  }

  double B = acos(L_term);
  double A = atan(Z / Y);
  double J1 = atan(X / Y) * (180 / M_PI);
  double J2 = (B + A) * (180 / M_PI);
  double L_term2 = (pow(FEMUR, 2) + pow(TIBIA, 2) - pow(L, 2)) / (2 * FEMUR * TIBIA);

   if(L_term2 < -1 || L_term2 > 1) {
    Serial.println("Erro: argumento inválido para acos de L_Term2\n");
  }

  double J3 = (acos(L_term2) * (180 / M_PI));

  angles[0] = (90 - J1);
  angles[1] = (90 - J2);
  angles[2] = (J3 + J3_offsetting - 90);
}