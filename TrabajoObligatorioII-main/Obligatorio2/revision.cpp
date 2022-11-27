#include <stdio.h>
#include "revision.h"

// Selectoras
revision darRevision(revision r) {
  return r;
}
fecha darFecha(revision r) {
  return r.realizado;
}
void darMotivo(revision r, string &s) {
  strcop(s, r.motivo);
}
long darCodigoExp(revision r) {
  return r.codigoExp;
}
evaluacion darEvaluacion(revision r) {
  return r.resultado;
}

// Funcionalidades
long expMenor(long e, long f) {
  long mayor = e;
    if(e < f)
      mayor = f;
  return mayor;
}

// Cargar -Mostrar
void cargar(revision &r) {
  cargar(r.realizado);
    printf("Ingrese el motivo: ");
      scan(r.motivo);
    printf("Ingrese el codigo del expediente: ");
      scanf("%ld", &r.codigoExp);
  cargar(r.resultado);
}
void mostrar(revision r) {
  mostrar(r.realizado);
    printf(", ");
  print(r.motivo);
    printf(", %ld, ", r.codigoExp);
  mostrar(r.resultado);
}

// Archivos
void bajar(revision e, FILE *a) {
  bajar(e.realizado, a);
  bajar(e.motivo, a);
  fwrite(&e.codigoExp, sizeof(long), 1, a);
  bajar(e.resultado, a);
}
void levantar(revision &e, FILE *a) {
  levantar(e.realizado, a);
  levantar(e.motivo, a);
  fread(&e.codigoExp, sizeof(long), 1, a);
  levantar(e.resultado, a);
}
