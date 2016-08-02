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
    leftWheel.setPWM(pwm - turn * leftRight);
    rightWheel.setPWM(pwm + turn * leftRight);
}

int8_t Walker::edgeChange() {
    /*
     * 一見どっちも同じに見えるけど、なぜかこれで成功した。
     */
    if(leftRight == 1) {
        run(10, 5);
        clock.sleep(20);
        leftRight = -1;
    } else {
        run(10, 5);
        clock.sleep(20);
        leftRight = 1;
    }
    
    return leftRight;
}

int32_t Walker::get_count_L()
{
    return leftWheel.getCount();
}
int32_t Walker::get_count_R()
{
    return rightWheel.getCount();
}