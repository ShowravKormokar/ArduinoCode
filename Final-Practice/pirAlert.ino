// If motion is detected by PIR sensor, buzzer will sound and LCD will display message.

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int pir = 2;
int buz = 3;
int led = 4;

void setup()
{
    // LCD configure
    lcd.init();
    lcd.backlight();

    pinMode(led, OUTPUT);
    pinMode(buz, OUTPUT);
    pinMode(led, INPUT);
    Serial.begin(9600);
}

void loop()
{
    lcd.clear();

    int pirRead = digitalRead(pir);
    if (pirRead)
    {
        // digitalWrite(buz,HIGH);
        tone(buz, 1000); // Play a 1 kHz tone
        digitalWrite(led, HIGH);

        lcd.setCursor(0, 0);
        lcd.print("Motion Detected!");
        Serial.println("Motion Detected!");
    }
    else
    {
        lcd.setCursor(0, 0);
        lcd.print("Motion not Detected!");

        // digitalWrite(buz,LOW);
        noTone(buz);
        digitalWrite(led, LOW);
    }

    delay(300);
}