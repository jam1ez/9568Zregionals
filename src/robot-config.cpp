#include "lemlib/api.hpp"
#include "pros/rtos.hpp"
// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Motor arm(7, pros::MotorGearset::green);
// motor groups
pros::Motor intake(-8,pros::MotorGearset::red);
pros::MotorGroup leftMotors({-19, 1, -4},pros::MotorGearset::blue);
pros::MotorGroup rightMotors({16, 15, -14}, pros::MotorGearset::blue); 
pros::Rotation ArmRotation(-18);
pros::Imu imu(5);
pros::Rotation horizontalEnc(2);
pros::Rotation verticalEnc(-20);
pros::ADIDigitalOut rightdoinker(2);
pros::ADIDigitalOut leftdoinker(3);
pros::ADIDigitalOut pistake(8);
pros::ADIDigitalOut goalclamp(1);
//lemlib defs
lemlib::TrackingWheel horizontal(&horizontalEnc, lemlib::Omniwheel::NEW_275, -2.3);
lemlib::TrackingWheel vertical(&verticalEnc, 2.75, 1.375);
//-1.375

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
    &rightMotors, // right motor group
    10.82, // 10 inch track width
    lemlib::Omniwheel::NEW_325, // using new 4" omnis
    480, // drivetrain rpm is 360
    2 // horizontal drift is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings linearController(10, // proportional gain (kP)
    0, // integral gain (kI)
    3, // derivative gain (kD)
    3, // anti wi ndup
    0, // small error range, in inches
    100, // small error range timeout, in milliseconds
    0, // large error range, in inches
    500, // large error range timeout, in milliseconds
    14 // maximum acceleration (slew)
);
// angular motion controller
// lemlib::ControllerSettings angularController(4, // proportional gain (kP)
//                                              0.5, // integral gain (kI)
//                                              22, // derivative gain (kD)
//                                              5+2.7, // anti windup
//                                              1, // small error range, in degrees
//                                              100, // small error range timeout, in milliseconds
//                                              3, // large error range, in degrees
//                                              500, // large error range timeout, in milliseconds
//                                              0 // maximum acceleration (slew)
// );
lemlib::ControllerSettings angularController(2, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            10, // derivative gain (kD)
                                            5, // anti windup
                                            0, // small error range, in degrees
                                            100, // small error range timeout, in milliseconds
                                            0, // large error range, in degrees
                                            500, // large error range timeout, in milliseconds
                                            0 // maximum acceleration (slew)
);
// sensors for odometry
lemlib::OdomSensors sensors(&vertical, // vertical tracking wheel
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                            &horizontal, // horizontal tracking wheel
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors, &throttleCurve, &steerCurve

);
