int trigPin = 12;
int echoPin = 11;
int ledPin = 13;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  if (distance < 100) {
    Serial.println(distance);
    digitalWrite(ledPin, HIGH);
    delay(50);
  }
    digitalWrite(ledPin, LOW);
}