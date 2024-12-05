#include "movement.h"

const Movement standby[] {
  Movement({ 0.0 , 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0}, { 0.0, 0.0, 0.0 } , { 0.0, 0.0, 0.0 })
};

const Movement& standBy() {
  return standby;
}

const Movement& front() {
  return front;
}

const Movement& back() {
  return back;
}

const Movement& rotateLeft() {
  return rotate_left;
}

const Movement& rotateRight() {
  return rotate_rightft;
}

const Movement MovementList[] = {
  standBy(),
  front(),
  back(),
  rotateLeft(),
  rotateRight()
};