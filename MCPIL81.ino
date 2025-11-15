// Program for measuring temperature using TMP32 sensor and displaying it on an LCD. Alerts user when temperature is too high or too low.
int sensorPin = A0;
int ledPin = 2;
int buzzerPin = 3;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int sensor = analogRead(sensorPin);
    float volt = sensor * (5.0 / 1023.0);   // Convert analog to voltage
    float temperature = (volt - 0.5) * 100; // TMP36 formula in °C

    if (temperature > 40.0 && temperature < 70.0)
    {
        digitalWrite(ledPin, HIGH);
        digitalWrite(buzzerPin, LOW);
    }
    else if (temperature >= 70.0)
    {
        digitalWrite(ledPin, HIGH);
        digitalWrite(buzzerPin, HIGH);
    }
    else
    {
        digitalWrite(ledPin, LOW);
        digitalWrite(buzzerPin, LOW);
    }

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");
    delay(500);
}