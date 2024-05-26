const int redPin = 9;    // Red pin of the RGB LED
const int greenPin = 10; // Green pin of the RGB LED
const int bluePin = 11;  // Blue pin of the RGB LED

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // Initialize all LEDs to off
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}

void loop() {
  setColor(255, 0, 0);   // Red with lower intensity
  delay(1000);            // Wait for 1 second
  setColor(0, 255, 0);   // Green with lower intensity
  delay(1000);            // Wait for 1 second
  setColor(0, 0, 255);   // Blue with lower intensity
  delay(1000);
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
