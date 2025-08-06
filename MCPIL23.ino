// Configure 5 LEDs that turn on one by one and then off reversely

int leds[] = {2, 3, 4, 5, 6}; // Array holding LED pin numbers
int n = 5;

void setup()
{
    for (int i = 0; i < n; i++)
    {
        pinMode(leds[i], OUTPUT); // Set all LED pins as OUTPUT
    }
}

void loop()
{
    // Turn ON LEDs from first to last
    for (int i = 0; i < n; i++)
    {
        digitalWrite(leds[i], HIGH);
        delay(1000);
    }

    // Turn OFF LEDs from last to first
    for (int i = n - 1; i >= 0; i--)
    {
        digitalWrite(leds[i], LOW);
        delay(1000);
    }
}