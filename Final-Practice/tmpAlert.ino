// Show temperature on LCD and Serial Monitor, if tepmperature exceeds threshold, show alert on LCD and turn on Red LED.

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int ledArr[4] = {4, 5, 6, 3};

int pir = A0;
int buz = 7;

void setup()
{
    // LED Configure
    for (int i = 0; i < 4; i++)
    {
        pinMode(ledArr[i], OUTPUT);
    }

    // Buzzer Configure
    pinMode(buz, OUTPUT);

    // LCD Configure
    lcd.init();
    lcd.backlight();

    // Serial Monitor Configure
    Serial.begin(9600);
}

void loop()
{
    // lcd.clear();
    float sensor = analogRead(pir);

    float volt = sensor * (5.0 / 1023.0);
    float tempu = (volt - 0.5) * 100.0;

    lcd.setCursor(0, 0);
    lcd.print("TMP: ");
    lcd.print(tempu);
    lcd.setCursor(12, 0);
    lcd.print("*C");

    if (tempu < 0.0)
    {
        digitalWrite(ledArr[0], LOW);
        digitalWrite(ledArr[1], LOW);
        digitalWrite(ledArr[2], LOW);
        digitalWrite(ledArr[3], HIGH);
        digitalWrite(buz, LOW);

        lcd.setCursor(0, 1);
        lcd.print("Very COLD!");
    }
    else if (tempu >= 0.0 && tempu <= 40.0)
    {
        digitalWrite(ledArr[0], HIGH);
        digitalWrite(ledArr[1], LOW);
        digitalWrite(ledArr[2], LOW);
        digitalWrite(ledArr[3], LOW);
        digitalWrite(buz, LOW);
    }
    else if (tempu > 40.0 && tempu <= 70.0)
    {
        digitalWrite(ledArr[0], LOW);
        digitalWrite(ledArr[1], HIGH);
        digitalWrite(ledArr[2], LOW);
        digitalWrite(ledArr[3], LOW);
        digitalWrite(buz, LOW);
    }
    else if (tempu > 70.0)
    {
        digitalWrite(ledArr[0], LOW);
        digitalWrite(ledArr[1], LOW);
        digitalWrite(ledArr[2], HIGH);
        digitalWrite(ledArr[3], LOW);
        digitalWrite(buz, HIGH);

        lcd.setCursor(0, 1);
        lcd.print("Very HOT!");
    }

    Serial.print("Temperature: ");
    Serial.print(tempu);
    Serial.println(" *C");
    delay(200);
}