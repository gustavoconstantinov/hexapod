#ifndef HEXAPOD__STRUCTS_H
#define HEXAPOD__STRUCTS_H

typedef struct {
  double x;
  double y;
  double z;
} Vector3;

namespace Enum {
  enum MovementType {
    Standby,
    Front,
    Back,
    RotateLeft,
    RotateRight,
  };
}

#endif