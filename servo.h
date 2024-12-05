#ifndef SERVO_H
#define SERVO_H

#include <Adafruit_PWMServoDriver.h>

class Servo
{
  public:
    Servo(int legIndex, int initialPort);
  public: 
    void setAngle(double angle);
    double getAngle();
    void init(void);
  private:
    double _angle;
    Adafruit_PWMServoDriver* _pwm;
    int _port;
    bool pwmInited = false;
    Adafruit_PWMServoDriver _pwmLeft;
    Adafruit_PWMServoDriver _pwmRight;
    int _legIndex;
  private:
    void initPWM();
    void setPWM(int legIndex);
    int convertAngleToPulse(double angle);
};

#endif // SERVO_H