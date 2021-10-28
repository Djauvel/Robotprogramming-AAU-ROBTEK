#include <Zumo32U4.h>
#include <Wire.h>

// This excercise is from Robotprogrammering - Course 4 (23-09-2021)
// This file has the purpose of testing the motors on our zumo robot.
// The code in this excercise simulates a mini mars rover 

Zumo32U4Motors motors; // Defining the motors compatible with the Zumo32U4 board.

int nCom = 6;
char com[] = { 'f', 'r', 'f', 'l', 'b', 's' };

int params[2][6] =
{
	{50, 100, 50, 100, 200, 0},
	{1000, 500, 1000, 500, 500, 0}
};

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	for (int i = 0; i < nCom; i++)
	{
		Serial.println(com[i]); // Just prints the char from the 'com' array.
		switch (com[i]) // In this switch we look at what the value i is from the array 'com' from the loop.
		{
		case 'f':
			MoveForward(i, "We move forward!");
			break;

		case 'r':
			MoveRight(i, "We move right");
			break;

		case 'l':
			MoveLeft(i, "We move left!");
			break;

		case 'b':
			MoveBackwards(i, "We move backwards!");
			break;

		case 's':
		default:
			Serial.println("We do not move!");
			motors.setSpeeds(0, 0);
			delay(params[1][i]);
			break;
		}
		motors.setSpeeds(0, 0); // Stops the motors. (Sets speed to 0)
		delay(1000);
	}
}

/// <summary>
/// Moves the rover in a forward direction.
/// </summary>
/// <param name="index"></param>
/// <param name="text"></param>
void MoveForward(int index, String text)
{
	Serial.println(text);
	motors.setSpeeds(params[0][index], params[0][index]);
	delay(params[1][index]);
}

/// <summary>
/// Moves the rover in a left direction.
/// </summary>
/// <param name="index"></param>
/// <param name="text"></param>
void MoveLeft(int index, String text)
{
	Serial.println("We move left!");
	motors.setSpeeds(params[0][index], -params[0][index]);
	delay(params[1][index]);
}

void MoveRight(int index, String text)
{
	Serial.println("We move right!");
	motors.setSpeeds(-params[0][index], params[0][index]);
	delay(params[1][index]);
}

void MoveBackwards(int index, String text)
{
	Serial.println("We move backwards!");
	motors.setSpeeds(-params[0][index], -params[0][index]);
	delay(params[1][index]);
}

