#include "main.h"
#include "pros/rtos.hpp"
#include "lemlib/api.hpp"
#include "robot-config.h"
#include "macros.h"

//tuned 2025.2.25
//blue 3 plus 1 2 corner rings

void bluesawp(){
    //first going to alliance stake and clamping mogo
	int  AutoarmCurrent=0;
	int AutoarmDesired=37;
	chassis.setPose(-12,3,-45);
	// chassis.setPose(-10,6,-45);
	ArmRotation.reset();
	ArmRotation.set_position(3);
	arm.move_velocity(0);
	arm.set_brake_mode(MOTOR_BRAKE_HOLD);
	arm.brake();
	arm.move_velocity(-150);
	chassis.arcade(65,0);
	pros::delay(200);
	chassis.arcade(0,0);
	pros::delay(600);
	arm.move_velocity(0);
	chassis.arcade(-100,0);
	pros::delay(200);
	chassis.arcade(0,0);
	arm.move_velocity(200);
	chassis.moveToPose(-2.2, -25.2566, -0, 1800, {.forwards=false, .lead=0.2, .maxSpeed=45, .minSpeed=25, .earlyExitRange=0});
	chassis.waitUntilDone();
	//new shi
	chassis.arcade(-20,0);
	pros::delay(300);
	goalclamp.set_value(true);
	pros::delay(100);
	chassis.arcade(0,0);
    ///////////////////////////
    //clamp mogo and intake
    //
    //
    ///////////////////////////
    intake.move_velocity(200);
    arm.move_velocity(0);
    //intake first ring
    chassis.turnToPoint(16.69, -26, 800, {.maxSpeed=100, .minSpeed=60, .earlyExitRange=0});
    chassis.waitUntilDone();
    chassis.moveToPose(16.69, -26, 97.6, 1500, {.forwards=true, .lead=0.2, .maxSpeed=90, .minSpeed=60, .earlyExitRange=0});
    chassis.waitUntilDone();
    pros::delay(388);
    chassis.turnToPoint(-18.5, -11, 800, {.maxSpeed=100, .minSpeed=60, .earlyExitRange=0});
    chassis.waitUntilDone();
    pistake.set_value(true);
    chassis.moveToPose(-18, -9, -56, 1500, {.forwards=true, .lead=0.2, .maxSpeed=100, .minSpeed=50, .earlyExitRange=0});
    chassis.waitUntilDone();
    pros::delay(200);
    pistake.set_value(false);
    chassis.arcade(-80,0);
    pros::delay(400);
    chassis.arcade(0,0);
    pros::delay(1000);
    intake.move_velocity(0);
    goalclamp.set_value(false);
    chassis.moveToPose(-46.5, -9.7, -90, 1500, {.forwards=true, .lead=0.2, .maxSpeed=100, .minSpeed=50, .earlyExitRange=0});  
    chassis.waitUntilDone();
    chassis.turnToHeading(0,500);
    chassis.waitUntilDone();
    chassis.moveToPose(-49, -30, 0, 1500, {.forwards=false, .lead=0.2, .maxSpeed=30, .minSpeed=20, .earlyExitRange=0});
    chassis.waitUntilDone();
    pros::delay(200);
    goalclamp.set_value(true);
//itnaking last ring
pros::delay(400);

    chassis.turnToPoint(-63, -30, 800, {.maxSpeed=100, .minSpeed=60, .earlyExitRange=0});
    intake.move_velocity(200);
    chassis.waitUntilDone();
    chassis.moveToPose(-68, -25, -98, 1500, {.forwards=true, .lead=0.2, .maxSpeed=100, .minSpeed=50, .earlyExitRange=0});
    chassis.waitUntilDone();
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    pros::delay(200); 
    chassis.moveToPose(-38, -33, 220, 1500, {.forwards=true, .lead=0.2, .maxSpeed=100, .minSpeed=60, .earlyExitRange=0});
    chassis.waitUntilDone();
}