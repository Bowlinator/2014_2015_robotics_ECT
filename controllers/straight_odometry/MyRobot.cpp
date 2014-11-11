/**
 * @file MyRobot.cpp
 * @brief this controller contrals the robot using odometry
 *
 * @autor Eduardo Cubells Talavera <100291101@alumnos.uc3m.es>
 * @date 11/11/2014
 */
#include "MyRobot.h"

//////////////////////////////////////////////

MyRobot::MyRobot() : DifferentialWheels()
{
    _time_step = 64;

    _left_speed = 0;
    _right_speed = 0;

    // Get and enable the compass device
    _my_compass = getCompass("compass");
    _my_compass->enable(_time_step);

     enableEncoders(_time_step); 
}
    
   

//////////////////////////////////////////////

MyRobot::~MyRobot()
{
    _my_compass->disable();
    disableEncoders();
}

//////////////////////////////////////////////

void MyRobot::run()
{
    _posicion0=0;
    _posicion1= -9;
    _posicion2= M_PI/4;

    _state = 1;

    while (step(_time_step) != -1)
    {
        _left_encoder = getLeftEncoder() / ENCODER_RESOLUTION;
        _right_encoder = getRightEncoder() / ENCODER_RESOLUTION;

        double _left_increment = _left_encoder - _last_left_encoder;
        double _right_increment = _right_encoder - _last_right_encoder;

        _posicion0 = _posicion0 + ((_right_increment + _left_increment)/2) * cos(_posicion2+((_right_increment - _left_increment)/2*AXLELENGTH)) * radio;
        _posicion1 = _posicion1 + ((_right_increment + _left_increment)/2) * sin(_posicion2+((_right_increment - _left_increment)/2*AXLELENGTH)) * radio;
        _posicion2 = _posicion2 + ((_right_increment - _left_increment)/AXLELENGTH) * radio;

        _last_left_encoder = _left_encoder;
        _last_right_encoder = _right_encoder;

        _posicion2_grados = (180*_posicion2)/ M_PI;

        cout << "posicion[0]: " << _posicion0 << "\tposicion[1]: " << _posicion1 << "\tposicion[2]: " << _posicion2 << endl;



        switch(_state)
        {
            case 1:
                go_forward(3.5, 45);
                break;
            case 2:
                cout << "END" << endl;
                _state = 2;
                break;
            case 3:
                break;
            default:
                break;
        }

    }
}

//////////////////////////////////////////////

void MyRobot::go_forward(double distance_desired, double angle_desired)
{
    cout << "GO FORWARD" << endl << endl;
    _distance = _left_encoder / 5 * 0.0825;
    cout << "DISTANCE: " << _distance << endl << endl;
    // simple bang-bang control
    if (_posicion2_grados < angle_desired - 2) {
        // turn right
        _right_speed = MAX_SPEED;
        _left_speed = MAX_SPEED - 15;
        cout << "Gira r" << endl << endl;
        cout << "_posicion2_grados" << _posicion2_grados << endl << endl;

        setSpeed(_left_speed, _right_speed);
    }
    else {
        if (_posicion2_grados > angle_desired - 2) {
            // turn left
            _right_speed = MAX_SPEED - 15;
            _left_speed = MAX_SPEED;
            cout << "Gira l" << endl << endl;
            cout << "_posicion2_grados" << _posicion2_grados << endl << endl;

            setSpeed(_left_speed, _right_speed);
        }
        else {
            // move straight forward
            _left_speed = MAX_SPEED;
            _right_speed = MAX_SPEED;
            setSpeed(_left_speed, _right_speed);
        }
    }
    // set the motor speeds

    //resets encoders
    if(_distance > distance_desired)
    {
        reset_encoders();
    }
}

//////////////////////////////////////////////

void MyRobot::reset_encoders()
{
    cout << "RESET ENCODERS "<< endl;
    _left_speed = 0;
    _right_speed = 0;
    setSpeed(_left_speed, _right_speed);
    _distance = 0;
    setEncoders(0,0);
    _state = _state + 1;
}

//////////////////////////////////////////////


