#include <SoftwareSerial.h>  // Libreria para comunicacion serial
#include <Servo.h>           // Libreria para servomotor
#include "src/utils.h"           // Libreria para servomotor
#include "src/move.h"           // Libreria para servomotor

SoftwareSerial bluetooth(9, 10);  //(Tx(9),Rx(10)) para comunicacion serial
Servo left;                        // Nombramos al servomotor izquierdo como "left"
Servo right;                       // Nombramos al servomotor derecho como "right"
int grados_left = 0;                // Iniciamos en cero los grados del servomotor izquierdo
int grados_right = 0;               // Iniciamos en cero los grados del servomotor derecho

void setup() {
  Serial.begin(0);           // Habilitamos comunicacion serial
  bluetooth.begin(9600);        // Inicializamos la comunicacion con el HC-05
  left.attach(12);              // Pin de control para el servomotor izquierdo
  right.attach(11);             // Pin de control para el servomotor derecho
}

void loop() {
  if (bluetooth.available()) {  // Si hay datos disponibles en el Bluetooth
    String input = bluetooth.readString();  // Lee el string enviado por Bluetooth
   
    String comando = ObtenerMovimiento(input);
    int separador = comando.indexOf(' ');
    if (separador != -1) {
      grados_left = extraerGrados( comando.substring(0, separador) );    // Obtiene la parte del comando para left
      grados_left = extraerGrados( comando.substring(separador + 1) );  // Obtiene la parte del comando para right

      // Mueve los servomotores a las posiciones indicadas por grados_left y grados_right
      left.write(grados_left);
      right.write(grados_right);
    }
    
  }
}