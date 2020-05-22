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
    printf("10: ordenar\n");
    printf("0: Salir\n");
    scanf("%d", &opc);
    return opc;
}

int generos(){
	int opc;
	printf("Que genero es su local?\n");
	printf("=================\n");
	printf("1: MODA\n");
	printf("2: TECNOLOGIA\n");
	printf("3: HOGAR\n");
	printf("0: OTROS\n");
	scanf("%d",opc);
	return opc;
}

int menuEdit(){
	int opc;
	printf("Que decide editar?\n");
	printf("=================\n");
	printf("1: Editar Nombre\n");
	printf("2: Editar Precio menejado\n");
	printf("3: Editar genero del local\n");
	printf("0: salir\n");
	scanf("%d",opc);
	return opc;
}



void selection_sort(local_t **centroComercial, int pisos, int locales){
     int j, i, x;
	 local_t temp;
	 for (i = 0; i < pisos; i++){
	 	for(j = 0; x < locales - 1; x++){
	 }
}


 void insert_sort(local_t **centroComercial, int pisos, int locales){
	int i, j, x, temp;
	for(i = 0; i < pisos; i++){
		for(x = 0; x < locales; x++){
			temp = centroComercial[i][x];
			j = x - 1;
			while(j >= 0 && centroComercial[j] > temp){
				centroComercial[i][j+1] = centroComercial[i][j];
				j--;
			}
		}
		centroComercial[i][j+1] = temp;
	}
}


void merge_sort(local_t ** centroComercial, int numPisos, int numLocalesxPiso){
	
}


quick_sort(local_t ** centroComercial, int numPisos, int numLocalesxPiso){
	
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
            	printf("Precio manejado por el local es %d\n", centroComercial[numPiso][numLocalxPiso].precio);
            	printf("Ganancias totales del local es %d\n", centroComercial[numPiso][numLocalxPiso].GTotal);
            	printf("El local es de %d\n", centroComercial[numPiso][numLocalxPiso].genero);
				cont = 1;
			}
		}
	}
	if (cont == 0)
	printf("este local no esta alquilado actualmente\n");
}


void alquilarLocal(local_t **centroComercial, int pisos, int locales){
    int piso, local, genero; 
    int meta = 1;
    int disponible = planosCC(centroComercial,  pisos,  locales);
    if (disponible != 0){
		
	    while (meta){
	        printf("Piso\n");
	        scanf("%d", &piso);
	        printf("Local\n");
	        scanf("%d", &local);
	        
	        
	        if (piso - 1 >= pisos || local - 1 >= locales)
	            printf("Error de digitacion\n");
	            
	        if (centroComercial[piso - 1][local - 1].idLocal != 0)
	            printf("Local ya ocupado\n");
	            
	        else
	            meta = 0;
	    }
		
		meta = 1;
	    printf("Nombre del local\n");
	    scanf("%35s", centroComercial[piso - 1][local - 1].nombreLocal);
	    centroComercial[piso - 1][local - 1].idLocal = id();
	    centroComercial[piso - 1][local - 1].pisoLocal = piso;
	    centroComercial[piso - 1][local - 1].numLocalxPiso = local;
	    while (meta){
		    genero = generos();
		    if (genero < 1 || genero > 4){
		    	print("opcion incorrecta\n");
			}
			else{
		    	meta = 0;
			}
		}
		centroComercial[piso - 1][local - 1].genero = genero;
		printf("ingrese el precio de venta que maneja este local\n");
		scanf("%d",centroComercial[piso][local].precio);
	    centroComercial[piso][local].GTotal = 0;
		
	    
	}
	else{
		printf("todos los locales estan alquilados, elimine un local si quiere uno nuevo [opc 2 en menu]")
	}
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
			switch(opc){
				case 1:
					    printf("Nombre Nuevo\n");
		    			scanf("%34s", nombre);
		    			strcpy(local->nombreLocal, nombre);
		    			break;
			
				case 2:
						int precioN;
						printf("Precio Nuevo\n");
		    			scanf("%d", precioN);
		    			local->precio = precioN;
		    			break;
			
				case 3:
						int generoN;
						printf("nuevo genero\n");
		    			scanf("%d", generoN);
		    			local->genero = generoN;
		    			break;
			
				case 0:
						printf("gracias por todo, se a salido del menu de edicion\n");
						break;
			
			default:
				printf("Error de digitacion\n");
		}
		else
			printf("Local clausurado\n");
	
	}
	else
		printf("No se encontro local\n");
}


void TopVentas(local_t **centroComercial, int pisos, int locales){
    int i;
    int j;
    int Top1 = 0;
    char local1[35];
    int Top2 = 0;
    char local2[35];
	int Top3 = 0;
    char local3[35];
	for (i = 0; i <pisos; i++){
    	for (j = 0; j < locales; j++){
    		if (centroComercial[i][j].GTotal > Top1){
	    		Top3 = Top2;
	    		local3 = local2;
				Top2 = Top1;
	    		local2 = local1;
				Top1 = centroComercial[i][j].GTotal;
	    		local1 = centroComercial[i][j].nombreLocal;
	    	}
		}
	}
	printf("puesto #1 = %35s ---- %d", local1, Top1);
	printf("puesto #2 = %35s ---- %d", local2, Top2);
	printf("puesto #3 = %35s ---- %d", local3, Top3);
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
	printf("las ganancias totoales para el CENTRO VERTCAL DE AUTOGESTION es de: %f\n", ganancias);
}


int planosCC(local_t **centroComercial, int pisos, int locales){
	int i;
	int j;
	disponibles = 0;
    for (i = 0; i < pisos; i++){
        for (j = 0; j < locales; j++){
        	if(centroComercial[i][j] !=0){
            	printf("Nombre del local es %s\n", centroComercial[i][j].nombreLocal);
            	printf("Local numero %d del piso %d\n", j, i);
            	printf("Id del local es %d\n", centroComercial[i][j].idLocal);
            	printf("Precio manejado por el local es %d\n", centroComercial[i][j].precio);
            	printf("Ganancias totales del local es %d\n", centroComercial[i][j].GTotal);
            	printf("El local es de %d\n", centroComercial[numPiso][numLocalxPiso].genero);
			}
			else
				printf("local [%d][%d] libre para alquilar\n", i, j);
				disponobles++;
		}
	}
	return disponibles;
}







