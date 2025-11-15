// Couneter with LCD display using buttons to increase, decrease, and reset the count.

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Button pins
int btnInc = 2;   // Increase
int btnDec = 3;   // Decrease
int btnReset = 4; // Reset

// Previous button states
bool lastInc = HIGH;
bool lastDec = HIGH;
bool lastReset = HIGH;

// Counter variable
int counter = 0;

void setup()
{
    pinMode(btnInc, INPUT_PULLUP);
    pinMode(btnDec, INPUT_PULLUP);
    pinMode(btnReset, INPUT_PULLUP);

    lcd.init();
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print("Counter: 0");
}

void loop()
{
    // Read all buttons
    bool readInc = digitalRead(btnInc);
    bool readDec = digitalRead(btnDec);
    bool readReset = digitalRead(btnReset);

    // Increase button: HIGH → LOW press
    if (lastInc == HIGH && readInc == LOW)
    {
        counter++;
        updateLCD();
        delay(250);
    }

    // Decrease button: HIGH → LOW press
    if (lastDec == HIGH && readDec == LOW)
    {
        counter--;
        updateLCD();
        delay(250);
    }

    // Reset button
    if (lastReset == HIGH && readReset == LOW)
    {
        counter = 0;
        updateLCD();
        delay(250);
    }

    // Save previous states
    lastInc = readInc;
    lastDec = readDec;
    lastReset = readReset;
}

void updateLCD()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Counter: ");
    lcd.print(counter);
}