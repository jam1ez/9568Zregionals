#include "main.h"
#include "pros/rtos.hpp"
#include "lemlib/api.hpp"
#include "robot-config.h"
#include "macros.h"

void skillz(){
    chassis.setPose(0,0,0);
    ArmRotation.reset();
    ArmRotation.set_position(3);
    chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
    intake.move_velocity(200);
    pros::delay(399);
    intake.move_velocity(0);
    //move to align with first goal
    chassis.moveToPose(0, 14, 0, 900, {.forwards=true, .lead=0.2, .maxSpeed=60, .minSpeed=40, .earlyExitRange=0});
    chassis.waitUntilDone();
    //turnaround to first goal;
    chassis.turnToHeading(90, 800);
    chassis.waitUntilDone();
    //move to first goal
    chassis.moveToPose(-22, 15, 90, 1000, {.forwards=false, .lead=0.2, .maxSpeed=50, .minSpeed=20, .earlyExitRange=0});
    chassis.waitUntilDone();
    //clamp goal
    goalclamp.set_value(true);
    pros::delay(200);
    //turn to first ring
    chassis.turnToHeading(0, 600);
    chassis.waitUntilDone();
    intake.move_velocity(200);
    //move to first ring
    chassis.moveToPose(-22.65, 33.35, -4.2, 1000, {.forwards=true, .lead=0.2, .maxSpeed=120, .minSpeed=70, .earlyExitRange=0});
    chassis.waitUntilDone();
    // pros::delay(100);
    //move to second ring
    chassis.moveToPose(-55.123, 56.636, -70, 2000, {.forwards=true, .lead=0.2, .maxSpeed=120, .minSpeed=50, .earlyExitRange=0});
    chassis.waitUntilDone();
    pros::delay(300);
    //turn to point third ring
    chassis.turnToPoint(-43.19, 6.33, 800, {.maxSpeed=100, .minSpeed=60, .earlyExitRange=0});
    chassis.waitUntilDone();
    //move to third fourth and fifth ring
    chassis.moveToPose(-42.19, -0.33, -180.83, 3000, {.forwards=true, .lead=0.2, .maxSpeed=70, .minSpeed=50, .earlyExitRange=0});
    chassis.waitUntilDone();
    pros::delay(200);
    //TURN TO 6TH RING
    chassis.turnToPoint(-62, 14, 800, {.maxSpeed=100, .minSpeed=60, .earlyExitRange=0});
    chassis.waitUntilDone();
    //move to 6th ring
    chassis.moveToPose(-62, 14, -69, 2000, {.forwards=true, .lead=0.2, .maxSpeed=80, .minSpeed=50, .earlyExitRange=0});
    chassis.waitUntilDone();
    pros::delay(300);
    // //turn to 40 degrees (corner)
    // chassis.turnToHeading(40, 800);
    // chassis.waitUntilDone();
    //move to corner
    chassis.moveToPose(-64, 3, 38, 2000, {.forwards=false, .lead=0.2, .maxSpeed=100, .minSpeed=80, .earlyExitRange=0});
    chassis.waitUntilDone();
    //push goal in more
    chassis.arcade(-80,0);
    pros::delay(500);
    chassis.arcade(0,0);
    //stop intake
    intake.move_velocity(0);
    //put down the goal
    goalclamp.set_value(false);
    pros::delay(100);
    //move to align with second goal(-50,15.7,41)
    chassis.moveToPose(-52.935, 16.29, 30, 2000, {.forwards=true, .lead=0.2, .maxSpeed=80, .minSpeed=60, .earlyExitRange=0});
    chassis.waitUntilDone();
    chassis.turnToHeading(-90, 800);
    chassis.waitUntilDone();
    //move to second goal, 2,10,-87
    chassis.moveToPose(8, 11, -90, 2000, {.forwards=false, .lead=0.2, .maxSpeed=120, .minSpeed=80, .earlyExitRange=0});
    chassis.waitUntilDone();
    //finalize move to goal
    chassis.moveToPose(29, 13.6, -90, 1000, {.forwards=false, .lead=0.2, .maxSpeed=30, .minSpeed=20, .earlyExitRange=0});
    chassis.waitUntilDone();
    /*

    ################################
    ||                            ||
    ||     END OF FIRST PART      ||
    || START TO CLAMP SECOND GOAL ||
    ||     START SECOND PART      ||
    ||                            ||
    ################################
    

    */
    //clamp goal
    goalclamp.set_value(true);
    pros::delay(200);
    //turn to heading 12 for first ring
    chassis.turnToHeading(12, 800);
    chassis.waitUntilDone();
    //move to first ring @22,35,22.5
    intake.move_velocity(200);
    chassis.moveToPose(22, 35, 22.5, 1000, {.forwards=true, .lead=0.2, .maxSpeed=120, .minSpeed=90, .earlyExitRange=0});    
    chassis.waitUntilDone();
    //move to second ring@56,62,69
    chassis.moveToPose(58.5, 62, 69, 2000, {.forwards=true, .lead=0.2, .maxSpeed=120, .minSpeed=50, .earlyExitRange=0});
    chassis.waitUntilDone();
    pros::delay(200);
    //turnheading third ring @theta = 202
    chassis.turnToHeading(202, 800);
    chassis.waitUntilDone();
    //move to fifth ring @48.3,4,179
    chassis.moveToPose(49.3, 0.33, 179, 2000, {.forwards=true, .lead=0.2, .maxSpeed=60, .minSpeed=40, .earlyExitRange=0}); 
    chassis.waitUntilDone();
    pros::delay(100);
    //turn to 6th ring heading at 59.2
    chassis.turnToHeading(59.2, 800);
    chassis.waitUntilDone();
    //move to 6th ring @ 57,14,59
    chassis.moveToPose(59, 14, 59, 2000, {.forwards=true, .lead=0.2, .maxSpeed=80, .minSpeed=50, .earlyExitRange=0});
    chassis.waitUntilDone();
    pros::delay(300);
    //turn to corner heading -25
    chassis.turnToHeading(-25, 800);
    chassis.waitUntilDone();
    //move to corner @ 59,3,-30
    chassis.moveToPose(59, 3, -30, 2000, {.forwards=false, .lead=0.2, .maxSpeed=100, .minSpeed=80, .earlyExitRange=0});
    chassis.waitUntilDone();
    //push goal in more
    chassis.arcade(-80,0);
    pros::delay(200);
    chassis.arcade(0,0);
    //stop intake
    intake.move_velocity(0);
    //put down the goal
    goalclamp.set_value(false);
    pros::delay(100);
    //move to prime positiion for third goal push to conrer @ 47.5, 62.6969, 1.3
    chassis.moveToPose(47.5, 56.6969, 1.3, 2000, {.forwards=true, .lead=0.2, .maxSpeed=100, .minSpeed=60, .earlyExitRange=0});
    chassis.waitUntilDone();

    /*

################################
||                            ||
||     END OF SECOND PART     ||
||      START THIRD PART      ||
||                            ||
################################

    */

    intake.move_velocity(200);
    //move to point 26,81,-41 to pre load a ring
    chassis.moveToPose(25, 82, -52, 3000, {.forwards=true, .lead=0.2, .maxSpeed=100, .minSpeed=80, .earlyExitRange=0});
    chassis.waitUntilDone();
    //stop intake
    pros::delay(266);
    intake.move_velocity(0);
    //push goal in point 1 @ 11, 109, 7.5
    chassis.moveToPose(22, 110, 7.5, 1000, {.forwards=true, .lead=0.2, .maxSpeed=120, .minSpeed=80, .earlyExitRange=0});
    chassis.waitUntilDone();
    //push goal point 2 @ 14,115,44.5
    chassis.moveToPose(25, 120, 44.5, 1000, {.forwards=true, .lead=0.2, .maxSpeed=80, .minSpeed=40, .earlyExitRange=0});
    chassis.waitUntilDone();
    //push goal point 3 final point @ 35, 126, 76
    chassis.moveToPose(46, 130, 76, 2000, {.forwards=true, .lead=0.2, .maxSpeed=60, .minSpeed=40, .earlyExitRange=0});
    chassis.waitUntilDone();
    //another last push at 49.126.82
    chassis.moveToPose(61.75, 130.5, 82, 800, {.forwards=true, .lead=0.2, .maxSpeed=60, .minSpeed=40, .earlyExitRange=0});
    chassis.waitUntilDone();
    pros::delay(200);
    //go back to clamp a mogo at 4.335, 113.748,55.741
    chassis.moveToPose(0, 111.748, 52.741, 4000, {.forwards=false, .lead=0.2, .maxSpeed=60, .minSpeed=20, .earlyExitRange=0});
    chassis.waitUntilDone();
    //clamp goal
    chassis.arcade(-20,0);
    pros::delay(300);
    goalclamp.set_value(true);
    pros::delay(100);
    chassis.arcade(0,0);
    pros::delay(100);
    //turn on the intake to score the first ring
    intake.move_velocity(200);
    //move to 42.42, 112.1, 91.3 to intake first ring
    chassis.moveToPose(48.42, 113.1, 91.3, 2000, {.forwards=true, .lead=0.2, .maxSpeed=100, .minSpeed=80, .earlyExitRange=0});
    chassis.waitUntilDone();
    //turn to point for below coordinates 52.6, 90, 160
    chassis.turnToPoint(55.6, 80, 800, {.maxSpeed=100, .minSpeed=80, .earlyExitRange=0});
    chassis.waitUntilDone();
    //move to 52.6, 90, 160 to intake second ring
    chassis.moveToPose(52.6, 76, 160, 2000, {.forwards=true, .lead=0.2, .maxSpeed=100, .minSpeed=80, .earlyExitRange=0});
    chassis.waitUntilDone();
    //turn to heading to go to other side curve 305
    chassis.turnToHeading(305, 800);
    chassis.waitUntilDone();
/*

################################
||                            ||
||   GOING TO LAST QUADRANT   ||
||                            ||
################################

*/

    //midpoint of first curve 0,100, 245.8
    chassis.moveToPose(0, 105, 245.8, 2000, {.forwards=true, .lead=0.2, .maxSpeed=100, .minSpeed=80, .earlyExitRange=0});
    chassis.waitUntilDone();
    //second point of curve to intake 4th ring (-17,90,221.334)
    chassis.moveToPose(-17, 86, 221.334, 2000, {.forwards=true, .lead=0.2, .maxSpeed=100, .minSpeed=80, .earlyExitRange=0});
    chassis.waitUntilDone();
    //third point of curve for 5th ring ( -44,81.687,267.6)
    chassis.moveToPose(-50, 81.687, 267.6, 2000, {.forwards=true, .lead=0.2, .maxSpeed=100, .minSpeed=80, .earlyExitRange=0});
    chassis.waitUntilDone();
    //fourth point of curve for 6th ring (-59.5,100.6,355.6)
    chassis.moveToPose(-59.5, 109.6, 355.6, 2000, {.forwards=true, .lead=0.2, .maxSpeed=90, .minSpeed=60, .earlyExitRange=0});
    chassis.waitUntilDone();
    //move reverse to pose -57.5, 91, 384.39 to put down mogo and align with alliance stake ring
    chassis.moveToPose(-57.5, 96, 384.39, 2000, {.forwards=false, .lead=0.2, .maxSpeed=100, .minSpeed=80, .earlyExitRange=0});
    chassis.waitUntilDone();
    pros::delay(300);
    //put down mogo
    goalclamp.set_value(false);
    pros::delay(100);
    //load wall ring
    intake.move_velocity(180);
    loadringmacro();
    //move to -51.8,107.62,411.96 load ring
    chassis.moveToPose(-51.8, 107.62, 411.96, 2000, {.forwards=true, .lead=0.2, .maxSpeed=80, .minSpeed=40, .earlyExitRange=0});
    chassis.waitUntilDone();
    //move to -49.3,59.92, 360
    chassis.moveToPose(-49.3, 63.92, 360, 2000, {.forwards=false, .lead=0.2, .maxSpeed=100, .minSpeed=80, .earlyExitRange=0});
    chassis.waitUntilDone();
    //turn to 270 heading
    chassis.turnToHeading(270, 800);
    chassis.waitUntilDone();
    //ram wall
    chassis.arcade(100,0);
    pros::delay(500);
    chassis.arcade(0,0);
    //stop intake
    intake.move_velocity(0);
    //score arm
    scoreringmacro();
    chassis.arcade(-100,0);
    pros::delay(80);
    chassis.arcade(100,0);
    pros::delay(100);
    chassis.arcade(-60,0);
    pros::delay(400);
    chassis.arcade(0,0);



    

    




    





}