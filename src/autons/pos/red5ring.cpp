#include "main.h"
#include "pros/rtos.hpp"
#include "lemlib/api.hpp"
#include "robot-config.h"
#include "macros.h"

void redpos5(){
    chassis.setPose(-0,0,0);
	// chassis.setPose(-10,6,-45);
	ArmRotation.reset();
	ArmRotation.set_position(3);
    chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
    chassis.moveToPose(0, -23, 0, 2000, {.forwards=false, .lead=0.2, .maxSpeed=80, .minSpeed=60, .earlyExitRange=0});

    chassis.waitUntilDone();
    chassis.moveToPose(0, -32, 0, 2000, {.forwards=false, .lead=0.2, .maxSpeed=30, .minSpeed=20, .earlyExitRange=0});
    chassis.waitUntilDone();
    pros::delay(200);
    goalclamp.set_value(true);
    pros::delay(100);
    intake.move_velocity(200);
    pistake.set_value(true);
    chassis.turnToPoint(17.6, -15, 2000, {.maxSpeed=70, .minSpeed=58, .earlyExitRange=0});
    chassis.waitUntilDone();
    chassis.moveToPose(22.4186, -7, 46, 2000, {.forwards=true, .lead=0.2, .maxSpeed=70, .minSpeed=38, .earlyExitRange=0});
    chassis.waitUntilDone();
    pistake.set_value(false);
    // pros::delay(200);
    chassis.moveToPose(9.316, -14.141, 56, 300, {.forwards=false, .lead=0.2, .maxSpeed=70, .minSpeed=38, .earlyExitRange=0});
    // chassis.waitUntilDone();
    // pros::delay(100);
    chassis.turnToPoint(-20.35, -24.23, 1000, {.maxSpeed=80, .minSpeed=60, .earlyExitRange=0});
    chassis.waitUntilDone();
    chassis.moveToPose(-10.25, -31.23, -111, 2000, {.forwards=true, .lead=0.2, .maxSpeed=70, .minSpeed=58, .earlyExitRange=0});
    chassis.waitUntilDone();
    ///////////////////////////
    //h
    //goin into the corner align
    /////////////////////////////
    chassis.moveToPose(-34.3, -2.84, 1, 500, {.forwards=true, .lead=0.2, .maxSpeed=90, .minSpeed=60, .earlyExitRange=0});
    chassis.waitUntilDone();
    // chassis.moveToPose(35, 5, 0, 900, {.forwards=true, .lead=0.2, .maxSpeed=80, .minSpeed=60, .earlyExitRange=0});
    // chassis.waitUntilDone();
    chassis.moveToPose(-35, 8.9-0.8, -0, 1200, {.forwards=true, .lead=0.2, .maxSpeed=70, .minSpeed=60, .earlyExitRange=0});
    chassis.waitUntilDone();
    chassis.turnToHeading(-46, 800);
    chassis.waitUntilDone();
    ///////////////////////////
    //
    //corner backshots
    /////////////////////////////
    pros::delay(100);
	chassis.arcade(100,0);
	pros::delay(600);
  chassis.arcade(-127,0);
  pros::delay(610);
  chassis.arcade(0,0);
  pros::delay(150);

//   chassis.setBrakeMode(MOTOR_BRAKE_HOLD);
// //   chassis.moveToPose(33.2699, 8.122, 44.62, 1500, {.forwards=true, .lead=0.15, .maxSpeed=40, .minSpeed=20, .earlyExitRange=0});
//   chassis.waitUntilDone();
  ///////////////////////////
  //finish the corner backshots
//intake corner second ring
  /////////////////////////////
 
chassis.moveToPose(-36, 12.5, -40, 1500, {.forwards=true, .lead=0.15, .maxSpeed=40, .minSpeed=30, .earlyExitRange=0});
 chassis.waitUntilDone();
 pros::delay(60);
 ///////////////////////////

 //clearing the corner
 /////////////////////////////
//  rightdoinker.set_value(true);
//  pros::delay(60);
 chassis.turnToHeading(-260, 700, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE,.maxSpeed=80, .minSpeed=50 });
 chassis.waitUntilDone();
 pros::delay(500);
 goalclamp.set_value(false);
 chassis.moveToPose(-26, -33, 0, 2000, {.forwards=false, .lead=0.2, .maxSpeed=120, .minSpeed=90, .earlyExitRange=0});
    chassis.waitUntilDone();
chassis.turnToHeading(0, 500);
chassis.waitUntilDone();


 
}