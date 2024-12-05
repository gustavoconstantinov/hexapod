#ifndef LEGS_H
#define LEGS_H

#include "servo.h"
#include "hexapod_structs.h"

class Legs {
  private:
    Servo servos[3];
    void _inverseKinematics(Vector3 position, double angles[3]);
  public:
    Legs(int legIndex, int initialPort);
    void move(Vector3 position);
};

#endif // Legs_H