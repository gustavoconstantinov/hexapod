#include "movement.h"


Movement::Movement(
  Vector3 right_1, 
  Vector3 right_2, 
  Vector3 right_3, 
  Vector3 left_1, 
  Vector3 left_2, 
  Vector3 left_3) : 
_positions{right_1, right_2, right_3, left_1, left_2, left_3}{}
