#ifndef LISTAREV_H_INCLUDED
#define LISTAREV_H_INCLUDED

#include "revision.h"

typedef struct nodoR {
  revision info;
  nodoR *sig;
} nodoRev;

typedef nodoRev *lista;

// Base
void crear(lista &l);
boolean esVacia(lista l);
void eliminar(lista &l);

// Busqueda



#endif