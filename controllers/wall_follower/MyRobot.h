#include <iostream>
#include <cmath>
#include <webots/DifferentialWheels.hpp>

using namespace std;
using namespace webots;

#define MAX_SPEED       80
#define NUM_DISTANCE_SENSOR 8
#define DISTANCE_LIMIT      100

class MyRobot : public DifferentialWheels {
    private:
        int _time_step;

        DistanceSensor * _distance_sensor[NUM_DISTANCE_SENSOR];

        double _left_speed, _right_speed;

        enum Mode {
                    STOP,
                    FORWARD,
                    SLOW_FORWARD,
                    TURN_LEFT,
                    TURN_RIGHT,
                    WALL_FOLLOWER
                  };

        Mode _mode;

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
