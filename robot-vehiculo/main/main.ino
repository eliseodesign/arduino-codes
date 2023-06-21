#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bluetooth(9, 10);
Servo left;
Servo right;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  left.attach(12);
  right.attach(11);
}

void loop() {
  if (bluetooth.available()) {
    char input = bluetooth.read();

    int grados_left = 0;
    int grados_right = 0;

    if (input == 'g') {
      grados_left = 40;
      grados_right = 150;
    } 
    if (input == 'b') {
      grados_left = 150;
      grados_right = 50;
    }
    if (input == 'l') {
      grados_left = 50;
      grados_right = 50;
    }
    if (input == 'r') {
      grados_left = 150;
      grados_right = 150;
    }
    if (input == 's') {
      grados_left = 90;
      grados_right = 90;
    }
    
    // Mueve los servomotores a las posiciones indicadas por grados_left y grados_right
    left.write(grados_left);
    right.write(grados_right);
  }
}
