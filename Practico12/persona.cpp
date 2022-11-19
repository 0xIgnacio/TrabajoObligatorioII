#include <stdio.h>
#include "persona.h"

// ================ Operaciones base ================
void crear(persona &a) {
    printf("Ingresa el nombre de la persona: ");
      scan(a.nombre);
    printf("\nIngrese la edad de la persona: ");
      scanf("%d", &a.edad);
    printf("\nIngrese la cedula de la persona: ");
      scanf("%ld", &a.cedula);
}
void darNombre(string &str, persona a) {
  strcop(str, a.nombre);
}
int darEdad(persona a) {
  return a.edad;
}
long darCedula(persona a) {
  return a.cedula;
}

// ============== Operaciones archivos ==============


// ==================================================