#include "main.h"
#include "pros/rtos.hpp"
#include "lemlib/api.hpp"
#include "robot-config.h"
#include "macros.h"
#include "autons.h"
#include "utilheader.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {
	pros::lcd::initialize();
	pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
  
    

    // the default rate is 50. however, if you need to change the rate, you
    // can do the following.
    // lemlib::bufferedStdout().setRate(...);
    // If you use bluetooth or a wired connection, you will want to have a rate of 10ms

    // for more information on how the formatting for the loggers
    // works, refer to the fmtlib docs

    // thread to for brain screen and position logging
    pros::Task screenTask([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // log position telemetry
            lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
            // delay to save resources
            pros::delay(50);
        }
    });
    
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	// red5plus1alliancefirst(); //tuned
  // bluepos5(); //tuned
  // blue3plus1qual(); //tuned
  // bluesawp();// tuned
  // monkey2();//SKILLS, TUNED
  // blue5plus1alliancefirst(); //tuned
  // red3plus1qual(); //tuned
  redpos5();


}


/**
 * 
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  chassis.setBrakeMode(MOTOR_BRAKE_COAST);
	float armDesired=0;
    float armCurrent=0;
	bool armstate=false;
	bool climbLatch=false;
	bool climbToggle=false;
	bool descoreLatch=false;
	bool descoreToggle=false;
	bool mogoLatch=false;
	bool mogoToggle=false;
	bool doinkerLatch=false;
	bool doinkerToggle=false;
	      ArmRotation.reset();
	      ArmRotation.set_position(3);
     
    // controller
    // loop to continuously update motors
    while (true) {
        // get joystick positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        // move the chassis with curvature drive
		armCurrent=(3+((ArmRotation.get_angle())/100))%360;
		arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
          armDesired=5;
		  armstate=true;
        }
        if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)){
          armDesired=28;
		  armstate=true;
        }
		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
			armDesired=66;
			armstate=true;
		  }
		  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)){
			armDesired=177;
			armstate=true;
		  }
        else{
        
        }
      //Scoring arm
          if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
              if(armCurrent<240){
              arm.move_velocity(-200);
          intake.move_velocity(-100);
		  armstate=false;
			}
		  }
          else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
              arm.move_velocity(200);
          intake.move_velocity(0);
		  armstate=false;
		  }
        else{
                arm.move_voltage(0);
                arm.brake();
        }
        
		if(armstate==true){
        if(abs(armCurrent-armDesired)>3){
        if((armDesired-armCurrent)>0){
          arm.move_voltage(-160*abs(armCurrent-armDesired)-300);
        }
        else if((armDesired-armCurrent)<0){
          arm.move_voltage(160*abs(armCurrent-armDesired)+300);
        }
        else{
          arm.brake();
        }
      }
      else{
          arm.brake();
        }
        }
      
        chassis.arcade(leftY, rightX);
		    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
          intake.move_velocity(200);
        }
        
        else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
          intake.move_velocity(0);

        }
        else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
          intake.move_velocity(-200);

        }
        else{
          intake.move_velocity(0);

        }
        
	      if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
          if(!climbLatch){
            climbToggle = !climbToggle;
            climbLatch = true;
          }
        } else {
          climbLatch = false;
        }
        
        if (climbToggle){
            rightdoinker.set_value(true);     
          }
          else{
            rightdoinker.set_value(false);
          }


	      if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
          if(!mogoLatch){
            mogoToggle = !mogoToggle;
            mogoLatch = true;
          }
        } else {
          mogoLatch = false;
        }
        
        if (mogoToggle){
			goalclamp.set_value(true);
          }
          else{
			goalclamp.set_value(false);
          }

	     if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
          if(!doinkerLatch){
            doinkerToggle = !doinkerToggle;
            doinkerLatch = true;
          }
        } else {
          doinkerLatch = false;
        }
        
        if (doinkerToggle){
			leftdoinker.set_value(true);
          }
          else{
			leftdoinker.set_value(false);
          }

          
        // delay to save resources
        pros::delay(10);

      
    }                           // Run for 20 ms then update
}
