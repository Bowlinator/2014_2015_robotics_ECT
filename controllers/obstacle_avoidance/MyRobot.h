/**
 * @file MyRobot.h
 * @brief this controller contrals the robot using odometry
 *
 * @autor Eduardo Cubells Talavera <100291101@alumnos.uc3m.es>
 * @date 11/11/2014
 */
#include <iostream>
#include <cmath>
#include <webots/DifferentialWheels.hpp>

using namespace std;
using namespace webots;

#define NUM_DISTANCE_SENSOR 16
#define DISTANCE_LIMIT      200
#define MAX_SPEED           30
#define DESIRED_ANGLE   45.0

class MyRobot : public DifferentialWheels {
    private:
        int _time_step;

        Compass * _my_compass;
        DistanceSensor * _distance_sensor[NUM_DISTANCE_SENSOR];
        double _left_speed, _right_speed;

        enum Mode {
            STOP,
            FORWARD,
            TURN_LEFT,
            TURN_RIGHT,
            FAST_TURN_RIGHT,
            OBSTACLE_AVOID
        };

        Mode _mode;

    public:
        // You may need to define your private methods or variables, like
        //  Constructors, helper functions, etc.

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
	
	/**
         * @brief Function for converting bearing vector from compass to angle (in degrees).
         * @param in_vector Input vector with the values to convert.
         * @return The value in degrees.
         */
        double convert_bearing_to_degrees(const double* in_vector);
};

