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

// Archivos
void bajar(escribano e, FILE *a) {
  bajar(e.nombre, a);
  bajar(e.apellido, a);
}
void levantar(escribano &e, FILE *a) {
  levantar(e.nombre, a);
  levantar(e.apellido, a);
}