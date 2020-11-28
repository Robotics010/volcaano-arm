/*
  volcaano::motor - Library for controlling volcaano robot arm motors
  All rights reserved for Volcaano team
  Created initally by Kirill Mitkovskii, November 2, 2019
*/

#ifndef volcaano_motor_h
#define volcaano_motor_h

#include "Arduino.h"

namespace volcaano {

class Motor
{
    public:
        Motor();
        bool config();
        double read_position();
        void write_setpoint(double setpoint);
    private:

};

} // volcaano

#endif