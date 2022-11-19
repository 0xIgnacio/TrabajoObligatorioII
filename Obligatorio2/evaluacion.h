#ifndef EVALUACION_H_INCLUDED
#define EVALUACION_H_INCLUDED

typedef enum {SATIS, INCOMP, PEND} evaluacion;

// Cargar - Mostrar
void cargar(evaluacion &e);
void mostrar(evaluacion e);

#endif