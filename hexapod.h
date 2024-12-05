#pragma once

#ifndef HEXAPOD_H
#define HEXAPOD_H

#include "legs.h"
#include "hexapod_structs.h"
using namespace Enum;

class Hexapod {
public:
  Hexapod();
  void init();
private:
  Legs legs[6];
  void processMovement(MovementType mode);
  void setNexStep();
  MovementType _mode;
  int _movementIndex = 0;
};


#endif // Legs_H