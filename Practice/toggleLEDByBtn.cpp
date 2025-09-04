// Turn 4 led left to right by 1st press btn and again press turn led right to left (Toggle)

int pinLED[4] = {2, 3, 4, 5}; //  LED's Pin
int btnPin = 6; // Button pin
int btnStatus = 0;
int toggle = 0;

void setup()
{
    for (int i = 0; i < 4; i++)
    {
        pinMode(pinLED[i], OUTPUT);
    }
}

void loop()
{
    btnStatus = digitalRead(btnPin);

    if (btnStatus == HIGH)
    {
        offLED();
        delay(500);
        if (toggle == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                digitalWrite(pinLED[i], HIGH);
                delay(1000);
            }
            toggle = 1;
        }
        else if (toggle == 1)
        {
            offLED();
            delay(500);
            for (int i = 3; i >= 0; i--)
            {
                digitalWrite(pinLED[i], HIGH);
                delay(1000);
            }
            toggle = 0;
        }
    }
}

// LED OFF
void offLED()
{
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(pinLED[i], LOW);
    }
}