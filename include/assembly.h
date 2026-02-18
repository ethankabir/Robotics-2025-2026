#pragma once

#include "vex.h"

using namespace vex;

class Assembly {
public:
    Assembly(
        mik::motor_group intake_motors,
        mik::piston piston
    );

    void init();
    void control();

    void intake_motors_control();
    void piston_control();

    mik::motor_group intake_motors;
    mik::piston piston;
};
