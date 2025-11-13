#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8
int segPins[7] = {SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G};

byte led7Code[] = {
  0b11000000, // 0
  0b11111001, // 1
  0b10100100, // 2
  0b10110000, // 3
  0b10011001, // 4
  0b10010010, // 5
  0b10000010, // 6
  0b11111000, // 7
  0b10000000, // 8
  0b10010000  // 9
};

#define RED1     A0
#define YELLOW1  A1
#define GREEN1   A2
#define RED2     A3
#define YELLOW2  A4
#define GREEN2   A5
#define Button   9

bool buttonMode = false;   
bool lastButton = HIGH;    

void showNumber(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], bitRead(led7Code[num], i));
  }
}


void clear7Seg() {
  for (int i = 0; i < 7; i++)  digitalWrite(segPins[i], HIGH); }


void setup() {
  for (int i = 0; i < 7; i++) pinMode(segPins[i], OUTPUT);

  pinMode(RED1, OUTPUT);
  pinMode(YELLOW1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(YELLOW2, OUTPUT);
  pinMode(GREEN2, OUTPUT);

  pinMode(Button, INPUT_PULLUP);
}

void loop() {
  bool buttonState = digitalRead(Button);

 
  if (lastButton == HIGH && buttonState == LOW) {
    buttonMode = !buttonMode;   
    delay(200);                 
  lastButton = buttonState;

 
  if (buttonMode) {
    clear7Seg();
    digitalWrite(RED1, LOW);
    digitalWrite(GREEN1, LOW);
    digitalWrite(RED2, LOW);
    digitalWrite(GREEN2, LOW);

    digitalWrite(YELLOW1, HIGH);
    digitalWrite(YELLOW2, HIGH);
    delay(1000);

    digitalWrite(YELLOW1, LOW);
    digitalWrite(YELLOW2, LOW);
    delay(1000);
    return;
  }




  digitalWrite(RED1, HIGH);
  digitalWrite(GREEN2, HIGH);
  for (int i = 9; i >= 0; i--) {
    showNumber(i);
    delay(1000);
    if (digitalRead(Button) == LOW) return;
    if (i == 4) {
      digitalWrite(GREEN2, LOW);
      digitalWrite(YELLOW2, HIGH);
    }
  }

  digitalWrite(RED1, LOW);
  digitalWrite(YELLOW2, LOW);
  digitalWrite(GREEN2, LOW);

  digitalWrite(GREEN1, HIGH);
  digitalWrite(RED2, HIGH);
  for (int i = 7; i >= 0; i--) {
    showNumber(i);
    delay(1000);
    if (digitalRead(Button) == LOW) return;
  }

  digitalWrite(GREEN1, LOW);

  digitalWrite(YELLOW1, HIGH);
  for (int i = 3; i >= 0; i--) {
    showNumber(i);
    delay(1000);
    if (digitalRead(Button) == LOW) return;
  }

  digitalWrite(YELLOW1, LOW);
  digitalWrite(RED2, LOW);
  }}
