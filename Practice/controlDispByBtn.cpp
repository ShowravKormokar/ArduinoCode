// Show 0-9 on seven segment display by pressing btn, each press increase num and print

int btnPin = 9;
int segPins[] = {2, 3, 4, 5, 6, 7, 8}; // a–g connected to Arduino pins

int digits[10][7] = {
    // a b c d e f g
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

int btnState = 0;
int lastBtnState = 0;
int btnStatus = 0; // current digit

void setup()
{
    pinMode(btnPin, INPUT_PULLUP); // button with pull-up
    for (int i = 0; i < 7; i++)
    {
        pinMode(segPins[i], OUTPUT);
    }
    displayDigit(btnStatus); // show 0 at start
}

void loop()
{
    btnState = digitalRead(btnPin);

    // detect button press (LOW because of INPUT_PULLUP)
    if (btnState == LOW && lastBtnState == HIGH)
    {
        btnStatus++;
        if (btnStatus > 9)
        {
            btnStatus = 0;
        }
        displayDigit(btnStatus);
        delay(200); // debounce delay
    }

    lastBtnState = btnState;
}

void displayDigit(int num)
{
    for (int i = 0; i < 7; i++)
    {
        digitalWrite(segPins[i], digits[num][i]);
    }
}
