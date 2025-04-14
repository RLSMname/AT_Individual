#define LED_COUNT 3

const int ledPins[LED_COUNT] = {10, 11, 12};
const int btnPins[LED_COUNT] = {2, 3, 4};

int sequence[100];
int currentLength = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(btnPins[i], INPUT_PULLUP);  
  }
  randomSeed(analogRead(A0));  
  delay(1000);
  nextRound();  
}

void loop() {
  playSequence();
  if (!getPlayerInput()) {
    gameOver();
  } else {
    delay(500);
    nextRound();
  }
}

void nextRound() {
  sequence[currentLength] = random(0, LED_COUNT);
  currentLength++;
}

void playSequence() {
  for (int i = 0; i < currentLength; i++) {
    flashLED(sequence[i]);
    delay(300);
  }
}

bool getPlayerInput() {
  for (int i = 0; i < currentLength; i++) {
    int input = waitForButtonPress();
    if (input != sequence[i]) {
      return false;
    }
  }
  return true;
}

int waitForButtonPress() {
  while (true) {
    for (int i = 0; i < LED_COUNT; i++) {
      if (digitalRead(btnPins[i]) == LOW) {
        flashLED(i);  // Feedback
        while (digitalRead(btnPins[i]) == LOW);  
        return i;
      }
    }
  }
}

void flashLED(int index) {
  digitalWrite(ledPins[index], HIGH);
  delay(250);
  digitalWrite(ledPins[index], LOW);
}

void gameOver() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < LED_COUNT; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(200);
    for (int j = 0; j < LED_COUNT; j++) {
      digitalWrite(ledPins[j], LOW);
    }
    delay(200);
  }
  currentLength = 0;
  delay(1000);
  nextRound();  
}
