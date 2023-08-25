#include <Servo.h>

int trigPin = 8;
int echoPin = 9;
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

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  if (distance < 10) { // Si hay un objeto cercano
    Serial.println(distance);
    digitalWrite(ledPin, HIGH);

    // Detener el movimiento
    myservo1.write(90); // Ángulo de 90 grados (posición central)
    myservo2.write(90); // Ángulo de 90 grados (posición central)

    delay(500);

    myservo1.write(0); //Retroceso
    myservo2.write(189); // Retroceso
    delay(2000);

    bool espacio = false;

    while (!espacio) { // se puede avanzar
      Serial.println("While");
      // girar hasta estar despejado el camino
      myservo1.write(180);
      myservo2.write(180);
      delay(500);

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

  } else { // Si no hay un objeto cercano
    digitalWrite(ledPin, LOW);

    // Avanzar recto
    myservo1.write(180); // Ángulo de 180 grados (máxima velocidad hacia adelante)
    myservo2.write(0);   // Ángulo de 0 grados (máxima velocidad hacia adelante)
  }
}
