#include <SoftwareSerial.h>
#include <Servo.h>

int buzzerPin = 7;

String receivedString = ""; // Inicializa una cadena vacía para almacenar la línea recibida
// SoftwareSerial bluetooth(8,9); // pin RX, pin TX REMOVE
Servo left;
Servo right;

void setup() {
  // Inicializar el puerto serial a una velocidad de 57600 baudios
  Serial.begin(57600);
  left.attach(10);
  right.attach(11);
  pinMode(buzzerPin, OUTPUT); 
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read(); // Lee un carácter del puerto serial
    if (c == '\n') {
      // Si se recibe un salto de línea ('\n'), significa que se ha completado una línea
      Serial.println("received: " + receivedString); // Imprime la línea completa
      moveServo(receivedString);
      receivedString = ""; // Borra la cadena para la siguiente línea

    } else {
      receivedString += c; // Agrega el carácter a la cadena
    }
  }
}

void moveServo(String input){
  int grados_left = 90;
  int grados_right = 90;
    input.trim();
    Serial.println(input);
    Serial.println(input == "go");

    if (input == "go") {
      Serial.println("g");
      grados_left = 40;   //izquierdo
      grados_right = 150; //derecho
    }else if (input == "back") {
      Serial.println("b");
      grados_left = 150; //izquierdo
      grados_right = 50; //derecho
    }else if (input == "left") {
      Serial.println("l");
      grados_left = 50; //izquierdo
      grados_right = 50;//derecho
    }else if (input == "rigth") {
      Serial.println("r");
      grados_left = 150; //izquierdo
      grados_right = 150; //derecho
      
    }else if(input == "ok"){
      Serial.println("PIP");
      digitalWrite(buzzerPin, HIGH);
      delay(200);
      digitalWrite(buzzerPin, LOW);
    } else{
      grados_left = 90; //izquierdo
      grados_right = 90; //derecho
    }

    // Mueve los servomotores a las posiciones indicadas por grados_left y grados_right
    left.write(grados_left);
    right.write(grados_right);
}