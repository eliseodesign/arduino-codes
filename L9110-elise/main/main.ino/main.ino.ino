#include <SoftwareSerial.h>

int INA = 6;
int INB = 5;

SoftwareSerial bluetooth(9, 10);

void setup()
{
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  if (bluetooth.available())
  {
    char input = bluetooth.read();
    Serial.println(input);

    if (input == '1')
    {
      Serial.print("Received: ");
      Serial.println(input);

      analogWrite(INA, 400); // Establecer velocidad máxima hacia adelante
      digitalWrite(INB, LOW); // Dirección hacia adelante
    }
    else if (input == '2')
    {
      Serial.print("Received: ");
      Serial.println(input);

      analogWrite(INA, 0);   // Detener motor
      digitalWrite(INB, LOW); // Mantener freno bajo
    }
    // Añade más condiciones aquí para manejar otros comandos si es necesario
  }
}
