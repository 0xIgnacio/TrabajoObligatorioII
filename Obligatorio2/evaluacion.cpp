#include <stdio.h>
#include "evaluacion.h"

void cargar(evaluacion &e) {
  int x;
    printf("1. Satisfactoria\n2. Incompleta\n3. Pendiente\nIngrese: ");
      scanf("%d", &x);
    switch (x) {
      case 1:
        e = SATIS;
        break;
      case 2:
        e = INCOMP;
        break;
      case 3:
        e = PEND;
        break;
    }
}
void mostrar(evaluacion e) {
    if(e == SATIS)
      printf("Satisfactoria");
    else if(e == INCOMP)
      printf("Incompleta");
    else
      printf("Pendiente");
}

// Archivos
void bajar(evaluacion e, FILE *a) {
  fwrite(&e, sizeof(evaluacion), 1, a);
}
void levantar(evaluacion &e, FILE *a) {
  fread(&e, sizeof(evaluacion), 1, a);
}