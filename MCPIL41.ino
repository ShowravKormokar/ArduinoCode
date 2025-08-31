// 7-Segment Display with Arduino (Common Cathode)
// Pins for segments: a, b, c, d, e, f, g

int segPins[] = {9, 10, 4, 5, 6, 8, 7}; // a–g connected to Arduino pins
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

void setup()
{
    for (int i = 0; i < 7; i++)
    {
        pinMode(segPins[i], OUTPUT);
    }
}

void loop()
{
    // Count up 0-9
    for (int num = 0; num < 10; num++)
    {
        displayDigit(num);
        delay(1000); // Hold each number for 1 second
    }

    // Count down 9-0
    for (int num = 9; num >= 0; num--)
    {
        displayDigit(num);
        delay(1000); // Hold each number for 1 second
    }
}

void displayDigit(int num)
{
    for (int i = 0; i < 7; i++)
    {
        digitalWrite(segPins[i], digits[num][i]);
    }
}