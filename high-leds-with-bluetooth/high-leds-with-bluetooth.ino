#include <SoftwareSerial.h> // Libreria para comunicacion serial

SoftwareSerial bluetooth(2, 3); //(Tx(9),Rx(10))para comunicacion serial

char Letra;

const int led = 8; //creamos la constante “led”
const int led2 = 9; //creamos la constante “led”

void setup() {

pinMode(led, OUTPUT);

Serial.begin(9600); // habilitamos comunicacion serial

bluetooth.begin(9600); // inicializamos la comunicacion con el HC-05

}

void loop() { //encendemos y apagamos el led

if (bluetooth.available()) { // si encuentras un valor

Letra = bluetooth.read(); // guarda ese valor en Letra

Serial.println(Letra);

if (Letra == '1') { //Si Letra es igual a i esto es = 0

Serial.println(Letra); // imprimiremos inicio en monitor serie

digitalWrite(led, HIGH);

} else if (Letra == '2') { // si llega un f los grados estan listos

Serial.println(Letra); // imprimiremos los grados que se movio
  
digitalWrite(led, LOW);

} else if (Letra == '3') { // si llega un f los grados estan listos

Serial.println(Letra); // imprimiremos los grados que se movio

digitalWrite(led2, HIGH);

}else if (Letra == '4') { // si llega un f los grados estan listos

Serial.println(Letra); // imprimiremos los grados que se movio

digitalWrite(led2, LOW);

}

}

}