#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include "string.h"

void agregar (string nomArch, int entero);
boolean existe (string nomArch);
boolean vacio (string nomArch);
boolean pertenece (string nomArch, int entero);
int largo (string nomArch);
int k_esimo (string nomArch, int k);
void desplegar (string nomArch);

#endif