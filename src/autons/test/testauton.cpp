#include "main.h"
#include "pros/rtos.hpp"
#include "lemlib/api.hpp"
#include "robot-config.h"
#include "macros.h"

void testauto(){
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(0,0,0);
    chassis.turnToHeading(-90,700);
    chassis.waitUntilDone();
}

void testLateral() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(0, 0, 0); // Reset the robot's position
    chassis.moveToPose(0, 24, 0, 3500, {.forwards=true, .lead=0.1, .maxSpeed=100, .minSpeed=30, .earlyExitRange=0});
    chassis.waitUntilDone();
}

void monkey(){
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(0,0,0);
    chassis.moveToPose(0, 24, 0, 3500, {.forwards=true, .lead=0.1, .maxSpeed=100, .minSpeed=30, .earlyExitRange=0});
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.moveToPose(0, 0, 0, 3500, {.forwards=false, .lead=0.1, .maxSpeed=100, .minSpeed=30, .earlyExitRange=0});
    chassis.waitUntilDone();
}

void armtestload(){
    int armDesired=0;
    int armCurrent=ArmRotation.get_angle();
    armDesired=150;
    ArmRotation.reset();
    ArmRotation.set_position(3);
    arm.move_velocity(-200);
    pros::delay(100);
    while(abs(armCurrent-armDesired)>3){
        armCurrent=(3+((ArmRotation.get_angle())/100))%360;
      if((armDesired-armCurrent)>0){
        arm.move_voltage(-200*abs(armCurrent-armDesired)-350);
      }
      else if((armDesired-armCurrent)<0){
        arm.move_voltage(200*abs(armCurrent-armDesired)+350);
      }
    }
    arm.move_voltage(0);
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    arm.brake();
}