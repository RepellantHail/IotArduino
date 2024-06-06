#define RPIN 52
#define GPIN 50
#define BPIN 48
#define RED 255, 0, 0
#define GREEN 0, 255, 0
#define BLUE 0, 0, 255

int buttonPin = 2;
int buttonState = 0;
int count = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(RPIN, OUTPUT);
  pinMode(GPIN, OUTPUT);
  pinMode(BPIN, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
    Serial.println("HIGH");
    changeCount();
    delay(500);
  }
  setColor(0, 0, 0);
  buttonState = LOW;
  delay(100);
}

void changeCount()
{
  if (count == 0)
  {
    setColor(RED);
  }
  if (count == 1)
  {
    setColor(GREEN);
  }
  if (count == 2)
  {
    setColor(BLUE);
  }
  count++;
  if (count > 2)
    count = 0;
}

void setColor(int redValue, int greenValue, int blueValue)
{
  analogWrite(RPIN, redValue);
  analogWrite(GPIN, greenValue);
  analogWrite(BPIN, blueValue);
}