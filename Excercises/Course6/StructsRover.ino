#include<Wire.h>
#include<Zumo32U4.h>

/// <summary>
/// Defines the basic properties for a simple control command for the rover.
/// </summary>
struct RoverControl // A struct is much like a class however technically a structure that can hold multiple variables and functions.
{
	char command; // The command for moving in a certain direction.
	int speed; // The motor rotation speed
	int time; // Time in milliseconds

	/// <summary>
	/// Returns the local 'speed' variable value.
	/// </summary>
	/// <returns></returns>
	int getSpeed() {
		return speed;
	}

	/// <summary>
	/// Sets the local 'speed' variable value.
	/// </summary>
	/// <param name="s"></param>
	void setSpeed(int s) {
		speed = s;
	}

	/// <summary>
	/// Runs a delay with the set time.
	/// </summary>
	void wait() {
		delay(time);
	}
};

void setup()
{ 
	Serial.begin(9600);
}

void loop()
{
	RoverControl rc; // Creates a new RoverControl struct everytime we call 'rc'
	rc.command = 'f'; // Sets the command to 'f' for: forward
	rc.setSpeed(100); // Sets the motor rotation speed to: 100
	rc.time = 1000; // Sets the time to 1000ms (1 second)

	Serial.println("Command -> " + (String)rc.command + " Params -> speed: " + rc.getSpeed() + " time: " + rc.time); // Prints the data of our newly created struct
	delay(5000);
}
