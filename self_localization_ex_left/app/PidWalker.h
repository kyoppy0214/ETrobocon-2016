#include "ColorSensor.h"
#include "Clock.h"
#include "Walker.h"
#include "pid.h"
#include "self_localization.h"

using namespace ev3api;

class PidWalker {
public:
  PidWalker();
  void trace();

private:
  Walker walker;
    Self_localization self_localization;
  ColorSensor colorSensor;
  Clock clock;
  Pid pid;
  int8_t forward = 20;
  int8_t turn = 0;
};
