#include <stdio.h>
#include "expediente.h"

//Selectoras
long darCodigo(expediente e) {
  return e.codigo;
}
int darCantPaginas(expediente e) {
  return e.cantPaginas;
}

//  Cargar - Mostrar
void cargar(expediente &e) {
    printf("Ingrese el codigo del expediente: ");
      scanf("%ld", &e.codigo);
    printf("Ingrese la caratula: ");
  scan(e.caratula);
  cargar(e.datosEscri);
    printf("Ingrese la cantidad de paginas: ");
      scanf("%d", &e.cantPaginas);
}
void mostrar(expediente e) {
    printf("%ld, ", e.codigo);
  print(e.caratula);
    printf(", ");
  mostrar(e.datosEscri);
    printf(", %d\n", e.cantPaginas);
}

// Archivos
void bajar(expediente e, FILE *a) {
  fwrite(&e.codigo, sizeof(long), 1, a);
  bajar(e.caratula, a);
  bajar(e.datosEscri, a);
  fwrite(&e.cantPaginas, sizeof(int), 1, a);
}
void levantar(expediente &e, FILE *a) {
  fread(&e.codigo, sizeof(long), 1, a);
  levantar(e.caratula, a);
  levantar(e.datosEscri, a);
  fread(&e.cantPaginas, sizeof(int), 1, a);
}