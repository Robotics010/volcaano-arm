#include <ARTeamMotorM5.h> // include the library for motor M5 control

void setup() {
  setupM5motor(); // configure pins required for motor control
  Serial.begin (9600);
  Serial.println("starting ARTeamMotorM5 rotate_motor_10_times example"); 
}

void loop() {
  float step = 360; // we will move motor by 1 rotation
  int times = 10;   // every 10 times
  
  for (int i = 0; i <= times-1; i++) {
    moveM5motor(50); // command motor to move forward with 50% of maximum power
    // pos = getM5position(); // !PROBLEM! pos is equal zero instead of result of getM5position()
    while (getM5position() < step) {
      Serial.println(getM5position()); // print current motor position
      delay(1);
      }
    moveM5motor(0); // stop motor
    resetM5position(); // reset motor position to 0
  }
  
  while (true) {delay(1);} // and wait forever
}
