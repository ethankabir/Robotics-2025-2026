/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       ethan                                                     */
/*    Created:      10/31/2025, 7:22:14 PM                                    */
/*    Description:  V5 competition bot                                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"


using namespace vex;


int main() {

    // Drive train handler 
    vexcodeInit();

    Brain.Screen.printAt( 10, 50, "Hello V5" );
   
    while(1) {
        
        // Pneumatics handler
        bool PistonActive = false;

        if(Controller1.ButtonR1.pressing())
        {
            PistonActive = !PistonActive;
        }
        
        if(PistonActive)
        {
            Piston.set(true);
        }
        else
        {
            Piston.set(false);
        }


        // Intake handler
        Intake1.setVelocity(100, pct);

        if(Controller1.ButtonA.pressing())
        {
            Intake1.spin(forward);
            Intake2.spin(forward);
        }

        if(Controller1.ButtonB.pressing())
        {
            Intake1.spin(reverse);
            Intake2.spin(reverse);
        }

        else 
        {
            Intake1.stop();
            Intake2.stop();
        }

        // Allow other tasks to run
        this_thread::sleep_for(10);
    }
}
