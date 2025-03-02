#include "main.h"
#include "pros/rtos.hpp"
#include "lemlib/api.hpp"
#include "robot-config.h"



// Task to display coordinates and battery percentage on the controller screen
void displayCoordinatesAndBattery(void* param) {
    while (true) {
        // Get the current pose (X, Y, heading)
        float x = chassis.getPose().x;
        float y = chassis.getPose().y;
        float heading = chassis.getPose().theta;

        // Get the battery percentage
        float batteryPercentage = pros::battery::get_capacity();

        // Format the coordinates and battery percentage as a string
        char buffer[50];
        controller.print(0,0, buffer, "X: %.2f\nY: %.2f\nH: %.2f\nBat: %.1f%%", x, y, heading, batteryPercentage);

        // Display the string on the controller screen
        // pros::lcd::set_text(0, buffer);
       
      
        // Wait for 100ms before updating the display
        pros::delay(66);
        // controller.clear();
    }
}

// Initialize the task in autonomous or opcontrol
void initializeDisplayTask() {
    // Start the task to display coordinates and battery percentage
    pros::Task displayTask(displayCoordinatesAndBattery, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Display Task");
}