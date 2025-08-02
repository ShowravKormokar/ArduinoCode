//Turning on 3 led's depending when 0 on red, even on green and odd on blue using loop 0-10

void setup()
{
    pinMode(13, OUTPUT); // Red LED
    pinMode(8, OUTPUT);  // Blue LED
    pinMode(7, OUTPUT);  // Green LED

    for (int i = 0; i <= 10; i++)
    {
        if (i == 0)
        {
            digitalWrite(13, HIGH); // Red ON
            digitalWrite(8, LOW);
            digitalWrite(7, LOW);
        }
        else if (i % 2 != 0)
        { // Odd
            digitalWrite(13, LOW);
            digitalWrite(8, HIGH); // Blue ON
            digitalWrite(7, LOW);
        }
        else
        { // Even (not zero)
            digitalWrite(13, LOW);
            digitalWrite(8, LOW);
            digitalWrite(7, HIGH); // Green ON
        }

        delay(1000); // Wait 1 second for each number

        // Turn off all LEDs before next number
        digitalWrite(13, LOW);
        digitalWrite(8, LOW);
        digitalWrite(7, LOW);
    }
}

void loop()
{
    // Do nothing after running once
}
