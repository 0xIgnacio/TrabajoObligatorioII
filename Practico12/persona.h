#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "string.h"

typedef struct {
  string nombre;
  int edad;
  long cedula;
} persona;

// ================ Operaciones base ================
void crear(persona &a);
void darNombre(string &str, persona a);
int darEdad(persona a);
long darCedula(persona a);

// ============== Operaciones archivos ==============
void guardar(persona a, FILE *f);

#endif // PERSONA_H_INCLUDED
