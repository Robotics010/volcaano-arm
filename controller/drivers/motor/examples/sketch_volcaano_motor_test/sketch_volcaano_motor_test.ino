#include <motor.h>

volcaano::Motor motor_base = volcaano::Motor();

void setup() {
  // put your setup code here, to run once:
motor_base.config();
}

void loop() {
  // put your main code here, to run repeatedly:
motor_base.read_position();
}
