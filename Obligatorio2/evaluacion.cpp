#include <stdio.h>
#include "evaluacion.h"

void cargar(evaluacion &e) {
  int x;
    printf("1. Satisfactoria\n2. Incompleta\n3. Pendiente\nIngrese: ");
      scanf("%d", &x);
    if(x == 1)
      e == SATIS;
    else if(x == 2)
      e == INCOMP;
    else
      e == PEND;
}
void mostrar(evaluacion e) {
    if(e == SATIS)
      printf("satisfactoria");
    else if(e == INCOMP)
      printf("incompleta");
    else
      printf("pendiente");
}