#pragma once

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "hexapod_structs.h"

class Movement
{
  public:
    Movement(Vector3 right_1, Vector3 right_2, Vector3 right_3, Vector3 left_1, Vector3 left_2, Vector3 left_3);
  private:
    Vector3 _positions[6];
};
#endif // MOVEMENT_H