#include "ColorSensor.h"
#include "Clock.h"
#include "Walker.h"
#include "pid.h"

using namespace ev3api;

class PidWalker {
public:
  PidWalker();
  void trace();

private:
  Walker walker;
  ColorSensor colorSensor;
  Clock clock;
  Pid pid;
  int8_t forward = 20;
  int8_t turn = 0;
};
