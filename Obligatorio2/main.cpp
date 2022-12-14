#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "arbolExp.h"
#include "listaRev.h"

int main() {
  int menuP, menuCB, menuL, menuC;
  lista rev; // Revisiones
  rev = NULL;
  levantar(rev);
  arbol exp; // Expedientes
  exp = NULL;
  levantar(exp);
    do {
      system("cls");
      menuPrincpial();
      scanf("%d", &menuP);
        while(menuP < 0 || menuP > 4) {
            printf("\n\nNumero invalido, ingrese denuevo: ");
              scanf("%d", &menuP);
        }
        switch(menuP) {
          case 1: //* Menu Cargar/Borrar
              do {
                system("cls");
                menuCargarBorrar();
                scanf("%d", &menuCB);
                  while(menuCB < 0 || menuCB > 4) {
                      printf("\n\nNumero invalido, ingrese denuevo: ");
                        scanf("%d", &menuCB);
                  }
                  switch(menuCB) {
                    case 1: //* Nuevo expediente
                      system("cls");
                      expediente e;
                      cargar(e); // Cargo el expediente a la variable "e"
                        if(!existe(exp, e.codigo)) {
                          cargar(exp, e); // Si no existe cargo "e" al arbol de expedientes
                            printf("\nExpediente cargado correctamente\n\n");
                        }
                        else
                          printf("\nEse codigo de expediente ya existe, volviendo al menu\n\n");
                      system("pause");
                      break;
                    case 2: //* Nueva revision
                      system("cls");
                      revision r;
                      cargar(r); // Cargo la revision a la variable "r"
                        if(existe(exp, darCodigoExp(r))) {
                            if(vacio(rev)) {
                              cargar(rev, r); // Si el expediente existe y la lista es vacia, cargo la revision
                                printf("\nRevision del expediente \"%ld\" cargada correctamente\n\n", darCodigoExp(r));
                            }
                            else {
                                if(menor(darFecha(rev -> info),darFecha(r))) {
                                  cargar(rev, r); // Si el expediente existe y fecha es menor, cargo la revision
                                    printf("\nRevision del expediente \"%ld\" cargada correctamente\n\n", darCodigoExp(r));
                                }
                                else
                                    printf("\nError al cargar revision, la fecha de la nueva revision tiene que ser mayor a la anterior, volviendo al menu\n\n");
                            }
                        }
                        else
                            printf("\nError al cargar revision, el codigo de expediente no existe, volviendo al menu\n\n");
                      system("pause");
                      break;
                    case 3: //* Borrar expediente y revisiones del mismo
                      system("cls");
                      long c;
                        printf("Ingresa el codigo del expediente que quieras eliminar: ");
                          scanf("%ld", &c);
                        if(existe(exp, c)) {
                          borrar(exp, c); // Si el expediente existe, lo borro
                          eliminar(rev, c);
                            printf("El expediente y sus revisiones fueron borrados\n\n");
                        }
                        else
                            printf("Error al borrar expediente, el mismo no existe, volviendo al menu\n\n");
                      system("pause");
                      break;
                  }
              } while(menuCB != 4); //! Si se ingresa 4 se vuelve al menu principal
            break;
          case 2: //* Listados
              do {
                system("cls");
                menuListados();
                scanf("%d", &menuL);
                  while(menuL < 0 || menuL > 5) {
                      printf("\n\nNumero invalido, ingrese denuevo: ");
                        scanf("%d", &menuL);
                  }
                  switch(menuL) {
                    case 1: //* Listar expedientes
                      system("cls");
                        if(vacio(exp))
                          printf("No hay expedientes revisados aun\n\n");
                        else {
                            printf("Lista de expedientes: codigo, caratula, escribano, cantidad de paginas\n\n");
                          mostrar(exp);
                            printf("\n");
                        }
                      system("pause");
                      break;
                    case 2: //* Listar expediente con el mayor y el expediente con menor numero
                      system("cls");
                        if(vacio(exp))
                          printf("Aun no hay expedientes");
                        else {
                            printf("\nExpediente con mayor codigo: \n");
                          mostrar(mayor(exp));
                            printf("\n\nExpediente con menor codigo: \n");
                          mostrar(menor(exp));
                        }
                        printf("\n\n");
                      system("pause");
                      break;
                    case 3: //* Listar revisiones
                      system("cls");
                        if(vacio(rev))
                          printf("No hay expedientes registrados aun\n\n");
                        else {
                            printf("Lista de expedientes: DD/MM/AAAA, motivo, codigo expediente, evaluacion\n\n");
                          mostrar(rev);
                            printf("\n");
                        }
                      system("pause");
                      break;
                    case 4: //* Listar revisiones segun codigo de expediente
                      system("cls");
                      long c;
                        printf("Ingresa el codigo del expediente para ver sus revisiones: ");
                          scanf("%d", &c);
                        if(existe(rev, c))
                          mostrar(rev, c);
                        else
                          printf("\nError, el codigo no existe o el mismo no tiene revisiones, volviendo al menu\n");
                        printf("\n\n");
                      system("pause");
                      break;
                  }
              } while(menuL != 5); //! Si se ingresa 5 se vuelve al menu principal
            break;
          case 3: //* Consultas
              do {
                system("cls");
                menuConsultas();
                scanf("%d", &menuC);
                  while(menuC < 0 || menuC > 5) {
                      printf("\n\nNumero invalido, ingrese denuevo: ");
                        scanf("%d", &menuC);
                  }
                  switch(menuC) {
                    case 1: //* Expedientes segun apellido de escribano
                      system("cls");
                      string apellido;
                        printf("Ingrese el apellido: ");
                      scan(apellido);
                        printf("\nHay %d expedientes hechos por el escribano ", cantidad(exp, apellido));
                      print(apellido);
                        printf("\n\n");
                      system("pause");
                      break;
                    case 2: //* Expediente con mayor cantidad de revisiones
                      system("cls");
                        if(vacio(rev))
                            printf("Aun no hay revisiones \n\n");
                        else
                            printf("El expediente con mayor cantidad de revisiones es el expediente de codigo \"%ld\"\n\n", expedienteMayorRev(rev));
                      system("pause");
                      break;
                    case 3: //* Cantidad de revisiones en un periodo de tiempo
                      system("cls");
                      fecha f, g;
                      printf("Primer fecha: \n\n");
                      cargar(f);
                      printf("\nSegunda fecha: \n\n");
                      cargar(g);
                        if(valida(f) && valida(g)) {
                            if(menor(f, g)){
                                printf("\nLa cantidad de revisiones entre las dos fechas es %d", periodo(rev, f, g));
                            }
                            else
                                printf("\nError, la primer fecha tiene que ser menor que la segunda");
                        }
                        else
                          printf("Error, fechas invalidas");
                        printf("\n\n");
                      system("pause");
                      break;
                    case 4: //* Cantidad de revisiones de cada tipo
                      system("cls");
                        printf("Revisiones satisfactorias: %d\n", cantSatis(rev));
                        printf("Revisiones incompletas: %d\n", cantIncomp(rev));
                        printf("Revisiones pendientes: %d\n", cantPend(rev));
                      system("pause");
                      break;
                  }
              } while(menuC != 5); //! Si se ingresa 5 se vuelve al menu principal
            break;
        }
    } while(menuP != 4); //! Si se ingresa 4 se cierra el programa
  bajar(exp);
  bajar(rev);
  return 0;
}

// ==============================================================================================================