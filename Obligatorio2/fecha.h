#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include "boolean.h"

typedef struct {
  int dia;
  int mes;
  int anio;
} fecha;

// Selectoras
int darDia(fecha f);
int darMes(fecha f);
int darAnio(fecha f);

// Cargar - Mostrar
void cargar(fecha &f);
void mostrar(fecha f);

// Funcionalidades
boolean menor(fecha f, fecha g); // Si f < g
boolean iguales(fecha f, fecha g);
boolean valida(fecha f);

#endif