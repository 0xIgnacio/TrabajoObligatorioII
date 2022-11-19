#include <stdio.h>
#include "listaRev.h"

void crear(lista &l) {
  l = NULL;
}
boolean esVacia(lista l) {
  boolean es = FALSE;
    if(l == NULL)
      es = TRUE;
  return es;
}
void eliminar(lista &l, long codigo) {
  lista aux = l, aux2;
    while(aux != NULL) {
        if(darCodigoExp(aux -> info) == codigo) {
          aux2 = aux -> sig;
          delete aux;
          aux = aux2;
        }
      aux = aux -> sig;
    }
}