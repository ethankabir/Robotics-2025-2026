#include "vex.h"

using namespace vex;

// Pass in the devices we want to use
Assembly::Assembly(
    mik::motor_group intake_motors,
    mik::piston piston
) :
    // Assign the ports to the devices
    intake_motors(intake_motors),
    piston(piston)
{};

// Called once when user control starts
void Assembly::init() {
    // No background tasks needed for simple intake/piston
}

// Called every loop iteration in user control
void Assembly::control() {
    intake_motors_control();
    piston_control();
}

// Spins intake forward if R2 is held, reverse if L2 is held; stops otherwise
void Assembly::intake_motors_control() {
    if (Controller.ButtonR2.pressing()) {
        intake_motors.spin(fwd, 12, volt);
    } else if (Controller.ButtonL2.pressing()) {
        intake_motors.spin(fwd, -12, volt);
    } else {
        intake_motors.stop();
    }
}

// Toggle piston when Button A is pressed
void Assembly::piston_control() {
    if (btnA_new_press(Controller.ButtonA.pressing())) {
        piston.toggle();
    }
}
