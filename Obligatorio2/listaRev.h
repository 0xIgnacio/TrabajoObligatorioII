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
boolean vacio(lista l);
void eliminar(lista &l, long codigo);
revision primero(lista l);

// Cargar - Mostrar
void cargar(lista &l, revision r); // Al principio
void mostrar(lista l);

// Busqueda
boolean existe(lista l, long codigo);
void mostrar(lista l, long codigo);
int cantSatis(lista l);
int cantIncomp(lista l);
int cantPend(lista l);
int periodo(lista l, fecha f, fecha g);
int cantRev(lista l, long codigo);
long expedienteMayorRev(lista l);

// Archivos
void bajar(lista e);
void levantar(lista &e);

#endif