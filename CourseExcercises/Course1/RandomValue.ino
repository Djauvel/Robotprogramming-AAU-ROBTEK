
// This excercise is from Robotprogrammering - Course 1 (14-9-2021)
// This file has the purpose of learning how to generate and use random values.
// The code in this excercise UNDEFINED

int randomNumber = 0; // This is the variable we will be modifying with random events.
int nIteration = 0; // The total iterations / The total times we have gone through our loops.
int count60 = 0; // This value will indicate how many times we generate a number larger than 60.
int count30 = 0; // This value will indicate how many times we generate a number less than 30.
int countNone = 0; // This value will indicate how many times we generate a number inbetween 60 and 30.

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	randomSeed(analogRead(0));
}

// the loop function runs over and over again until power down or reset
void loop() {
	randomNumber = random(0, 101); // Here we assign randomNumber to a numeric value that is generated. The number will be inbetween 0 to 101.
	delay(500); // Waits 500ms (half a second)
	nIteration++; // For each time loop is run the total iterations is increased by 1.

	if (randomNumber > 60) { // If the random number is LARGER than 60
		count60++; // Increases variable value by 1.
	}
	else if (randomNumber < 30) { // If the random number is LESS then 30
		count30++; // Increases variable value by 1.
	}
	else { // If the number is neither LARGER than 60 nor LESS than 30 (This means inbetween the two)
		countNone++; // Increases variable value by 1.
	}

	if (nIteration % 6 == 0) {
		Serial.println("Number of values read: " + (String)nIteration + "; Higher than 60: " + (String)count60 + "; Lower than 30: " + (String)count30 + "; Rest: " + (String)countNone);
	}
}

