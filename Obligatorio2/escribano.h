#ifndef ESCRIBANO_H_INCLUDED
#define ESCRIBANO_H_INCLUDED

#include "string.h"

typedef struct {
  string nombre;
  string apellido;
} escribano;

// Selectoras
void darApellido(escribano es, string &s);

// Cargar - Mostrar
void cargar(escribano es);
void mostrar(escribano es);

#endif