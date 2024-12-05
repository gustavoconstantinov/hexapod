#include "hexapod.h"
#include "constants_hexapod.h"
#include "servo.h"
#include "hexapod_structs.h"
#include "movement.h"

Hexapod::Hexapod() :
legs { Legs(1, 0), Legs(2, 4), Legs(3, 8), Legs(4, 12), Legs(5, 8), Legs(6, 0) }, _movementIndex(0)
{
}

const Vector3 standby[1][6] = {
  {
    { 0.0, 0.0, 0 }, { 0.0, 0.0, 0 }, { 0.0, 0.0, 0 },
    { 0.0, 0, 0 }, { 0.0, 0.0, 0 }, { 0, 0.0, 0 }
  }
};

const Vector3 walk[][6] = {
  {
    { 0, 0, 50 }, { 0, 0, 0 }, { 0, 0, 50 }, // Levantar impar
    { 0, 0, 0 }, { 0, 0, 50 }, { 0, 0, 0 }
  },
  {
    { -50, 0, 50 }, { 50, 0, 0 }, { -50, 0, 50 }, // Mover impar e par -50 e 50
    { 50, 0, 0 }, { -50, 0, 50 }, { 50, 0, 0 }
  },
  {
    { -50, 0, 0 }, { 50, 0, 0 }, { -50, 0, 0 }, // Abaixar pata impar
    { 50, 0, 0 }, { -50, 0, 0 }, { 50, 0, 0 }
  },
  {
    { -50, 0, 0 }, { 50, 0, 50 }, { -50, 0, 0 }, // Levantar pata par
    { 50, 0, 50 }, { -50, 0, 0 }, { 50, 0, 50 }
  },
  {
    { 0, 0, 0 }, { 0, 0, 50 }, { 0, 0, 0 }, // Mover pata impar e par 0 e 0
    { 0, 0, 50 }, { 0, 0, 0 }, { 0, 0, 50 }
  },
  {
    { 50, 0, 0 }, { -50, 0, 50 }, { 50, 0, 0 }, // Mover pata impar e par 50 e -50
    { -50, 0, 50 }, { 50, 0, 0 }, { -50, 0, 50 }
  },
  {
    { 50, 0, 0 }, { -50, 0, 0 }, { 50, 0, 0 }, // Abaixar pata par
    { -50, 0, 0 }, { 50, 0, 0 }, { -50, 0, 0 }
  },
   {
    { 50, 0, 50 }, { -50, 0, 0 }, { 50, 0, 50 }, // Levantar pata impar
    { -50, 0, 0 }, { 50, 0, 50 }, { -50, 0, 0 }
  },
};


void Hexapod::processMovementStandby(MovementType mode) {
  for (int legIndex = 0; legIndex < 6; legIndex++) {
    legs[legIndex].move(standby[_movementIndex][legIndex]); // Move o servo motor para a posição standBy    
  }

  setNexStep();
}


void Hexapod::setNexStepStandby() {
  int numRows = sizeof(standby) / sizeof(standby[0]);

  if(_movementIndex == numRows - 1) {
    _movementIndex = 0;  
  }else {
    _movementIndex+=1;
  }
}

void Hexapod::processMovementWalk(MovementType mode) {
  for (int legIndex = 0; legIndex < 6; legIndex++) {
    legs[legIndex].move(walk[_movementIndex][legIndex]); // Move o servo motor para a posição standBy    
  }

  setNexStep();
}


void Hexapod::setNexStepWalk() {
  int numRows = sizeof(walk) / sizeof(walk[0]);

  if(_movementIndex == numRows - 1) {
    _movementIndex = 0;  
  }else {
    _movementIndex+=1;
  }
// }

void Hexapod::init() {
  _mode = Enum::Standby;
  processMovement(_mode);
}



