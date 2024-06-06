#include <Encoder.h>

#define RPIN 10
#define GPIN 9
#define BPIN 8
#define DT_PIN 2
#define CLK_PIN 3

#define MAX_ENCODER_VALUE 12

#define RED 255, 0, 0
#define GREEN 0, 255, 0
#define BLUE 0, 0, 255

Encoder myEncoder(CLK_PIN, DT_PIN);
int nRegions = 3;
int regionSize = MAX_ENCODER_VALUE / nRegions;
int lastPos;
int curPos = 0;

void setup()
{
  pinMode(RPIN, OUTPUT);
  pinMode(GPIN, OUTPUT);
  pinMode(BPIN, OUTPUT);

  lastPos = myEncoder.read();
  Serial.begin(9600);
}

void loop()
{
  readInput();
  checkRegion();
  delay(30);
}

void readInput()
{
  int newPos = myEncoder.read();
  if (newPos != lastPos)
  {
    Serial.println(curPos);
    if (curPos == 0 && newPos < lastPos)
    {
      curPos = MAX_ENCODER_VALUE;
    }
    else if (curPos == MAX_ENCODER_VALUE && newPos > lastPos)
    {
      curPos = 0;
    }
    else
    {
      if (newPos > lastPos)
        curPos++;
      else
        curPos--;
    }
    lastPos = newPos;
  }
}

void checkRegion()
{
  switch (curPos)
  {
  case 0: // RED
    setColor(255, 0, 0);
    break;
  case 1: // Orange
    setColor(255, 127, 0);
    break;
  case 2: // Yellow
    setColor(255, 255, 0);
    break;
  case 3: // Lime Green
    setColor(127, 255, 0);
    break;
  case 4: //  Green
    setColor(0, 255, 0);
    break;
  case 5: // Blue Green
    setColor(0, 255, 127);
    break;
  case 6: //  Cyan
    setColor(0, 255, 255);
    break;
  case 7: //  Azure
    setColor(0, 255, 127);
    break;
  case 8: //  Blue
    setColor(0, 0, 255);
    break;
  case 9: //  Violet
    setColor(127, 0, 255);
    break;
  case 10: //  Magenta
    setColor(255, 0, 255);
    break;
  case 11: //  Rose
    setColor(255, 0, 127);
    break;
  default:
    setColor(0, 0, 0);
    break;
  }
}

void setColor(int redValue, int greenValue, int blueValue)
{
  analogWrite(RPIN, redValue);
  analogWrite(GPIN, greenValue);
  analogWrite(BPIN, blueValue);
}
