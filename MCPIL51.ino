// Measure distance using sensors and set if object in range turn on buzzer
int trig = 9;
int echo = 10;
int buzzer = 3;

void setup()
{
    pinMode(buzzer, OUTPUT);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(trig, LOW);
    delay(2);
    digitalWrite(trig, HIGH);
    delay(15);
    digitalWrite(trig, LOW);

    int time = pulseIn(echo, HIGH);
    int dis = time * 0.034 / 2;
    if (dis < 324)
    {
        digitalWrite(buzzer, HIGH);
    }
    else
    {
        digitalWrite(buzzer, LOW);
    }
    Serial.print(dis);
    Serial.println("cm");
}