#include <stdio.h>
#include "escribano.h"

// Seectoras
void darApellido(escribano es, string &s){
  strcop(s, es.apellido);
}

// Cargar - Mostrar
void cargar(escribano &es){
 
    printf("Ingrese el nombre del escribano: ");
  scan(es.nombre);
    printf("Ingrese el apellido del escribano: ");
  scan(es.apellido);
}
void mostrar(escribano es){
  print(es.nombre);
    printf(" ");
  print(es.apellido);
}