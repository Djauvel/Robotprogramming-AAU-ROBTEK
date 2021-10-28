#include <Zumo32U4.h>
#include <Wire.h>

// This excercise is from Robotprogrammering - Course 4 (23-09-2021)
// This file has the purpose of testing the motors on our zumo robot.
// The code in this excercise simulates a mini mars rover 

struct RoverControl
{
	char command;
	int speed;
	int time;

	void setSpeed(int s) {
		speed = s;
	}

	void setTime(int t) {
		time = t;
	}
};

Zumo32U4Motors motors; // Defining the motors compatible with the Zumo32U4 board.
RoverControl controls[6];
int totalDirections = 6;

char directions[] = { 'f', 'r', 'f', 'l', 'b', 's' };
int speedParams = 250;
bool controlsSet = false;

void setup()
{
	Serial.begin(9600);
	setControls();
}

void setControls()
{
	for (int i = 0; i < totalDirections; i++)
	{
		RoverControl rc;
		rc.command = directions[i];
		rc.setTime(1000);
		rc.setSpeed(speedParams);
		controls[i] = rc;
	}
	controlsSet = true;
}

void loop()
{
	if (controlsSet)
	{
		for (int i = 0; i < totalDirections; i++)
		{
			switch (controls[i].command)
			{
			case 'f':
				MoveForward(controls[i].speed, controls[i].time);
				break;

			case 'r':
				MoveRight(controls[i].speed, controls[i].time);
				break;

			case 'b':
				MoveBackwards(controls[i].speed, controls[i].time);
				break;

			case 'l':
				MoveLeft(controls[i].speed, controls[i].time);
				break;

			default:
				Stop();
				break;
			}
		}
	}
}

void MoveForward(int speed, int time)
{
	motors.setSpeeds(speed + 100, speed);
	delay(time);
}

void MoveRight(int speed, int time)
{
	motors.setSpeeds(speed, -speed);
	delay(time);
}

void MoveBackwards(int speed, int time)
{
	motors.setSpeeds(-speed, -speed);
	delay(time);
}

void MoveLeft(int speed, int time)
{
	motors.setSpeeds(-speed, speed);
	delay(time);
}

void Stop()
{
	motors.setSpeeds(0, 0);
	delay(1000);
}

