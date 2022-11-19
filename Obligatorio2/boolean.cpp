#include <stdio.h>
#include "boolean.h"

void cargar(boolean &b) {
  int valor;
    printf ("ingrese 0 para FALSE y 1 para TRUE: ");
      scanf ("%d",& valor);
    if (valor == 0)
      b = FALSE;
    else
    b = TRUE;
}
void mostrar(boolean b) {
    if (b)
      printf ("verdadero");
    else
      printf ("falso");
}

// ==================================================