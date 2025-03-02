//red 5 ring and alliance stake touching bar
//tuned 2024.2.24

#include "main.h"
#include "pros/rtos.hpp"
#include "lemlib/api.hpp"
#include "robot-config.h"
#include "macros.h"

void blue5plus1alliancefirst(){
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
	pros::delay(450);
	goalclamp.set_value(true);
	pros::delay(100);
	chassis.arcade(0,0);
	
	pros::delay(150);
	//
	
	
	arm.move_velocity(50);
	chassis.turnToHeading(-95,500);
	chassis.waitUntilDone();
	intake.move_velocity(200);
	arm.move_velocity(0);
	// intakeTop.move_velocity(200);
	chassis.moveToPose(-15, -42.0, -100, 1500, {.forwards=true, .lead=0.2, .maxSpeed=70, .minSpeed=50, .earlyExitRange=0});
	chassis.turnToHeading(-90,100);
	chassis.moveToPose(-34, -42.0, -100, 1500, {.forwards=true, .lead=0.2, .maxSpeed=40, .minSpeed=30, .earlyExitRange=0});
	chassis.moveToPose(2, -28, -135, 1500, {.forwards=false, .lead=0.2, .maxSpeed=90, .minSpeed=80, .earlyExitRange=0});
	chassis.turnToHeading(-90,300);
	chassis.moveToPose(-13.2, -28, -90, 1500, {.forwards=true, .lead=0.2, .maxSpeed=100, .minSpeed=60, .earlyExitRange=0});
	chassis.waitUntilDone();
	pros::delay(200);
	chassis.turnToHeading(-30,400);
	chassis.moveToPose(-25, -6, -46, 1500, {.forwards=true, .lead=0.2, .maxSpeed=100, .minSpeed=60, .earlyExitRange=0});
	chassis.turnToHeading(-45,200);
  //align to corner y=7
	chassis.moveToPose(-33, 12, -48, 1200, {.forwards=true, .lead=0.15, .maxSpeed=80, .minSpeed=50, .earlyExitRange=0});
	chassis.turnToHeading(-45,200);
	chassis.waitUntilDone();


		chassis.arcade(96,0);
    //corner bakcshots
	pros::delay(600);
	//reduce speed to 50 for better entry on metal field wall
	chassis.arcade(127,0);
	pros::delay(700);
//   chassis.arcade(-70,0);
//   pros::delay(700);
  chassis.arcade(-100,0);
  pros::delay(600);
  chassis.arcade(0,0);
  pros::delay(150);
  chassis.setBrakeMode(MOTOR_BRAKE_HOLD);
  chassis.moveToPose(-33.2699, 8.122, -44.62, 1500, {.forwards=true, .lead=0.15, .maxSpeed=40, .minSpeed=20, .earlyExitRange=0});
 //y=9.235 
  chassis.waitUntilDone();
  //finish the corner backshots
  chassis.setBrakeMode(MOTOR_BRAKE_COAST);
  chassis.moveToPose(-4.913, -10.015, -57.683, 1200, {.forwards=false, .lead=0.15, .maxSpeed=120, .minSpeed=100, .earlyExitRange=0});
  chassis.waitUntilDone();
  chassis.turnToHeading(-210,300);
  chassis.waitUntilDone();
chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
intake.move_velocity(0);
//move to 14, -30, 221
chassis.moveToPose(14, -30, -221, 1500, {.forwards=true, .lead=0.15, .maxSpeed=120, .minSpeed=120, .earlyExitRange=0});
  // chassis.arcade(127,0);
  // pros::delay(188);
  // chassis.arcade(0,0);
//   chassis.setBrakeMode(MOTOR_BRAKE_COAST);
  
//   pros::delay(300);
//   chassis.arcade(0,0);
// 	chassis.moveToPose(9, -5, 90, 1500, {.forwards=false, .lead=0.2, .maxSpeed=90, .minSpeed=80, .earlyExitRange=0});
// 	//x=6
//   chassis.waitUntilDone();
//     intake.move_velocity(0);
// 	intake.move_velocity(-200);
// 	pros::delay(200);
// 	intake.move_velocity(200);
//   	pistake.set_value(true);
// 	chassis.turnToHeading(-90,700);
// 	chassis.waitUntilDone();
// 	chassis.setBrakeMode(MOTOR_BRAKE_HOLD);

// 	chassis.moveToPose(-23.5, -5, -90, 1570, {.forwards=true, .lead=0.2, .maxSpeed=80, .minSpeed=65, .earlyExitRange=0});
// 	chassis.waitUntilDone();
// 	pistake.set_value(false);
// 	pros::delay(300);
// 	chassis.arcade(-80,0);
// 	pros::delay(600);
// 	chassis.arcade(0,0);
// 	pros::delay(400);
// 	chassis.moveToPose(-16,-38, 45, 1500, {.forwards=false, .lead=0.1, .maxSpeed=120, .minSpeed=110, .earlyExitRange=0});
// 	chassis.turnToHeading(45,300);
// 	chassis.waitUntilDone();
}