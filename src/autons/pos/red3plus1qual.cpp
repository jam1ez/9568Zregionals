#include "main.h"
#include "pros/rtos.hpp"
#include "lemlib/api.hpp"
#include "robot-config.h"
#include "macros.h"



void red3plus1qual(){
    //first going to alliance stake and clamping mogo
	int  AutoarmCurrent=0;
	int AutoarmDesired=37;
	chassis.setPose(12,9.3,45);
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
	chassis.moveToPose(2.2, -25.2566, 0, 1800, {.forwards=false, .lead=0.2, .maxSpeed=45, .minSpeed=25, .earlyExitRange=0});
	chassis.waitUntilDone();
	//new shi
	chassis.arcade(-20,0);
	pros::delay(300);
	goalclamp.set_value(true);
	pros::delay(100);
	chassis.arcade(0,0);
	
	pros::delay(150);
    intake.move_velocity(200);
    //new shi
	///////////////////////////
    //
    //
    /////////////////////////////
    // intake.move_velocity(200);
    // chassis.moveToPose(13.9, -24.666, -103.5, 1500, {.forwards=true, .lead=0.2, .maxSpeed=90, .minSpeed=60, .earlyExitRange=0});
    // chassis.waitUntilDone();
    // chassis.turnToHeading(47.3,500);
    // chassis.waitUntilDone();
    /////////////////////////////
    //
    //
    /////////////////////////////
    chassis.moveToPose(-21.35, -25.23, -111, 2000, {.forwards=true, .lead=0.2, .maxSpeed=70, .minSpeed=58, .earlyExitRange=0});
    chassis.waitUntilDone();
    ///////////////////////////
    //h
    //goin into the corner align
    /////////////////////////////
    chassis.moveToPose(-23.5, -2.84, 1, 500, {.forwards=true, .lead=0.2, .maxSpeed=90, .minSpeed=60, .earlyExitRange=0});
    chassis.waitUntilDone();
    // chassis.moveToPose(35, 5, 0, 900, {.forwards=true, .lead=0.2, .maxSpeed=80, .minSpeed=60, .earlyExitRange=0});
    // chassis.waitUntilDone();
    chassis.moveToPose(-34, 8.9+1.9+1, -0, 1200, {.forwards=true, .lead=0.2, .maxSpeed=70, .minSpeed=60, .earlyExitRange=0});
    chassis.waitUntilDone();
    
    chassis.turnToHeading(-46, 800);
    chassis.waitUntilDone();
    chassis.arcade(0,30);
    pros::delay(200);
    chassis.arcade(0,0);
    ///////////////////////////
    //
    //backshots
    //
    /////////////////////////////
    pros::delay(100);
	chassis.arcade(100,0);
	pros::delay(600);
  chassis.arcade(-127,0);
  pros::delay(500);
  chassis.arcade(0,0);
  pros::delay(150);
 //getting the second
chassis.moveToPose(-33, 7, -40, 1500, {.forwards=true, .lead=0.15, .maxSpeed=40, .minSpeed=30, .earlyExitRange=0});
 chassis.waitUntilDone();
 pros::delay(60);
 pros::delay(300);

 ///////////////////////////
    //
    //touching bar
    //
/////////////////////////////
chassis.moveToPose(-16,-10,-50,1500,{.forwards=false, .lead=0.2, .maxSpeed=100, .minSpeed=90, .earlyExitRange=0});
chassis.waitUntilDone();
chassis.turnToHeading(223,500);
chassis.waitUntilDone();
chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
chassis.moveToPose(20,-35, -222, 1500, {.forwards=true, .lead=0.1, .maxSpeed=90, .minSpeed=80, .earlyExitRange=0});
chassis.waitUntilDone();




}