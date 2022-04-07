#include <LiquidCrystal.h>

const int rs = 21, en = 20, d4 = 17, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int i = 0, j = 0, k = 0;
int playBoard[3][3];
char undo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 4);
  clearPlayBoard();
}

int playerNumber = 1;

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    lcd.clear();
    k++;
    char character = Serial.read();
    //    lcd.print(character);
    if (character == '1')
      playBoard[0][2] = playerNumber;
    else if (character == '2')
      playBoard[1][2] = playerNumber;
    else if (character == '3')
      playBoard[2][2] = playerNumber;
    else if (character == '4')
      playBoard[0][1] = playerNumber;
    else if (character == '5')
      playBoard[1][1] = playerNumber;
    else if (character == '6')
      playBoard[2][1] = playerNumber;
    else if (character == '7')
      playBoard[0][0] = playerNumber;
    else if (character == '8')
      playBoard[1][0] = playerNumber;
    else if (character == '9')
      playBoard[2][0] = playerNumber;
    else if (character == '0')
      undoGame();
    undo = character;
    printGame();
    if (playerNumber == 1) {
      Serial.write('B');
      playerNumber = 2;
    }
    else if (playerNumber == 2) {
      Serial.write('A');
      playerNumber = 1;
    }
    checkWin();
  }
}

void undoGame() {
  if (undo == '1')
    playBoard[0][2] = 0;
  else if (undo == '2')
    playBoard[1][2] = 0;
  else if (undo == '3')
    playBoard[2][2] = 0;
  else if (undo == '4')
    playBoard[0][1] = 0;
  else if (undo == '5')
    playBoard[1][1] = 0;
  else if (undo == '6')
    playBoard[2][1] = 0;
  else if (undo == '7')
    playBoard[0][0] = 0;
  else if (undo == '8')
    playBoard[1][0] = 0;
  else if (undo == '9')
    playBoard[2][0] = 0;

}

void clearPlayBoard() {
  for (j = 0; j < 3; j++) {
    for (i = 0; i < 3; i++) {
      playBoard[i][j] = 0;
    }
  }
  Serial.write('A');
  playerNumber = 1;
}

void checkWin() {
  if (playBoard[0][0] == playBoard[0][1] && playBoard[0][0] == playBoard[0][2] && playBoard[0][0] != 0) {
    lcd.clear();
    lcd.write("Player");
    char c = playBoard[0][0] + 48;
    lcd.write(c);
    lcd.write("Win :)");
    clearPlayBoard();
  }
  if (playBoard[0][0] == playBoard[1][0] && playBoard[0][0] == playBoard[2][0] && playBoard[0][0] != 0) {
    lcd.clear();
    lcd.write("Player");
    char c = playBoard[0][0] + 48;
    lcd.write(c);
    lcd.write("Win :)");
    clearPlayBoard();
  }
  if (playBoard[1][1] == playBoard[0][0] && playBoard[1][1] == playBoard[2][2] && playBoard[1][1] != 0) {
    lcd.clear();
    lcd.write("Player");
    char c = playBoard[1][1] + 48;
    lcd.write(c);
    lcd.write("Win :)");
    clearPlayBoard();
  }
  if (playBoard[1][1] == playBoard[0][1] && playBoard[1][1] == playBoard[2][1] && playBoard[1][1] != 0) {
    lcd.clear();
    lcd.write("Player");
    char c = playBoard[1][1] + 48;
    lcd.write(c);
    lcd.write("Win :)");
    clearPlayBoard();
  }
  if (playBoard[1][1] == playBoard[1][2] && playBoard[1][1] == playBoard[1][2] && playBoard[1][1] != 0) {
    lcd.clear();
    lcd.write("Player");
    char c = playBoard[1][1] + 48;
    lcd.write(c);
    lcd.write("Win :)");
    clearPlayBoard();
  }
  if (playBoard[1][1] == playBoard[0][2] && playBoard[1][1] == playBoard[2][0] && playBoard[1][1] != 0) {
    lcd.clear();
    lcd.write("Player");
    char c = playBoard[1][1] + 48;
    lcd.write(c);
    lcd.write("Win :)");
    clearPlayBoard();
  }
  if (playBoard[2][2] == playBoard[1][2] && playBoard[2][2] == playBoard[0][2] && playBoard[2][2] != 0) {
    lcd.clear();
    lcd.write("Player");
    char c = playBoard[2][2] + 48;
    lcd.write(c);
    lcd.write("Win :)");
    clearPlayBoard();
  }
  if (playBoard[2][2] == playBoard[2][1] && playBoard[2][2] == playBoard[2][0] && playBoard[2][2] != 0) {
    lcd.clear();
    lcd.write("Player");
    char c = playBoard[2][2] + 48;
    lcd.write(c);
    lcd.write("Win :)");
    clearPlayBoard();
  }
}

void printGame() {
  for (j = 0; j < 3; j++) {
    for (i = 0; i < 3; i++) {
      if (playBoard[i][j] == 1)
        lcd.print('X');
      else if (playBoard[i][j] == 2)
        lcd.print('O');
      else
        lcd.print(' ');
    }
    lcd.setCursor(0, j + 1);
  }
}
