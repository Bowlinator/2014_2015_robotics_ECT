/**
 * @file MyRobot.h
 * @brief this controller contrals the robot using odometry
 *
 * @autor Eduardo Cubells Talavera <100291101@alumnos.uc3m.es>
 * @date 11/11/2014
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

        Camera * _spherical_camera;

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
