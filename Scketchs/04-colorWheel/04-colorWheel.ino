#include <Encoder.h>

#define RPIN 52
#define GPIN 50
#define BPIN 48
#define DT_PIN 2
#define CLK_PIN 3

#define MAX_ENCODER_VALUE 300

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
  Serial.println(curPos);
  if (curPos >= 0 && curPos < regionSize)
  {
    setColor(RED);
  }
  else if (curPos >= regionSize && curPos < 2 * regionSize)
  {
    setColor(GREEN);
  }
  else if (curPos >= 2 * regionSize && curPos <= MAX_ENCODER_VALUE)
  {
    setColor(BLUE);
  }
}

void setColor(int redValue, int greenValue, int blueValue)
{
  analogWrite(RPIN, redValue);
  analogWrite(GPIN, greenValue);
  analogWrite(BPIN, blueValue);
}
