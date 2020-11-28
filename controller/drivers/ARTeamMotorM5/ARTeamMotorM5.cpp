/*
  ARTeamMotorM5.cpp - Library for controlling M5 motor.
  Created by Kirill Mitkovskii, November 2, 2019.
  Released privately for ARTeam team members only.
*/
#include "Arduino.h"
#include "math.h"
#include "ARTeamMotorM5.h"

volatile int ART_M5_Pos;
volatile bool ART_M5_Dir;

extern void setupM5motor() {
	ART_M5_Pos = 0;
	ART_M5_Dir = false;
	pinMode (ART_M5_EncPin, INPUT);
	digitalWrite(ART_M5_EncPin, HIGH);       // turn on pull-up resistor
	attachInterrupt(ART_M5_IntNum, handleM5Int, CHANGE);  // encoder pin on M5_IntNum interrupt
	pinMode (ART_M5_DirPin, OUTPUT);
}

extern float getM5position() {
	float ART_M5_Pos_deg = (float)ART_M5_Pos * 360.0 / 1692.0;
    return ART_M5_Pos_deg;
}

extern void resetM5position() {
    ART_M5_Pos = 0;
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

extern void moveM5motor(float power) {
  //float pwmvalue;
  int pwmvalue;
  bool pwmdir;
  if (power == 0.0) {
    pwmvalue = 255.0;
    pwmdir = false;
  }
  else {
	power = constrain(power, -100.0, 100.0);  // limits range of motoro control value between -100 and 100
    pwmdir = power > 0.0;
    power = abs(power);
    //pwmvalue = map(power, 0, 100, 255, 0);
	pwmvalue = mapfloat(power, 0.0, 100.0, 255.0, 0.0);
	//pwmvalue = (-power * 255.0) / 100.0 + 255.0;
  }
  
  digitalWrite(ART_M5_DirPin, pwmdir);
  ART_M5_Dir = pwmdir;
  analogWrite(ART_M5_PwmPin,pwmvalue); // 127 = 50% of Speed Power (0 -> 100%, 255 -> 0%)
}

extern void handleM5Int() {
  /*
     If ART_M5_Dir is true it spinning forward
     If ART_M5_Dir is false it's going backward.
  */
    if (ART_M5_Dir) ART_M5_Pos++; else ART_M5_Pos--;
	//Serial.println(ART_M5_Pos);
}