// 7-Segment Display with Arduino (Common Cathode)
// Pins for segments: a, b, c, d, e, f, g

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

void setup()
{
    for (int i = 0; i < 7; i++)
    {
        pinMode(segPins[i], OUTPUT);
    }
}

void loop()
{
    for (int num = 0; num < 10; num++)
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
