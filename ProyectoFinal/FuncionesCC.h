#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <iostream>
using namespace std;


typedef enum generoLocal{
	MODA = 1, TECNOLOGIA = 2, HOGAR = 3, OTROS = 4
}generoLocal;

//Local 
typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
	int precio;
	int GTotal;
	generoLocal genero;
	// Completelo con lo que quiera
} local_t;

/*Agregar las funciones que necesite para satisfacer los requerimientos */
void mostrarLocal(local_t ** centroComercial, int numPisos, int numLocalesxPiso);

int idLocal();

void pruebasInt(int x);

int menu();

int generos();

int menuEdit();

int ordenamientos();

void intercambiar(local_t *a, local_t *b);

int particion(local_t muestra, int izquierda, int derecha);

void merge(local_t arr, int l, int m, int r);

void mergeSortAux(local_t *muestra, int p, int longitud);

void quickSortAux(local_t muestra, int izquierda, int derecha);

void selection_sort(local_t **centroComercial, int pisos, int locales);

void insert_sort(local_t **centroComercial, int pisos, int locales);

void merge_sort(local_t **centroComercial, int pisos, int locales);

void quick_sort(local_t **centroComercial, int pisos, int locales);

void alquilarLocal(local_t **centroComercial, int pisos, int locales);

void eliminarLocal(local_t **centroComercial, int pisos, int locales);

void editarLocal(local_t **centroComercial, int pisos, int locales);

void TopVentas(local_t **centroComercial, int pisos, int locales);

void comprarEn(local_t **centroComercial, int pisos, int locales);

void gananciasCC(local_t **centroComercial, int pisos, int locales);

int planosCC(local_t **centroComercial, int pisos, int locales);


#endif /* FUNCIONESCC_H_ */
