// Configure LED's that turning on one by one (off then on next)

void setup()
{
    pinMode(13, OUTPUT); // RED LED
    pinMode(7, OUTPUT);  // BLUE LED
    pinMode(4, OUTPUT);  // GREEN LED
}

void loop()
{
    digitalWrite(13, HIGH); // RED ON
    delay(1000);            // HOLD 1sec
    digitalWrite(13, LOW);  // RED OFF

    digitalWrite(7, HIGH); // BLUE ON
    delay(1000);           // HOLD 1sec
    digitalWrite(7, LOW);  // BLUE OFF

    digitalWrite(4, HIGH); // GREEN ON
    delay(1000);           // HOLD 1sec
    digitalWrite(4, LOW);  // GREEN OFF

    while (true)
        ; // stop loop
}