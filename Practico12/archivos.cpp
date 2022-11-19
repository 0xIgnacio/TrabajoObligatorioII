#include <stdio.h>
#include "archivos.h"

void agregar(string nomArch, int entero) {
  FILE *a = fopen(nomArch, "ab");
  fwrite(&entero, sizeof(int), 1, a);
  fclose(a);
}
boolean existe(string nomArch) {
  boolean existe = FALSE;
  FILE *a = fopen(nomArch, "rb");
    if(a == NULL)
      existe = TRUE;
  return existe;
}
boolean vacio(string nomArch) {
  boolean es = FALSE;
  FILE *a = fopen(nomArch, "rb");
  fseek(a, sizeof(int), SEEK_CUR);
    if(feof(a))
      es = TRUE;
  return es;
}
boolean pertenece(string nomArch, int entero) {
  boolean pert = FALSE;
  FILE *a = fopen(nomArch, "rb");
    while(!feof(a) && !pert) {
      int x;
      fread(&x, sizeof(int), 1, a);
        if(x == entero)
          pert = TRUE;
    }
  return pert;
}
int largo(string nomArch) {
  FILE *a = fopen(nomArch, "rb");
  fseek(a, sizeof(int), SEEK_END);
  int cant = ftell(a);
  return cant/sizeof(int);
}
int k_esimo(string nomArch, int k) {
  int x;
  FILE *a = fopen(nomArch, "rb");
  fseek(a, (k-1)*sizeof(int), SEEK_SET);
  fread(&x, sizeof(int), 1, a);
  return x;
}
void desplegar(string nomArch) {
  int x ;
  FILE *a = fopen(nomArch, "rb");
  fread(&x, sizeof(int), 1, a);
    while(!feof(a)) {
        printf("%d ", x);
      fread(&x, sizeof(int), 1, a);
    }
}

// ==================================================