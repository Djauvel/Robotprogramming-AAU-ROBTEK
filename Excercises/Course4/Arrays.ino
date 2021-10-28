
// This excercise is from Robotprogrammering - Extra Course (28-09-2021)
// This file has the purpose of learning and explaining 1D and 2D arrays.
// The code in this excercise is made to demonstrate how to use and read arrays of different datatypes.

int vArray[] = { 10, 20, 30 }; // This is an int array. Size: 3. vArray is just a random name.
String mArray[] = { "mm", "cm", "L" }; // This is called a String array. It's size is 3.

void setup() {
	Serial.begin(9600);
}

void loop() {
	// The reason we make 2 for loops is to iterate through both arrays. One of values and another for units.
	// We iterate while less than 3 because the size of the arrays are 3 (They contain 3 values)
	// Although the array has 3 items the highest item is reffered to as index: 2, because an array counts
	// differently. It counts 3 items as: 0, 1, 2. For this reason we do not count to 3 or above in the for loops.
	for (int v = 0; v < 3; v++) // Iterates v = 0, 1, 2.
	{
		for (int m = 0; m < 3; m++) // Iterates m = 0, 1, 2.
		{
			//The code inside of this loop will be run for each value i is. So if m and v is less than x this code will be run x times.

			Serial.println("Measurement is: " + vArray[v] + mArray[m]);
			// This will print a string that is first: "Measurement is: 10mm".
			// After that: "Measurement is: 20cm".
			// And atlast: "Measurement is: 30L".
		}
	}
}