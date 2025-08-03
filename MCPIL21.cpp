// Turning on LED's by using arduino uno
void setup()
{
    pinMode(13, OUTPUT); // RED LED
}

void loop()
{
    digitalWrite(13, HIGH); // RED ON
    delay(1000); // HOLD 1sec
    digitalWrite(13, LOW);
}