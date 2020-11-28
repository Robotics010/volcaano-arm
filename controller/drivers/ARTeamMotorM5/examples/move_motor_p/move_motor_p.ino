#include <ARTeamMotorM5.h> // include the library for motor M5 control

void setup() {
  setupM5motor(); // configure pins required for motor control
  Serial.begin (9600);
  Serial.println("starting ARTeamMotorM5 move_motor_p example"); 
}

void loop() {
  float current_position = 0;
  float desired_position = 180; // we will move motor at this position
  float motor_power = 0;
  float Kp = 0.5;
  int setpoint_change_period = 500;   // every ~5 second
  while (true) {
    for (int i = 0; i <= setpoint_change_period-1; i++) {
      current_position = getM5position();
      motor_power = (desired_position-current_position)*Kp; // calculate motor control value
      moveM5motor(motor_power); // command motor to move towards desired_position
      // if power is > 100 or < -100 it will be constrained to [-100;+100] range anyway in the library
      delay(10);
  }
  desired_position *= -1; // change desired_pos to -desired_pos
  }
}
