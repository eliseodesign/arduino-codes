#include <SoftwareSerial.h>  // Libreria para comunicacion serial
#include <Servo.h>           // Libreria para servomotor

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
    String comando = bluetooth.readString();  // Lee el string enviado por Bluetooth

    // Divide el string en dos partes para left y right
    int separador = comando.indexOf(' ');
    if (separador != -1) {
      String comando_left = comando.substring(0, separador);    // Obtiene la parte del comando para left
      String comando_right = comando.substring(separador + 1);  // Obtiene la parte del comando para right

      // Extrae los grados de los comandos para left y right
      grados_left = extraerGrados(comando_left);
      grados_right = extraerGrados(comando_right);

      // Mueve los servomotores a las posiciones indicadas por grados_left y grados_right
      left.write(grados_left);
      right.write(grados_right);
    }
  }
}

int extraerGrados(String comando) {
  int inicio = comando.indexOf('i') + 1;  // Busca el índice de 'i' en el comando
  int fin = comando.indexOf('f');         // Busca el índice de 'f' en el comando

  if (inicio != -1 && fin != -1 && fin > inicio) {
    String grados_str = comando.substring(inicio, fin);  // Extrae la parte del comando que contiene los grados
    return grados_str.toInt();  // Convierte los grados a entero y los retorna
  }

  return 0;  // Si no se pudo extraer los grados, retorna cero
}
