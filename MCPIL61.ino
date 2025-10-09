//  Detection of motion using PIR sensor. Use LED and buzzer with PIR sensor to indicate motion.
int pir = 4;
int led = 7;
int buzz = 6;

void setup()
{
    pinMode(pir, INPUT);
    pinMode(led, OUTPUT);
    pinMode(buzz, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int readData = digitalRead(pir);
    if (readData == HIGH)
    {
        digitalWrite(led, HIGH);  // LED ON
        digitalWrite(buzz, HIGH); // BUZZER ON
        Serial.println("Motion detected!");
    }
    else
    {
        digitalWrite(led, LOW);  // LED OFF
        digitalWrite(buzz, LOW); // BUZZER OFF
    }
    delay(200);
}