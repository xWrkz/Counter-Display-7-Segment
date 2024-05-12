const int sensorPin = 9;
const int displayPins[] = {2, 3, 4, 5, 6, 7, 8}; // Array para los pines del display
const int numDigits = 10;
int count = 0;

// Definición de los números para el display de 7 segmentos
const byte digits[numDigits][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(displayPins[i], OUTPUT);
  }
}

void displayDigit(int digit) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(displayPins[i], digits[digit][i]);
  }
}

void loop() {
  int value = digitalRead(sensorPin);
  if (value == LOW) {
    count++;
    if (count >= numDigits) {
      count = 0;
    }
    Serial.println(count);
    displayDigit(count);
    delay(1000); // Delay para evitar el parpadeo en el display
  }
}