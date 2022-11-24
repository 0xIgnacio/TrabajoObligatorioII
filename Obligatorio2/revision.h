#ifndef REVISION_H_INCLUDED
#define REVISION_H_INCLUDED

#include "fecha.h"
#include "evaluacion.h"
#include "string.h"

typedef struct {
  fecha realizado;
  string motivo;
  long codigoExp;
  evaluacion resultado;
} revision;

// Selectoras
revision darRevision(revision r);
fecha darFecha(revision r);
void darMotivo(revision r, string &s);
long darCodigoExp(revision r);
evaluacion darEvaluacion(revision r);

// Funcionalidades
long expMenor(long e, long f);

// Cargar -Mostrar
void cargar(revision &r);
void mostrar(revision r);

// Archivos
void bajar(revision e, FILE *a);
void levantar(revision e, FILE *a);

#endif