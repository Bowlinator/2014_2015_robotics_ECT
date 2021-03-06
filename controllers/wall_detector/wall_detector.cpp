/**
 * @file    wall_detector.cpp
 * @brief   this controlle detects walls with the frontal camera
 *
 * @author  Eduardo Cubells Talavera <100291101@alumnos.uc3m.es>
 * @date    13/11/2014
 */

#include "MyRobot.h"

// This is the main program of your controller.
// It creates an instance of your Robot subclass, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node

/**
 * @brief Main program.
 */
int main(int argc, char **argv)
{
    MyRobot* my_robot = new MyRobot();

    my_robot->run();

    delete my_robot;

    return 0;
}
