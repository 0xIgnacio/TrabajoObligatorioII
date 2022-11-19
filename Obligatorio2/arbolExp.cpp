#include <stdio.h>
#include "arbolExp.h"

// Base
void crear(arbol &a) {
  a = NULL;
}
boolean esVacio(arbol a) {
  boolean es = FALSE;
    if(a == NULL)
      es = TRUE;
  return es;
}
arbol hijoIzq(arbol a) {
  return a -> izq;
}
arbol hijoDer(arbol a) {
  return a -> der;
}
expediente darRaiz(arbol a) {
  return a -> info;
}
void cons(arbol i, arbol d, expediente e, arbol &a) {
  a = new nodoExp;
  a -> info = e;
  a -> izq = NULL;
  a -> der = NULL;
}

// Funcionalidades
int cantidad(arbol a, string s) {
  if(a == NULL)
    return 0;
  else {
    escribano e = a -> info.datosEscri;
      if(streq(e.apellido, s))
        return 1 + cantidad(a -> izq, s) + cantidad(a -> der, s);
      else
        return 0 + cantidad(a -> izq, s) + cantidad(a -> der, s);
  }
}

// Cargar - Mostrar
void borrarMinimo(arbol &a) {
    if(a -> izq == NULL) {
      arbol aux = a -> der;
      delete a;
      a = aux;
    }
    else
      borrarMinimo(a -> izq);
}
void borrarMaximo(arbol &a) {
    if(a -> der == NULL) {
      arbol aux = a -> izq;
      delete a;
      a = aux;
    }
    else
      borrarMaximo(a -> der);
}
void cargar(arbol &a, expediente e) {
    if(esVacio(a)) {
      a = new nodoExp;
      a -> info = e;
      a -> der = NULL;
      a -> izq = NULL;
    }
    else {
        if(e.codigo < darCodigo(a -> info))
          cargar(a -> izq, e);
        else
          cargar(a -> der, e);
    }
}
void borrar(arbol &a, long codigo) {
    if(codigo == darCodigo(a -> info)) {
        if(a -> izq == NULL) {
          arbol aux = a -> der;
          delete a;
          a = aux;
        }
        else {
            if(a -> der == NULL) {
              arbol aux = a -> izq;
              delete a;
              a = aux;
            }
            else {
              a -> info = menor(a -> der);
              borrarMinimo(a -> der);
            }
        }
    }
    else {
        if(codigo < darCodigo(a -> info))
          borrar(a -> izq, codigo);
        else
          borrar(a -> der, codigo);
    }
}
void mostrar(arbol a) {
    if(a != NULL) {
        mostrar(a -> izq);
        mostrar(a -> info);
        mostrar(a -> der);
    }
}

// Busqueda
boolean existe(arbol a, long codigo) {
    if(codigo == darCodigo(a->info)) {
      return TRUE;
    }
    else {
        if(a == NULL)
          return FALSE;
        else {
            if(codigo < darCodigo(a->info))
              return existe(a -> izq, codigo);
            else
              return existe(a -> der, codigo);
        }
    }
}
expediente mayor(arbol a) {
    if(a -> der == NULL)
      return a -> info;
    else
      return mayor(a -> der);
}
expediente menor(arbol a) {
    if(a -> izq == NULL)
      return a -> info;
    else
      return menor(a -> izq);
}