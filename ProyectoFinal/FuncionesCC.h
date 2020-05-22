#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


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

int menu();

int generos();

int menuEdit();

void alquilarLocal(local_t **centroComercial, int pisos, int locales);

void eliminarLocal(local_t **centroComercial, int pisos, int locales);

void editarLocal(local_t **centroComercial, int pisos, int locales);

void TopVentas(local_t **centroComercial, int pisos, int locales);

void comprarEn(local_t **centroComercial, int pisos, int locales);

void gananciasCC(local_t **centroComercial, int pisos, int locales);

int planosCC(local_t **centroComercial, int pisos, int locales);


#endif /* FUNCIONESCC_H_ */
