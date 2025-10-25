// The LCD is interfaced with an Arduino microcontroller to print and shift a string message to the 
//right and left using control commands. A button is added to create a transition between right and left shifts
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int buttonPin = 2;
int flag = 0; // 0 = right shift, 1 = left shift
int lastButtonState = HIGH;
String message = "222311077";
int pos = 0;

void setup()
{
    lcd.init();
    lcd.backlight();
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
    lcd.clear();
    int buttonState = digitalRead(buttonPin);

    // Toggle flag when button pressed
    if (buttonState == LOW && lastButtonState == HIGH)
    {
        flag = !flag; // toggle between 0 and 1
        lcd.clear();
        delay(300);
    }
    lastButtonState = buttonState;

    lcd.clear();

    if (flag == 0)
    { // Right shift
        lcd.setCursor(pos, 0);
        lcd.print(message);
        pos++;
        if (pos > 16)
            pos = 0;
    }
    else
    { // Left shift
        lcd.setCursor(pos, 0);
        lcd.print(message);
        pos--;
        if (pos < 0)
            pos = 16;
    }

    delay(250);
}