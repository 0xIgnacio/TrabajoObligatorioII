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

// Cargar -Mostrar
void cargar(revision r) {
  cargar(r.realizado);
    printf("Ingrese el motivo: ");
      scan(r.motivo);
    printf("Ingrese el codigo del expediente: ");
      scanf("%ld", &r.codigoExp);
  cargar(r.resultado);
}
void mostrar(revision r) {
  mostrar(r.realizado);
    printf("\nMotivo: ");
  print(r.motivo);
    printf("\nCodigo de expediente: %ld", r.codigoExp);
  mostrar(r.resultado);
}