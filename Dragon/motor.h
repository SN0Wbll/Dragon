/*
 * @Author: XHM
 * @Date: 2020-10-10 12:26:35
 * @LastEditTime: 2020-10-13 07:55:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Dragon\motor.h
 */
#ifndef MOTOR
#define MOTOR

#include "Interface.h"

class motor
{
    u8 le;
    u8 l1;
    u8 l2;
    u8 re;
    u8 r1;
    u8 r2;
    
public:
    // 构造函数，初始化引脚
    motor(u8 le, u8 re, u8 l1, u8 l2, u8 r1, u8 r2);
    
    void wait();
    void forward(u8 l_speed, u8 r_speed);
    void backward();
    void turn_left(u8 speed);
    void turn_right(u8 speed);
    void brake();
};

#endif // !MOTOR
