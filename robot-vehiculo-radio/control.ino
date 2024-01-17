int Xpin = A0;
int Ypin = A1;
int btnPin = 7;
int xVal;
int yVal;
int btnVal;

void setup() {
  pinMode(Xpin, INPUT);
  pinMode(Ypin, INPUT);
  pinMode(btnPin, INPUT_PULLUP); // Usar resistencia pull-up interna
  Serial.begin(57600);

}

void loop() {
  xVal = analogRead(Xpin);
  yVal = analogRead(Ypin);
  btnVal = digitalRead(btnPin);

  if (xVal < 450) {
    Serial.println("left");
  } else if (xVal > 600) {
    Serial.println("rigth");
  }else if (yVal < 450) {
    Serial.println("go");
  } else if (yVal > 600) {
    Serial.println("back");
  }else if (btnVal == LOW) {
    Serial.println("ok");
  }else{

    Serial.println("none");
  }

  delay(100);
}