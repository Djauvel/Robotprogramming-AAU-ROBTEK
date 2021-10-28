#include <Zumo32U4.h>
#include <Wire.h>


// This excercise is from Robotprogrammering - Course 4 (23-09-2021)
// This file has the purpose of testing the motors on our zumo robot.
// The code in this excercise rotaes the motor with a speed in the range of -100 - 100

Zumo32U4Motors motors; // Defining the motors compatible with the Zumo32U4 board.
int motorSpeed = 100; // The base speed value for the motors

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600); // Sets up the serial frequency
}

// the loop function runs over and over again until power down or reset
void loop() {
	motors.setSpeeds(0, 0); // turn off mottors
	delay(1000);
	motors.setSpeeds(motorSpeed, -motorSpeed); // set L and R speeds , minus speed for backwards.
	delay(300);
	motors.setSpeeds(-motorSpeed, motorSpeed);
	delay(300);
}
