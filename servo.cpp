#include "servo.h"
#include "constants_hexapod.h"

Servo::Servo(int legIndex, int initialPort) {
  _legIndex = legIndex;
  _port = initialPort;
  setPWM(legIndex);
}

void Servo::setPWM(int legIndex) {
  _pwmRight = Adafruit_PWMServoDriver(PCA9685_ADDRESS_1);
  _pwmLeft = Adafruit_PWMServoDriver(PCA9685_ADDRESS_2);
}

void Servo::initPWM() {
if (pwmInited)
      return;

  _pwmLeft.begin();
  _pwmLeft.setPWMFreq(FREQUENCY);
  _pwmRight.begin();  
  _pwmRight.setPWMFreq(FREQUENCY);

  if(_legIndex <= 3) {
    _pwm = &_pwmRight;
  }else {
    _pwm = &_pwmLeft; 
  }

  pwmInited = true;
}

void Servo::init() {
  initPWM();
}

void Servo::setAngle(double angle) {
  initPWM();
  _angle = angle;

  _pwm->setPWM(_port, 0, convertAngleToPulse(angle));
}

double Servo::getAngle() {
  return _angle;
}

int Servo::convertAngleToPulse(double angle) {
  int position = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  return position;
}
