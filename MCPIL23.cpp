// Configure 5 LED's that turning on one by one and then off reversely

void setup()
{
    pinMode(13, OUTPUT); // RED LED
    pinMode(12, OUTPUT);  // BLUE LED
    pinMode(11, OUTPUT);  // GREEN LED
    pinMode(10, OUTPUT);  // YELLOW LED
    pinMode(9, OUTPUT);  // WHITE LED
}

void loop()
{
    digitalWrite(13, HIGH); // RED ON
    delay(1000); // HOLD 1sec
    digitalWrite(12, HIGH);  // BLUE ON
    delay(1000); // HOLD 1sec
    digitalWrite(11, HIGH);  // GREEN ON
    delay(1000); // HOLD 1sec
    digitalWrite(10, HIGH);  // YELLOW ON
    delay(1000); // HOLD 1sec
    digitalWrite(9, HIGH);  // WHITE ON
    delay(1000); // HOLD 1sec

    digitalWrite(9, LOW);  // WHITE OFF
    delay(1000); // HOLD 1sec
    digitalWrite(10, LOW); // YELLOW OFF
    delay(1000); // HOLD 1sec
    digitalWrite(11, LOW);  // GREEN OFF
    delay(1000); // HOLD 1sec
    digitalWrite(12, LOW);  // BLUE OFF
    delay(1000); // HOLD 1sec
    digitalWrite(13, LOW); // RED OFF

    while (true)
        ; // stop loop
}