/*
  motor - Library for controlling volcaano robot arm motors
  All rights reserved for Volcaano team
  Created initally by Kirill Mitkovskii, November 2, 2019
*/

#include "Arduino.h"

#include "math.h"

#include "motor.h"

namespace volcaano {

Motor::Motor()
{
  Serial.println("motor constructor");
}

bool Motor::config() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("motor cong");
    return true;
}
double Motor::read_position() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  Serial.println("read pos");
    return 0.0;
}
void Motor::write_setpoint(double setpoint) {
    
}

} // volcaano