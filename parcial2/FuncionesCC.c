#include "FuncionesCC.h"


int idLocal(){
	srand(time(NULL));
	int id = 1 + rand()%(1000);
	return id;
}


int menu(){
	int opc;
    printf("BIENVENIDO AL CENTRO VERTCAL DE AUTOGESTION\n");
    printf("===========================================\n");
    printf("1: Mostrar Local\n");
    printf("2: Alquilar Local\n");
    printf("3: Eliminar Local\n");
    printf("4: Reporte de Locales\n");
    printf("5: Editar Local\n");
    printf("6: Top Ventas del CVA\n");
    printf("7: Comprar\n");
    printf("8: Ganancias\n");
    printf("9: Planos del CVA\n");
    printf("0: Salir\n");
    scanf("%d", &opc);
    return opc;
}


int menuEdit(){
	int opc;
	printf("Que decia editar?\n");
	printf("=================\n");
	printf("1: Editar Nombre\n");
	printf("2: Editar Precio menejado");
	printf("0: salir\n");
	scanf("%d",opc);
	return opc;
}


/* Funcion de ejemplo que imprimiria la informacion de un local */
void mostrarLocal(local_t ** centroComercial, int numPisos, int numLocalesxPiso){
	int cont = 0;
	int numPiso = 0;
	int numLocalxPiso  = 0;
	printf("Elija el piso\n");
	scanf("%d", numPiso);
	printf("Elija el local\n");
	scanf("%d", numLocalxPiso);
	
	int i;
	int j;
    for (i = 0; i < numPisos; i++){
        for (j = 0; j < numLocalesxPiso; j++){
            //Si los nombres son iguales, devuelve la direccion
            if (centroComercial[i][j].pisoLocal == numPiso && centroComercial[i][j].numLocalxPiso == numLocalxPiso && centroComercial[i][j].idLocal != 0){
            	printf("Nombre del local es %s\n", centroComercial[numPiso][numLocalxPiso].nombreLocal);
            	printf("Id del local es %d\n", centroComercial[numPiso][numLocalxPiso].idLocal);
            	printf("Precio manejado por el local es %d\n", centroComercial[numPiso][numLocalxPiso].precip);
            	printf("Ganancias totales del local es %d\n", centroComercial[numPiso][numLocalxPiso].GTotal);
            	cont = 1;
			}
		}
	}
	if (cont == 0)
	printf("este local no esta alquilado actualmente\n");
}


