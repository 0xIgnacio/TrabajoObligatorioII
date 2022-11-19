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
    printf("\nIngrese la caratula: ");
  scan(e.caratula);
  cargar(e.datosEscri);
    printf("\nIngrese la cantidad de paginas: ");
      scanf("%d", &e.cantPaginas);
}
void mostrar(expediente e) {
    printf("\n%ld, ", e.codigo);
  print(e.caratula);
    printf(", ");
  mostrar(e.datosEscri);
    printf(", %d\n", e.cantPaginas);
}