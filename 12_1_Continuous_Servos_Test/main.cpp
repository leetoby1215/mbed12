#include "mbed.h"
#define CENTER_BASE 1500

PwmOut servo(D11);

void servo_control(int speed) {
    if (speed > 1000)
        speed = 1000;
    else if (speed < -1000)
        speed = -1000;

    servo = (CENTER_BASE + speed) / 20000.0f;
}

int main() {
    servo.period(.02);

    while(1) {
        servo_control(1000);
        wait(2);
        servo_control(-1000);
        wait(2);
    }
}