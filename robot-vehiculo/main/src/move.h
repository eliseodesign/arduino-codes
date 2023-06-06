// utils.h
#include <Arduino.h>

#ifndef MOVE_H
#define MOVE_H

String joinComando(String str1, String str2) {
  String resultado = str1 + " " + str2;
  return resultado;
}

String ObtenerMovimiento(String input) {
  String comando = "";

  String go = "i60f";
  String back = "i160f";
  if (input == "g") {
    comando = joinComando(go, go);
  }
  if (input == "b") {
    comando = joinComando(back, back);
  }
  if (input == "l") {
    comando = joinComando(back, go);
  }
  if (input == "r") {
    comando = joinComando(go, back);
  }

  return comando;
}



#endif
