
// This excercise is from Robotprogrammering - Course 6 (23-09-2021)
// In this example we will be using IR Line Sensors to detect lines and boundaries that 
// the robot moves within and/or follows a black line drawn on the floor.

#include <Zumo32U4.h>
#include <Wire.h>

/// <summary>
/// Contains booleans for each of the sensors based on wether they detect white or black
/// White(true), Black(false).
/// </summary>
struct SensorDetection {
	bool left;
	bool leftCenter;
	bool Center;
	bool rightCenter;
	bool right;
};

Zumo32U4LineSensors sensors;
Zumo32U4Motors motors;

int NUM_SENSORS = 5; // This is the amount of sensors on the board.
int serialFrequency = 9600;
uint16_t sensorValues[5];
int sensorThreshold = 300;
SensorDetection sensorState = { false, false, false, false, false };
bool useEmitter = true;

void setup() {
	sensors.initFiveSensors();
	Serial.begin(serialFrequency);
}

void loop() {
	getSensorData(sensorState);
	delay(500);
}

/// <summary>
/// Handles any input from the IR Line sensors.
/// </summary>
void getSensorData(SensorDetection& state) {
	sensors.read(sensorValues, useEmitter ? QTR_EMITTERS_ON : QTR_EMITTERS_OFF);
	sensorState = { false, false, false, false, false };

	if (sensorValues[0] < sensorThreshold)
		sensorState.left = true;
	if (sensorValues[1] < sensorThreshold)
		sensorState.leftCenter = true;
	if (sensorValues[2] < sensorThreshold)
		sensorState.Center = true;
	if (sensorValues[3] < sensorThreshold)
		sensorState.rightCenter = true;
	if (sensorValues[4] < sensorThreshold)
		sensorState.right = true;

	Serial.println("------------- SENSOR DATA -------------");
	Serial.println("");
	Serial.println("Left sensor value:         " + (String)sensorValues[0] + ",     state: " + (String)sensorState.left);
	Serial.println("Left Center sensor value:  " + (String)sensorValues[1] + ",     state: " + (String)sensorState.leftCenter);
	Serial.println("Center sensor value:       " + (String)sensorValues[2] + ",     state: " + (String)sensorState.Center);
	Serial.println("Right Center sensor value: " + (String)sensorValues[3] + ",     state: " + (String)sensorState.rightCenter);
	Serial.println("RIGHT sensor value:        " + (String)sensorValues[4] + ",     state: " + (String)sensorState.right);
	Serial.println("");
	Serial.println("------------- END OF DATA -------------");
}