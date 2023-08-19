#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bluetooth(9, 10);
Servo left;
Servo right;

bool stopServo = false; // Variable para controlar el estado de detención del servomotor
int servoStoppedCount = 0; // Contador de veces que se ha presionado '3'

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);


}

void loop() {
  if (bluetooth.available()) {
    char input = bluetooth.read();
    Serial.print(input);

    int grados_left = 0;
    int grados_right = 0;

    if (input == '1') {
      grados_left = 40;   //izquierdo
      grados_right = 150; //derecho
    } 
    if (input == '2') {
      grados_left = 150; //izquierdo
      grados_right = 50; //derecho
    }
    if (input == '4') {
      grados_left = 50; //izquierdo
      grados_right = 50;//derecho
    }
    if (input == '3') {
      servoStoppedCount++;
      
      if (servoStoppedCount == 3) {
        stopServo = !stopServo; // Cambiar el estado de detención del servomotor
        servoStoppedCount = 0; // Reiniciar el contador
      }
      
      if (stopServo) {
        grados_left = 90; // Detener el servomotor en una posición neutral
        grados_right = 90;
      } else {
        grados_left = 150; //izquierdo
        grados_right = 150; //derecho
      }
    }
    if (input == '5') {
      grados_left = 90;
      grados_right = 90;
    }
    
    // Mueve los servomotores a las posiciones indicadas por grados_left y grados_right
    left.write(grados_left);
    right.write(grados_right);
  }
}