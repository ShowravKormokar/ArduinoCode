// Measure distance using sensors and set if object in range turn light and on buzzer
// C++ code
//
int trig = 3;
int echo = 2;

void setup()
{
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
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
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
    }
    else
    {
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
    }
    Serial.println(dis);
}