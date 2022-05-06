void setup()
{
	Serial.begin(9600);
	pinMode(12, OUTPUT);
	pinMode(6, OUTPUT); 
	pinMode(5, INPUT);
	pinMode(13, OUTPUT);
    Serial.println("Arduino based Social Distancing Detector");
    Serial.println("****************************************");
}
void loop()
{
	int duration, distance;
	digitalWrite(6, HIGH);
	delay(1);
	digitalWrite(6, LOW);
	duration = pulseIn(5, HIGH);
	distance = (duration/2) / 29.1;
	Serial.println("Distance in cm: ");
	Serial.println(distance);
	if (distance <= 100 && distance >= 0)
	{
        Serial.println("XX  ALERT  XX");
        Serial.println("MAINTAIN PROPER DISTANCE");
		tone(13,500,300);
		digitalWrite(12, HIGH);
        delay(80);
        digitalWrite(12, LOW);
        delay(80);
	}
	else
	{
        Serial.println("You are safe!");
		noTone(13);
		digitalWrite(12, LOW);
	}
	delay(100);
}
