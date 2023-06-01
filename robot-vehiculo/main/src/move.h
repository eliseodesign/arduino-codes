// utils.h
#include <Arduino.h>

#ifndef MOVE_H
#define MOVE_H

String ObtenerMovimiento(String input) {
  String comando = "";  // Lee el string enviado por Bluetooth

    String go = "i70f";
    String back = "i170f";
    if(input == "go"){
      comando = joinComando(go,go);
    }else if(comando == "back"){
      comando = joinComando(back,back);
    }else if(comando == "left"){
      comando = joinComando(back,go);
    }else if(comando == "right"){
      comando = joinComando(go,back);
    }

  return comando;
}

#endif
