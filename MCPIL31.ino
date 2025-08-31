const int buttonPin = 7;     // Push button connected to pin 2
const int led1 = 3;          // RED LED pin
const int led2 = 4;          // GREEN LED pin
const int led3 = 5;          // BLUE LED pin
const int buzzer = 2;        // Buzzer pin

int buttonState = 0;         // Current state of button
int lastButtonState = 0;     // Previous state of button
int pressCount = 0;          // Count button presses

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Detect button press (only when state changes from LOW to HIGH)
  if (buttonState == HIGH && lastButtonState == LOW) {
    pressCount++; // Increase press count

    // Sound buzzer for 500 ms
    tone(buzzer,100,500);
    digitalWrite(buzzer, LOW);

    // Control LEDs based on press count
    if (pressCount == 1) {
      digitalWrite(led1, HIGH);
    } 
    else if (pressCount == 2) {
      digitalWrite(led2, HIGH);
    } 
    else if (pressCount == 3) {
      digitalWrite(led3, HIGH);
    } 
    else if (pressCount > 3) {
      pressCount = 3; // Limit to 3 presses
    }
  }

  lastButtonState = buttonState; // Save the state
}