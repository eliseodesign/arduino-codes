#include <Servo.h>

int trigPin = 9;
int echoPin = 10;
int ledPin = 13;
int servoPin1 = 7; // Pin del primer servo
int servoPin2 = 6; // Pin del segundo servo
Servo myservo1;    // Objeto del primer servo
Servo myservo2;    // Objeto del segundo servo

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  myservo1.attach(servoPin1); // Inicializar el primer servo en el pin especificado
  myservo2.attach(servoPin2); // Inicializar el segundo servo en el pin especificado
  Serial.begin(9600);
}

int getDistance() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

void loop() {
  delay(100);
  int distance = getDistance();

  Serial.println(distance);
  if (distance < 15) { // Si hay un objeto cercano
    // Detener el movimiento
    myservo1.write(90); // Ángulo de 90 grados (posición central)
    myservo2.write(90); // Ángulo de 90 grados (posición central)

    delay(500);


    bool espacio = false;

    while (!espacio) { // se puede avanzar
      Serial.println("While");
      // girar hasta estar despejado el camino
      myservo1.write(30);
      myservo2.write(30);
      delay(700);

      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      long duration = pulseIn(echoPin, HIGH);
      int distance = duration * 0.034 / 2;

      if (distance > 10) {
        espacio = true; // habilitar para avanzar
      }
    }

    // Detener el movimiento después de encontrar espacio
    myservo1.write(90); // Ángulo de 90 grados (posición central)
    myservo2.write(90); // Ángulo de 90 grados (posición central)
    delay(1000);
    return;

  } 
  digitalWrite(ledPin, LOW);

  // Avanzar recto
  myservo1.write(150); // Ángulo de 180 grados (máxima velocidad hacia adelante)
  myservo2.write(30);   // Ángulo de 0 grados (máxima velocidad hacia adelante)
}