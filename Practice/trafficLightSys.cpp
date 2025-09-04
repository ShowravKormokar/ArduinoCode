// Make a traffic light system using 3 led and buzzer
// C++ code

int redL = 2, yellowL = 3, greenL = 4;
int buzzarPin = 5; // Bzzar Pin
int btnPin = 6;    // Button Pin
int btnStatus = 0;
int toggle = 0;

void setup()
{
    pinMode(redL, OUTPUT);
    pinMode(yellowL, OUTPUT);
    pinMode(greenL, OUTPUT);
    pinMode(buzzarPin, OUTPUT);
}

void loop()
{
    btnStatus = digitalRead(btnPin);

    if (btnStatus == HIGH)
    {
        digitalWrite(buzzarPin, LOW);
        digitalWrite(redL, HIGH);
        delay(5000);
        digitalWrite(redL, LOW);

        digitalWrite(yellowL, HIGH);
        delay(3000);
        digitalWrite(yellowL, LOW);

        digitalWrite(buzzarPin, HIGH);
        delay(300);
        digitalWrite(buzzarPin, LOW);

        digitalWrite(greenL, HIGH);
        delay(5000);
        digitalWrite(greenL, LOW);

        digitalWrite(buzzarPin, HIGH);
    }
}