// Common Anode 7-Segment Display with Slider Switch and Buzzer

int segPins[] = {2, 3, 4, 5, 6, 7, 8}; // a-g
int buzzer = 9;
int buttonPin = 10;

bool systemOn = false;
bool lastButtonState = HIGH;
int currentDigit = 0;

unsigned long previousMillis = 0;
const long interval = 500; // time for each digit

// Common Anode digits (0 = ON, 1 = OFF)
int digits[10][7] = {
    {0, 0, 0, 0, 0, 0, 1}, // 0
    {1, 0, 0, 1, 1, 1, 1}, // 1
    {0, 0, 1, 0, 0, 1, 0}, // 2
    {0, 0, 0, 0, 1, 1, 0}, // 3
    {1, 0, 0, 1, 1, 0, 0}, // 4
    {0, 1, 0, 0, 1, 0, 0}, // 5
    {0, 1, 0, 0, 0, 0, 0}, // 6
    {0, 0, 0, 1, 1, 1, 1}, // 7
    {0, 0, 0, 0, 0, 0, 0}, // 8
    {0, 0, 0, 0, 1, 0, 0}  // 9
};

void setup()
{
    for (int i = 0; i < 7; i++)
        pinMode(segPins[i], OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
    clearDisplay(); // Initially OFF
}

void loop()
{
    bool buttonState = digitalRead(buttonPin);

    // Detect slider toggle
    if (buttonState != lastButtonState && buttonState == LOW)
    {
        systemOn = !systemOn;    // Toggle ON/OFF
        tone(buzzer, 1000, 200); // Beep
        delay(200);              // Simple debounce
    }
    lastButtonState = buttonState;

    if (systemOn)
    {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval)
        {
            previousMillis = currentMillis;
            displayDigit(currentDigit);
            currentDigit++;
            if (currentDigit > 9)
                currentDigit = 0;
        }
    }
    else
    {
        clearDisplay();
        currentDigit = 0; // Reset digit when OFF
    }
}

void displayDigit(int num)
{
    for (int i = 0; i < 7; i++)
    {
        digitalWrite(segPins[i], digits[num][i]);
    }
}

void clearDisplay()
{
    for (int i = 0; i < 7; i++)
    {
        digitalWrite(segPins[i], HIGH); // Common Anode OFF
    }
}
