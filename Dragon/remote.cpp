/*
 * @Author: your name
 * @Date: 2020-10-10 15:45:26
 * @LastEditTime: 2020-10-31 20:23:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Dragon\remote.cpp
 */
#include "remote.h"
#include "Timerone.h"

remote::remote(motor &_control, Servo &shoot_gun, void sig()) : control(_control), shootgun(shoot_gun), signal(sig)
{
    Order = wait;
    //shootgun.attach(11);
}

void remote::fire()
{
    Timer1.detachInterrupt();
    shootgun.attach(4);
    shootgun.write(80);
    delay(150);
    
    shootgun.write(0);
    delay(170);
    shootgun.detach();
    Timer1.attachInterrupt(signal, 50000);
}

static int SPEED = ANALOG_MAX + 10;

void remote::mode()
{
    Order = wait;
    Serial.println(Modes);
    
    while (Modes == REMOTE_FLAG) {
        switch (Order) {
        case forward:
            control.forward(SPEED, SPEED);
            break;

        case backward:
            control.backward();
            break;

        case left:
            control.turn_left(SPEED + 15);
            break;

        case right:
            control.turn_right(SPEED + 15);
            break;

        case brake:
            control.brake();
            break;

        case shoot:
            fire();
            break;
        case up:
            SPEED += 5;
            break;
        case down:
            SPEED -= 5;
            break;
        }

        Order = wait;
        delay(50);
    }
} 
