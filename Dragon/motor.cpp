/*
 * @Author: XHM
 * @Date: 2020-10-10 12:26:44
 * @LastEditTime: 2020-11-01 13:46:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Dragon\motor.cpp
 */
#include "motor.h"

motor::motor(u8 _le, u8 _re, u8 _l1, u8 _l2, u8 _r1, u8 _r2)
: le(_le), re(_re), l1(_l1), l2(_l2), r1(_r1), r2(_r2)
{
    pinMode(l1, OUTPUT);
    pinMode(l2, OUTPUT);
    pinMode(r1, OUTPUT);
    pinMode(r2, OUTPUT);

    brake();
}

void motor::wait()
{
    analogWrite(le, 0);
    analogWrite(re, 0);
}

void motor::forward(u8 l_speed, u8 r_speed)
{
    Serial.println("forw");
    analogWrite(le, l_speed);
    analogWrite(re, r_speed);
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
}

void motor::backward()
{
    Serial.println("back");
    analogWrite(le, ANALOG_MAX);
    analogWrite(re, ANALOG_MAX);
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
}

void motor::turn_left(u8 speed)
{
    Serial.println("left");
    analogWrite(le, speed-30);
    analogWrite(re, speed);
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
}

void motor::turn_right(u8 speed)
{
    Serial.println("right");
    analogWrite(le, speed);
    analogWrite(re, speed-30);
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
}

void motor::brake()
{
    Serial.println("brake");
    analogWrite(le, 255);
    analogWrite(re, 255);
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
}
