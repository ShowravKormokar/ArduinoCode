// Turn ON LED when press button
// C++ code
//
void setup()
{
    pinMode(12, OUTPUT);
    pinMode(10, INPUT);
}

void loop()
{
    int button = digitalRead(10);
    if (button == HIGH)
    {
        digitalWrite(12, HIGH);
    }
    else
    {
        digitalWrite(12, LOW);
    }

    delay(5);
}