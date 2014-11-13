/**
 * @file    wall_detector.cpp
 * @brief   this controlle detects walls with the frontal camera
 *
 * @author  Eduardo Cubells Talavera <100291101@alumnos.uc3m.es>
 * @date    13/11/2014
 */

#include <iostream>

#include <webots/DifferentialWheels.hpp>

using namespace std;
using namespace webots;

#define NUM_DISTANCE_SENSOR 2
#define DISTANCE_LIMIT      100
#define MAX_SPEED           100

class MyRobot : public DifferentialWheels {
    private:
        int _time_step;

        Camera * _forward_camera;

        double _left_speed, _right_speed;

    public:
        /**
         * @brief Empty constructor of the class.
         */
        MyRobot();

        /**
         * @brief Destructor of the class.
         */
        ~MyRobot();

        /**
         * @brief User defined function for initializing and running the template class.
         */
        void run();
};
