const int ROWS = 4;
const int COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {0, 1, 2, 3}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5, 6, 7}; // connect to the column pinouts of the keypad

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = getKey();
  if(key != 0) {
    Serial.println(key);
  }
  delay(100); // debounce delay
}

char getKey() {
  for (byte row = 0; row < ROWS; row++) {
    pinMode(rowPins[row], OUTPUT);
    digitalWrite(rowPins[row], HIGH);
    for (byte col = 0; col < COLS; col++) {
      pinMode(colPins[col], INPUT_PULLUP);
      if (digitalRead(colPins[col]) == LOW) {
        delay(50); // debounce delay
        while (digitalRead(colPins[col]) == LOW) {} // wait for key release
        return keys[row][col];
      }
    }
    pinMode(rowPins[row], INPUT); // set row pin back to input
    digitalWrite(rowPins[row], LOW); // set row pin low
  }
  return 0; // return 0 if no key is pressed
}