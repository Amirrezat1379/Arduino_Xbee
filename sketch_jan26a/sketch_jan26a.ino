#include <Keypad.h>//add library

const byte ROWS = 4; //four rows //my keypad rows
const byte COLS = 4; //four columns // my keypad columns
char keys[ROWS][COLS] = { // all my key pad charecters
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'o', '0', '=', '+'}
};
byte rowPins[ROWS] = {22, 23, 24, 25}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {26, 27, 28, 29}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); // define new key pad

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int i = 1;

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
  if (Serial.available())
    if (Serial.read() == 'A')
      i = 1;
  if (key && i == 1) {
    Serial.write(key);
    i = 0;
  }
}
