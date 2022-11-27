#include <stdio.h>
#include "listaRev.h"

// Base
void crear(lista &l) {
  l = NULL;
}
boolean vacio(lista l) {
  boolean es = FALSE;
    if(l == NULL)
      es = TRUE;
  return es;
}
void eliminar(lista &l, long codigo){
    if(l!=NULL){
        if(codigo == darCodigoExp(l -> info)){
          lista aux = l;
          l = l -> sig;
          delete aux;
          eliminar(l, codigo);
        }
        else
          eliminar(l -> sig, codigo);
    }
}
revision primero(lista l) {
  return l -> info;
}

// Cargar - Mostrar
void cargar(lista &l, revision r) {
  lista aux = new nodoRev;
  aux -> info = r;
  aux -> sig = l;
  l = aux;
}
void mostrar(lista l) {
    if(!vacio(l)) {
      mostrar(l -> info);
        printf("\n");
      mostrar(l -> sig);
    }
}

// Busqueda
boolean existe(lista l, long codigo) {
    if(!vacio(l)) {
        if(darCodigoExp(l -> info) == codigo)
          return TRUE;
        else
          return existe(l -> sig, codigo);
    }
}
void mostrar(lista l, long codigo) {
    if(!vacio(l)) {
        if(darCodigoExp(l -> info) == codigo) {
            printf("\n");
          mostrar(l -> info);
        }
        mostrar(l -> sig, codigo);
    }
}
int cantSatis(lista l) {
    if(vacio(l))
      return 0;
    else {
        if(darEvaluacion(l -> info) == SATIS)
          return 1 + cantSatis(l -> sig);
        else
          return cantSatis(l -> sig);
    }
}
int cantIncomp(lista l) {
    if(vacio(l))
      return 0;
    else {
        if(darEvaluacion(l -> info) == INCOMP)
          return 1 + cantIncomp(l -> sig);
        else
          return cantIncomp(l -> sig);
    }
}
int cantPend(lista l) {
    if(vacio(l))
      return 0;
    else {
        if(darEvaluacion(l -> info) == PEND)
          return 1 + cantPend(l -> sig);
        else
          return cantPend(l -> sig);
    }
}
int periodo(lista l, fecha f, fecha g) {
    if(vacio(l))
      return 0;
    else {
        if(periodo(f, g, darFecha(l -> info)))
          return 1 + periodo(l, f, g);
        else
          return periodo(l, f, g);
    }
}
int cantRev(lista l, long codigo) {
    if(!vacio(l)) {
        if(darCodigoExp(l -> info) == codigo)
          return 1 + cantRev(l -> sig, codigo);
        else
          return cantRev(l -> sig, codigo);
    }
}
long expedienteMayorRev(lista l) {
    if(!vacio(l)) {
        if(cantRev(l, darCodigoExp(l -> info)) > cantRev(l -> sig, darCodigoExp(l -> info)))
          return darCodigoExp(l -> info);
        else {
            if(cantRev(l, darCodigoExp(l -> info)) == cantRev(l -> sig, darCodigoExp(l -> info)))
              return expMenor(darCodigoExp(l -> info), darCodigoExp(l -> sig -> info));
            else
              return darCodigoExp(l -> sig -> info);
        }
    }
}

// Archivos
void bajar(lista e) {
  FILE *f = fopen("revisiones.dat", "wb");
    while(!vacio(e)) {
      bajar(e -> info, f);
      e = e -> sig;
    }
  fclose(f);
}
void levantar(lista &e) {
  FILE *f = fopen("revisiones.dat", "rb");
  revision r;
  crear(e);
  if(f!=NULL) {
    levantar(r, f);
    while(!feof(f)) {
      cargar(e, r);
      levantar(r, f);
    }
  }
  fclose(f);
}