#pragma once

#include "main.h"
#include "pros/rtos.hpp"
#include "lemlib/api.hpp"

extern pros::Controller controller;
extern pros::Motor intake;
// motor groups
extern pros::Motor arm;
extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;
extern pros::Rotation ArmRotation;
extern pros::Imu imu;
extern pros::Rotation horizontalEnc;
extern pros::Rotation verticalEnc;
extern pros::ADIDigitalOut pistake;
extern pros::ADIDigitalOut goalclamp;
extern pros::ADIDigitalOut rightdoinker;
extern pros::ADIDigitalOut leftdoinker;

//lemlib defs

extern lemlib::TrackingWheel horizontal;
extern lemlib::TrackingWheel vertical;
extern lemlib::Drivetrain drivetrain;
extern lemlib::ControllerSettings linearController;
extern lemlib::ControllerSettings angularController;
extern lemlib::OdomSensors sensors;
extern lemlib::ExpoDriveCurve throttleCurve;
extern lemlib::ExpoDriveCurve steerCurve;
extern lemlib::Chassis chassis;
