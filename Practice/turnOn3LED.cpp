// Turning on three led light

void setup()
{
    pinMode(13, OUTPUT); // RED
    pinMode(8, OUTPUT);  // BLUE
    pinMode(7, OUTPUT);  // GREEN
}

void loop()
{
    digitalWrite(13, HIGH); // RED ON
    delay(1000);
    digitalWrite(13, LOW);

    digitalWrite(8, HIGH); // BLUE ON
    delay(1000);
    digitalWrite(8, LOW);

    digitalWrite(7, HIGH); // GREEN ON
    delay(1000);
    digitalWrite(7, LOW);

    // while (true); // Stop the loop after 3 repetitions
}
