#include "Walker.h"

Walker::Walker():
    leftWheel(PORT_C), rightWheel(PORT_B) {
}

void Walker::init() {
    init_f("Walker");
}

void Walker::terminate() {
    msg_f("Stopped.", 1);
    leftWheel.stop();
    rightWheel.stop();
}

void Walker::reset() {
    leftWheel.reset();
    rightWheel.reset();
}

void Walker::run(int8_t pwm, int8_t turn) {
    msg_f("running...", 1);

    /* left = p-t, right = p+t -> 左 */
    /* left = p+t, right = p-t -> 右 */
    leftWheel.setPWM(pwm - turn);
    rightWheel.setPWM(pwm + turn);
}
