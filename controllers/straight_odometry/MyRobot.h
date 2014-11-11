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

#define MAX_SPEED           100
#define ENCODER_RESOLUTION  5
#define radio               0.0825
#define AXLELENGTH          0.32

class MyRobot : public DifferentialWheels {
    private:
        int _time_step;
        double _distance;
        double _incremental_distance_right, _incremental_distance_left;
        double _posicion0, _posicion1, _posicion2;
        double _posicion2_grados;

        int _state;
        double _odometry_error;

        Compass * _my_compass;

        double _left_speed, _right_speed;
        double _left_encoder, _right_encoder;
        double _last_left_encoder, _last_right_encoder;
        double _total_left_increment, _total_right_increment;

        /**
        * @brief moves the distance introduced in the direction of the angle desired
        * @param the distance and the angle we want to follow
        * @return
        *
        */
        void go_forward(double distance_desired, double angle_desired);

        /**
        * @brief this funtion resets the encoders
        * @param
        * @return
        *
        */
        void reset_encoders();

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
