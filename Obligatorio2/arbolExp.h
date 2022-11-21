#ifndef ARBOLEXP_H_INCLUDED
#define ARBOLEXP_H_INCLUDED

#include "expediente.h"

typedef struct nodoE {
  expediente info;
  nodoE *izq;
  nodoE *der;
} nodoExp;

typedef nodoExp *arbol;

// Base
void crear(arbol &a);
boolean vacio(arbol a);
arbol hijoIzq(arbol a);
arbol hijoDer(arbol a);
expediente darRaiz(arbol a);
void cons(arbol i, arbol d, expediente e, arbol &a);

// Funcionalidades
int cantidad(arbol a, string s);

// Cargar - Mostrar - Borrar
void borrarMinimo(arbol &a);
void borrarMaximo(arbol &a);
void cargar(arbol &a, expediente e); // Precondición: que no exista
void borrar(arbol &a, long codigo); // Precondición: que exista
void mostrar(arbol a);

// Busqueda
boolean existe(arbol a, long codigo);
expediente mayor(arbol a);
expediente menor(arbol a);

#endif