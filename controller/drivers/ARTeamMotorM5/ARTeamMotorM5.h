/*
  ARTeamMotorM5.h - Library for controlling M5 motor.
  Created by Kirill Mitkovskii, November 2, 2019.
  Released privately for ARTeam team members only.
*/
#pragma once

#include "Arduino.h"

#define ART_M5_EncPin  2 // M5 Feedback connected to digital pin 2 (yellow)
#define ART_M5_IntNum  0 // M5 Feedback interrupt is digital pin 2 (yellow)
#define ART_M5_DirPin 22 // M5 Direction connected to digital pin 22 (orange)
#define ART_M5_PwmPin  4 // M5 PWM Speed connected to digital pin 4 (white)

extern void setupM5motor();
extern float getM5position();
extern void resetM5position();
extern void moveM5motor(float power);

extern void handleM5Int();