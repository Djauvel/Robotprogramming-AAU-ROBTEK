
// This excercise is from Robotprogrammering - Course 3 (UNDEFINED-9-2021)
// This file has the purpose of UNDEFINED
// The code in this excercise UNDEFINED

void loop() {
	if (Serial.available() > 0) {
		delay(200);
		c = Serial.read();
		if (i == 0)
		{
			Serial.println("Received " + (String)c); // echo the received chars
			delay(200);

			digitalWrite(yellow, LOW);
			digitalWrite(green, HIGH);

			switch (c)
			{
			case 'y':

				break;

			case 'g':

				break;
			}
		}
	}
}