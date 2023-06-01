// utils.h

#ifndef UTILS_H
#define UTILS_H

int extraerGrados(String comando) {
  int inicio = comando.indexOf('i') + 1;  // Busca el índice de 'i' en el comando
  int fin = comando.indexOf('f');         // Busca el índice de 'f' en el comando

  if (inicio != -1 && fin != -1 && fin > inicio) {
    String grados_str = comando.substring(inicio, fin);  // Extrae la parte del comando que contiene los grados
    return grados_str.toInt();  // Convierte los grados a entero y los retorna
  }

  return 0;  // Si no se pudo extraer los grados, retorna cero
}

#endif
