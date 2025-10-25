// An ultrasonic sensor (HC-SR04) measures the distance of a moving body,
// and the calculated distance in centimeters is displayed on the LCD screen.
#include <LiquidCrystal_I2C.h>

// Initialize LCD (address 0x27, 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 2;
const int echoPin = 3;
long duration;
float distance;

void setup()
{
    lcd.init();
    lcd.backlight();

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    lcd.setCursor(0, 0);
    lcd.print("Distance Meter");
    delay(1500);
    lcd.clear();
}

void loop()
{
    // Send 10µs trigger pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read echo time
    duration = pulseIn(echoPin, HIGH);

    // Calculate distance in cm
    distance = duration * 0.034 / 2;

    // Display on LCD
    lcd.setCursor(0, 0);
    lcd.print("Dist.:");
    lcd.setCursor(7, 0);
    lcd.print(distance);
    lcd.print("cm");

    delay(500);
}