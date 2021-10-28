#include<Wire.h>
#include<Zumo32U4.h>

/// <summary>
/// Defines the basic properties for a simple control command for the rover.
/// </summary>
struct RoverControl // A struct is much like a class however technically a structure that can hold multiple variables and functions.
{
	char command;
	int speed;
	int time;
};

void setup()
{ }

void loop()
{ }
