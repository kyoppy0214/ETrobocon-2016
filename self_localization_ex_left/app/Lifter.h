#include "Motor.h"
#include "Clock.h"

#include "util.h"

using namespace ev3api;

class Lifter {
public:
  Lifter();
  void liftUp();
  void liftDown();
  void defaultSet();
  void init();
  void terminate();
  void reset();

private:
  Motor liftHand;
  Clock clock;
};
