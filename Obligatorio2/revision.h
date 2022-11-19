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

// Cargar -Mostrar
void cargar(revision r);
void mostrar(revision r);

#endif