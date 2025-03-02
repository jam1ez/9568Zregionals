#include "main.h"
#include "pros/rtos.hpp"
#include "lemlib/api.hpp"
#include "robot-config.h"
#include <ctime>
#include <chrono>

void loadringmacro(){
    int armDesired=0;
    int armCurrent=0;
    armDesired=26;
    ArmRotation.reset();
    ArmRotation.set_position(3);
    arm.move_velocity(-200);
    pros::delay(100);
    while(abs(armCurrent-armDesired)>3){
        armCurrent=(3+((ArmRotation.get_angle())/100))%360;
      if((armDesired-armCurrent)>0){
        arm.move_voltage(-160*abs(armCurrent-armDesired)-350);
      }
      else if((armDesired-armCurrent)<0){
        arm.move_voltage(160*abs(armCurrent-armDesired)+350);
      }
    }
    arm.move_voltage(0);
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    arm.brake();
}

void scoreringmacro(){

    int armDesired=0;
    int armCurrent=ArmRotation.get_angle();
    armDesired=160;
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

void scoreringmacroto(){
        int armDesired = 130;
        int armCurrent = ArmRotation.get_angle();
        ArmRotation.reset();
        ArmRotation.set_position(3);
        arm.move_velocity(-200);
        pros::delay(100);
    
        // Start a timer using std::chrono
        auto startTime = std::chrono::steady_clock::now();
    
        while (abs(armCurrent - armDesired) > 3) {
            // Check if 3 seconds have passed
            auto currentTime = std::chrono::steady_clock::now();
            auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
            if (elapsedTime >= 1500) {
                return;  // Exit the loop if 3 seconds have passed
            }
    
            armCurrent = (3 + ((ArmRotation.get_angle()) / 100)) % 360;
            if ((armDesired - armCurrent) > 0) {
                arm.move_voltage(-200 * abs(armCurrent - armDesired) - 350);
            } else if ((armDesired - armCurrent) < 0) {
                arm.move_voltage(200 * abs(armCurrent - armDesired) + 350);
            }
        }
    
        arm.move_voltage(0);
        arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        arm.brake();
    
}

void armdown(){
  int armDesired = 5;
  int armCurrent = ArmRotation.get_angle();
  ArmRotation.reset();
  ArmRotation.set_position(3);
  arm.move_velocity(-200);
  pros::delay(100);

  // Start a timer using std::chrono
  auto startTime = std::chrono::steady_clock::now();

  while (abs(armCurrent - armDesired) > 3) {
      // Check if 3 seconds have passed
      auto currentTime = std::chrono::steady_clock::now();
      auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
      if (elapsedTime >= 3000) {
          break;  // Exit the loop if 3 seconds have passed
      }

      armCurrent = (3 + ((ArmRotation.get_angle()) / 100)) % 360;
      if ((armDesired - armCurrent) > 0) {
          arm.move_voltage(-200 * abs(armCurrent - armDesired) - 350);
      } else if ((armDesired - armCurrent) < 0) {
          arm.move_voltage(200 * abs(armCurrent - armDesired) + 350);
      }
  }

  arm.move_voltage(0);
  arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  arm.brake();

}