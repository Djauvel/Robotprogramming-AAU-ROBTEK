#include <Zumo32U4.h>
#include <Wire.h>

// This excercise is from Robotprogramming - Course 6 (28-10-2021)
// This excercise is about creating a sumo that moves around based on structs.

/// <summary>
/// Contains elementary variables for controlled movement.
/// </summary>
struct RoverControl // This is a struct, it is a structure that can hold variables, functions and even structs inside structs!
{
	char command; // The command that defines the movement in the type of a char. Such as 'f' for forward.
	int speed; // The speed for the motor to rotate (Movement speed)
	int time; // This is a timed delay for the sumo, this property will be used to determine how many milliseconds it will delay.

	/// <summary>
	/// Sets the struct speed value.
	/// </summary>
	/// <param name="s"></param>
	void setSpeed(int s) {
		speed = s;
	}

	/// <summary>
	/// Sets the struct time value.
	/// </summary>
	/// <param name="t"></param>
	void setTime(int t) {
		time = t;
	}
};

Zumo32U4Motors motors; // Defining the motors compatible with the Zumo32U4 board.
RoverControl controls[6]; // NOTE: The size set as 6 here must at all time be the same size as totalDirections
int totalDirections = 6; // The numeric value of how many different directions we have.

char directions[] = { 'f', 'r', 'f', 'l', 'b', 's' }; // All possible directions.
int speedParams = 250; // The speed for all movements.
bool controlsSet = false; // Indicates wether all controls has been added or not.

void setup()
{
	Serial.begin(9600);
	setControls(); // Calls the function to set all controls as soon as the arduino is on.
}

/// <summary>
/// Creates a set of commands and adds it to the controls array for external use.
/// </summary>
void setControls()
{
	for (int i = 0; i < totalDirections; i++) // Adds a new control struct for every direction there is.
	{
		RoverControl rc;
		rc.command = directions[i];
		rc.setTime(1000);
		rc.setSpeed(speedParams);
		controls[i] = rc;
	}
	controlsSet = true; // Sets this boolean to true once the for loop is done; meaning once all controls has been added.
}

void loop()
{
	if (controlsSet) // If all controls are added.
	{
		for (int i = 0; i < totalDirections; i++)
		{
			switch (controls[i].command) // Detects the command of the control struct within the controls array.
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

/// <summary>
/// Moves the sumo in a forward direction.
/// NOTE: Speed has been significantly increased in order to destroy Peter's sumo.
/// </summary>
/// <param name="speed"></param>
/// <param name="time"></param>
void MoveForward(int speed, int time)
{
	motors.setSpeeds(speed + 100, speed);
	delay(time);
}

/// <summary>
/// Rotates the sumo in a right direction by spinning the wheels in seperate ways by making the speed
/// value negative.
/// </summary>
/// <param name="speed"></param>
/// <param name="time"></param>
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

/// <summary>
///  Rotates the sumo in a left direction by spinning the wheels in seperate ways by making the speed
/// value negative.
/// </summary>
/// <param name="speed"></param>
/// <param name="time"></param>
void MoveLeft(int speed, int time)
{
	motors.setSpeeds(-speed, speed);
	delay(time);
}

/// <summary>
/// Makes the sumo stop, setting the speeds to zero and hereafter waits exactly one second.
/// </summary>
void Stop()
{
	motors.setSpeeds(0, 0);
	delay(1000);
}

