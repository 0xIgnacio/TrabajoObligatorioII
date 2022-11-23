#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "arbolExp.h"
#include "listaRev.h"

int main() {
  int menuP, menuCB, menuL, menuC;
  lista rev; // Revisiones
  arbol exp; // Expedientes
  crear(rev);
  crear(exp);
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
                      expediente e;
                      cargar(e); // Cargo el expediente a la variable "e"
                        if(!existe(exp, e.codigo)) {
                          cargar(exp, e); // Si no existe cargo "e" al arbol de expedientes
                            printf("\nExpediente cargado correctamente\n\n");
                        }
                        else
                          printf("Ese codigo de expediente ya existe, volviendo al menu\n\n");
                      system("pause");
                      break;
                    case 2: //* Nueva revision
                      revision r;
                      cargar(r); // Cargo la revision a la variable "r"
                        if(existe(exp, r.codigoExp)) {
                            if(vacio(rev)) {
                              cargar(rev, r); // Si el expediente existe y la lista es vacia, cargo la revision
                                printf("Revision del expediente \"%ld\" cargada correctamente\n\n");
                            }
                            else {
                                if(menor(r.realizado, darFecha(rev -> info))) {
                                  cargar(rev, r); // Si el expediente existe y fecha es menor, cargo la revision
                                    printf("Revision del expediente \"%ld\" cargada correctamente\n\n");
                                }
                                else
                                    printf("Error al cargar revision, la fecha de la nueva revision es mayor, volviendo al menu\n\n");
                            }
                        }
                        else
                            printf("Error al cargar revision, el codigo de expediente no existe, volviendo al menu\n\n");
                      system("pause");
                      break;
                    case 3: //* Borrar expediente y revisiones del mismo
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
                        printf("Lista de expedientes: \n\n");
                      mostrar(exp);
                        printf("\n\n");
                      system("pause");
                      break;
                    case 2: //* Listar expediente con el mayor y el expediente con menor numero
                        printf("\nExpediente con mayor codigo: \n");
                      mostrar(mayor(exp));
                        printf("\n\nExpediente con menor codigo: \n");
                      mostrar(menor(exp));
                        printf("\n\n");
                      system("pause");
                      break;
                    case 3: //* Listar revisiones
                      mostrar(rev);
                        printf("\n\n");
                      system("pause");
                      break;
                    case 4: //* Listar revisiones segun codigo de expediente
                      long c;
                        printf("Ingresa el codigo del expediente para ver sus revisiones: ");
                          scanf("%d", &c);
                        if(existe(rev, c))
                          mostrar(rev, c);
                        else
                          printf("Error al buscar expediente, el codigo no existe, volviendo al menu\n\n");
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
                      string apellido;
                        printf("Ingrese el apellido: ");
                      scan(apellido);
                        printf("\nHay %d expedientes hechos por el escribano ", cantidad(exp, apellido));
                      print(apellido);
                        printf("\n\n");
                      system("pause");
                      break;
                    case 2: //* Expediente con mayor cantidad de revisiones
                        printf("\nEl expediente con mayor cantidad de revisiones es el expediente de codigo \"%ld\"\n\n", expedienteMayorRev(rev));
                        system("pause");
                      break;
                    case 3: //* Cantidad de revisiones en un periodo de tiempo
                      fecha f, g;
                      cargar(f);
                      cargar(g);
                        if(valida(f) && valida(g) && menor(f, g))
                          printf("La cantidad de revisiones entre las dos fechas es %d", periodo(rev, f, g));
                        else
                          printf("Error, fechas invalidas\n\n");
                      system("pause");
                      break;
                    case 4: //* Cantidad de revisiones de cada tipo
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
  return 0;
}

// ==============================================================================================================