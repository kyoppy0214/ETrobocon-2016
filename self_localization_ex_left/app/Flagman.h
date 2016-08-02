#include "TouchSensor.h"
#include "Clock.h"

using namespace ev3api;

class Flagman {
public:
  Flagman();
  void startingWait();

private:
  TouchSensor touchSensor;
  Clock clock;
};
