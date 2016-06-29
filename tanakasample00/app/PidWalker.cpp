#include "ev3api.h"
#include "ColorSensor.h"
#include "Clock.h"

#include "PidWalker.h"

/* default pid(2.0, 0.05, 0.13, 20.0) */
PidWalker::PidWalker():
    colorSensor(PORT_2), pid(1.0, 0.0, 0.3, 30.0) {
}

void PidWalker::trace() {

    /* 両輪のリセット */
    walker.reset();

    while(1) {
        if(ev3_button_is_pressed(BACK_BUTTON)) {
            break;
        }

        pid.pid_calculate(colorSensor.getBrightness());
        turn = (int8_t)pid.pid_get_output();

        walker.run(forward, turn);

        clock.sleep(4); /* 4msec周期起動 */
    }

    walker.reset();
}
