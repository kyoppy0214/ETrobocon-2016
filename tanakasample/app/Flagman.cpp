#include "Flagman.h"

#include "app.h"

Flagman::Flagman():
    touchSensor(PORT_1) {
}

void Flagman::startingWait() {
    int8_t bt_cmd = 0;

    while (1) {
        if(bt_cmd == 1) {
            break;
        }
        if(touchSensor.isPressed()) {
            break;
        }

        clock.sleep(20);
    }
}

