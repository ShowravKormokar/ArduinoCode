// Use multiple LEDs with distance sensor(using HC-SR04) to indicate far or near distance range
int trigPin = 9;
int echoPin = 10;
int ledGreen = 3;
int ledYellow = 4;
int ledRed = 5;

long duration;
int distance;

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledGreen, OUTPUT);
    pinMode(ledYellow, OUTPUT);
    pinMode(ledRed, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    // Send ultrasonic pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read echo pulse duration
    duration = pulseIn(echoPin, HIGH);

    // Convert to distance in cm
    distance = duration * 0.034 / 2;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // LED indication based on distance
    if (distance >= 331)
    {
        // Out of range
        digitalWrite(ledGreen, LOW);
        digitalWrite(ledYellow, LOW);
        digitalWrite(ledRed, LOW);
    }
    else if (distance > 200)
    { // Far
        digitalWrite(ledGreen, HIGH);
        digitalWrite(ledYellow, LOW);
        digitalWrite(ledRed, LOW);
    }
    else if (distance > 100 && distance <= 199)
    { // Medium
        digitalWrite(ledGreen, LOW);
        digitalWrite(ledYellow, HIGH);
        digitalWrite(ledRed, LOW);
    }
    else if (distance <= 99)
    { // Near
        digitalWrite(ledGreen, LOW);
        digitalWrite(ledYellow, LOW);
        digitalWrite(ledRed, HIGH);
    }

    delay(200); // small delay
}