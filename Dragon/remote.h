/*
 * @Author: your name
 * @Date: 2020-10-10 15:45:14
 * @LastEditTime: 2020-10-19 20:35:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Dragon\remote.h
 */
#ifndef REMOTE
#define REMOTE

#include "motor.h"
#include "Interface.h"
#include "Servo.h"

class remote
{
    motor &control;
    Servo &shootgun;
    u8 shoot_pin;
    void (*signal)();
    void fire();
    
public:
    remote(motor &_control, Servo &shoot_gun, void (*)());
    // 启动遥控模式
    void mode();
};






#endif // !REMOTE