void alquilarLocal((local_t **centroComercial, int pisos, int locales){
    int piso, local;
    while (1){
        printf("Piso\n");
        scanf("%d", &piso);
        printf("Local\n");
        scanf("%d", &local);
        
        
        if (piso - 1 >= pisos || local - 1 >= locales)
            printf("Error de digitacion\n");
            
        if (centroComercial[piso - 1][local - 1].idLocal != 0)
            printf("Local ya ocupado\n");
            
        else
            break;
    }

    printf("Nombre del local\n");
    scanf("%35s", centroComercial[piso - 1][local - 1].nombreLocal);
    centroComercial[piso - 1][local - 1].idLocal = id();
    centroComercial[piso - 1][local - 1].pisoLocal = piso;
    centroComercial[piso - 1][local - 1].numLocalxPiso = local;
	printf("ingrese el precio de venta que maneja este local\n");
	scanf("%d",centroComercial[piso][local].precio);
    centroComercial[piso][local].GTotal = 0;
}


void eliminarLocal(local_t **centroComercial, int pisos, int locales){
    //Se pide la posicion a eliminar hasta que esta sea valida
    int piso;
	int local;
    while (1){
        printf("Piso: ");
        scanf("%d", &piso);
        printf("Local: ");
        scanf("%d", &local);

        if (piso - 1 >= pisos || local - 1 >= locales)
            printf("Error de digitacion\n");
        else if (centroComercial[piso - 1][local - 1].idLocal == 0)
            printf("Este local esta vacio\n");
        else
            break;
    }
    centroComercial[piso - 1][local - 1].idLocal = 0;
}


void editarLocal(local_t **centroComercial, int pisos, int locales){
	char nombre[35];
    int i;
	int j;
    local_t *local = NULL;
    printf("Nombre del local\n");
    scanf("%34s", nombre);

    for (i = 0; i < pisos; i++){
        for (j = 0; j < locales; j++){
            if (!strcmp(centroComercial[i][j].nombreLocal, nombre))
    			local_t *local = &centroComercial[i][j];
    	}
	}
	if (local != NULL);{
		if (local->idLocal != 0){
			int opc = menuEdit();
			if (opc == 1){
			    printf("Nombre Nuevo\n");
    			scanf("%34s", nombre);
    			strcpy(local->nombreLocal, nombre);
			}
			else if (opc == 2){
				int precioN;
				printf("Precio Nuevo\n");
    			scanf("%d", precioN);
    			local->precio = precioN;
			}
			else if (opc == 0){
				printf("gracias por todo, se a salido del menu de edicion\n");
				break;
			}
			else{
				printf("Error de digitacion, , se a salido de la edicion\n")
			}
		}
		else
			printf("Local clausulado\n");
	
	}
	else
		printf("No se encontro local\n");
}


void TopVentas(local_t **centroComercial, int pisos, int locales){
    int i;
    int j;
    int T1 = 0;
    char P1[35];
    int T2 = 0;
    char P2[35];
	int T3 = 0;
    char P3[35];
	for (i = 0; i <pisos; i++){
    	for (j = 0; j < locales; j++){
    		if (centroComercial[i][j].GTotal > T1)
    		T3 = T2;
    		P3 = P2;
			T2 = T1;
    		P2 = P1;
			T1 = centroComercial[i][j].GTotal;
    		P1 = centroComercial[i][j].nombreLocal;
		}
	}
	printf("puesto #1 = %35s ---- %d", P1, T1);
	printf("puesto #2 = %35s ---- %d", P2, T2);
	printf("puesto #3 = %35s ---- %d", P3, T3);
}


void comprarEn(local_t **centroComercial, int pisos, int locales){
	char nombre[35];
    int i;
	int j;
    local_t *local = NULL;
    printf("Nombre del local\n");
    scanf("%34s", nombre);

    for (i = 0; i < pisos; i++){
        for (j = 0; j < locales; j++){
            if (!strcmp(centroComercial[i][j].nombreLocal, nombre))
    			local_t *local = &centroComercial[i][j];
    	}
	}
	
    if (local != NULL){
        if (local->idLocal != 0){
                local->GTotal += local->precio;
        }
        else
            printf("Local clausulado\n");
    }
    else
        printf("No se encontro local\n");
	
}


void gananciasCC(local_t **centroComercial, int pisos, int locales){
	int i;
	int j;
	float ganancias = 0;
	
	for(i = 0; i < pisos; i++){
		for(j = 0; j < locales; j++){
			ganancias += (centroComercial[i][j].GTotal*0.3);
		}
	}
	printf("las ganancias totoales para el CENTRO VERTCAL DE AUTOGESTION es de: %f\n");
}


void planosCC(local_t **centroComercial, int pisos, int locales){
	int i;
	int j;
    for (i = 0; i < pisos; i++){
        for (j = 0; j < locales; j++){
        	if(centroComercial[i][j] !=0){
            	printf("Nombre del local es %s\n", centroComercial[i][j].nombreLocal);
            	printf("Local numero %d del piso %d\n", j, i);
            	printf("Id del local es %d\n", centroComercial[i][j].idLocal);
            	printf("Precio manejado por el local es %d\n", centroComercial[i][j].precio);
            	printf("Ganancias totales del local es %d\n", centroComercial[i][j].GTotal);
			}
			else
				printf("local [%d][%d] libre para alquilar\n", i, j);
		}
	}
}
