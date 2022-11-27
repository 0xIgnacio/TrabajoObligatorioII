#ifndef EXPEDIENTE_H_INCLUDED
#define EXPEDIENTE_H_INCLUDED

#include "escribano.h"

typedef struct {
  long codigo;
  string caratula;
  escribano datosEscri;
  int cantPaginas;
} expediente;

// Selectoras
long darCodigo(expediente e);
int darCantPaginas(expediente e);

// Cargar - Mostrar
void cargar(expediente &e);
void mostrar(expediente e);

// Archivos
void bajar(expediente e, FILE *a);
void levantar(expediente &e, FILE *a);

#endif