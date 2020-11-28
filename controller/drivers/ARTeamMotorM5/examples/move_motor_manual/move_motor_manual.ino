#include <ARTeamMotorM5.h> // include the library for motor M5 control

void setup() {
  setupM5motor(); // configure pins required for motor control
  Serial.begin (9600);
  Serial.println("starting ARTeamMotorM5 move_motor_manual example"); 
}

void loop() {
  while (Serial.available() == 0);
  int val = Serial.parseInt(); //read int or parseFloat for ..float...
  Serial.println(val);
  moveM5motor(val); // command motor to move forward with 50% of maximum power
  // if power is > 100 or < -100 it will be constrained to [-100;+100] range anyway in the library
}
