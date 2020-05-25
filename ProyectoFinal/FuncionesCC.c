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
    printf("10: Ordenar\n");
    printf("11: Guardar en archivo\n");
    printf("12: Cargar una demo del CVA\n");
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


int ordenamientos(){
	int opc;
	pritnf("De que forma quieres ordenar?\n");
	printf("=============================\n");
	printf("1: De mayor ganancia a menor ganancia\n");
	printf("2: De menor ganancia a mayor ganancia\n");
	printf("3: De mayor precio a menor precio\n");
	printf("4: De menor precio a maoyr precio\n");
	printf("0: Salir\n");
	scanf("%d",opc);
	return opc;
}

void intercambiar(int *a, int *b) {
  int temporal = *a;
  *a = *b;
  *b = temporal;
}


int particion(local_t muestra[], int izquierda, int derecha){
  int bandera = 1;
  int pivote = muestra[izquierda].precio;
  while (bandera){
    while (muestra[izquierda].precio < pivote){
      izquierda++;
    }
    while (muestra[derecha].precio > pivote){
      derecha--;
    }
    if (izquierda >= derecha){
      return derecha;
    }
	else{
      intercambiar(&muestra[izquierda].precio, &muestra[derecha].precio);
      izquierda++;
      derecha--;
    }
  }
}


void merge(local_t arr[], int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    local_t L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if ( L[i].precio <= R[j].precio) 
        { 
            arr[k].precio = L[i].precio; 
            i++; 
        } 
        else
        { 
            arr[k].precio = R[j].precio; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 


void mergeSortAux(local_t *muestra, int p, int longitud){
    if (p < longitud)
    {
        // Dividir el problema en subproblemas
        int q = (p + longitud)/2;
        
        // Resolver el problema de manera recursiva hasta llegar a una solucion trivial
        mergeSortAux(muestra, p, q);
        mergeSortAux(muestra, q + 1, longitud);
        
        // Fusion de resultados parciales
        merge(muestra, p, q, longitud);
    }
}


void quickSortAux(local_t muestra[], int izquierda, int derecha){
  if (izquierda < derecha) {
    int indiceParticion = particion(muestra, izquierda, derecha);
    quickSortAux(muestra, izquierda, indiceParticion);
    quickSortAux(muestra, indiceParticion + 1, derecha);
  }
}


void selection_sort(local_t **centroComercial, int pisos, int locales){
    int j, i, x = 0;
	local_t temp;
	local_t muestra [pisos*locales];
	for (i = 0; i < pisos; i++){
	 	for(j = 0; j < locales; j++){
	 		muestra[x]= centroComercial[i][j];
	 		x++;
		}
	}
	int actual, mas_pequeno;
     for (actual = 0; actual < pisos*locales - 1; actual++){
         mas_pequeno = actual;
         for (j = actual; j < pisos*locales; j++)
              if (muestra[j].GTotal < muestra[mas_pequeno].GTotal)
                  mas_pequeno = j;
          temp = muestra[actual];
          muestra[actual] = muestra[mas_pequeno];
          muestra[mas_pequeno] = temp;
     }
     for(x = 0; x < pisos*locales; x++){
     	printf("Nombre del local es %s\n", muestra[x].nombreLocal);
        printf("Id del local es %d\n", muestra[x].idLocal);
        printf("Precio manejado por el local es %d\n", muestra[x].precio);
        printf("Ganancias totales del local es %d\n", muestra[x].GTotal);
        printf("El local es de %d\n\n\n", muestra[x].genero);
	 }
}


 void insert_sort(local_t **centroComercial, int pisos, int locales){
	int i, j, x = 0;
	local_t temp;
	local_t muestra [pisos*locales];
	for (i = 0; i < pisos; i++){
	 	for(j = 0; j < locales; j++){
	 		muestra[x]= centroComercial[i][j];
	 		x++;
		}
	}
	for(i=0; i<pisos*locales; i++){
		temp=muestra[i];
		j=i-1;
		while(j>=0 && muestra[j].GTotal >temp.GTotal){
			muestra[j+1] = muestra[j];
			j--;
		}
		muestra[j+1] = temp;
	}
	for(x = 0; x < pisos*locales; x++){
     	printf("Nombre del local es %s\n", muestra[x].nombreLocal);
        printf("Id del local es %d\n", muestra[x].idLocal);
        printf("Precio manejado por el local es %d\n", muestra[x].precio);
        printf("Ganancias totales del local es %d\n", muestra[x].GTotal);
        printf("El local es de %d\n\n\n", muestra[x].genero);
	 }
}


void merge_sort(local_t **centroComercial, int pisos, int locales){
	int j, i, x = 0, p = 0;
	local_t temp;
	local_t muestra [pisos*locales];
	for (i = 0; i < pisos; i++){
	 	for(j = 0; j < locales; j++){
	 		muestra[x]= centroComercial[i][j];
	 		x++;
		}
	}
	int longitud = sizeof muestra / sizeof muestra[0] - 1;
	mergeSortAux(muestra, p, longitud);
}


quick_sort(local_t **centroComercial, int pisos, int locales){
	int j, i, x = 0;
	local_t temp;
	local_t muestra [pisos*locales];
	for (i = 0; i < pisos; i++){
	 	for(j = 0; j < locales; j++){
	 		muestra[x]= centroComercial[i][j];
	 		x++;
		}
	}
	int longitud = sizeof muestra / sizeof muestra[0];
	quickSortAux(muestra, 0, longitud - 1);
	for(x = 0; x < pisos*locales; x++){
     	printf("Nombre del local es %s\n", muestra[x].nombreLocal);
        printf("Id del local es %d\n", muestra[x].idLocal);
        printf("Precio manejado por el local es %d\n", muestra[x].precio);
        printf("Ganancias totales del local es %d\n", muestra[x].GTotal);
        printf("El local es de %d\n\n\n", muestra[x].genero);
	 }
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
		printf("todos los locales estan alquilados, elimine un local si quiere uno nuevo [opc 2 en menu]");
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
    			local = &centroComercial[i][j];
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
		else{
			printf("Local clausurado\n");
		}
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
    			local = &centroComercial[i][j];
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
	int disponibles = 0;
    for (i = 0; i < pisos; i++){
        for (j = 0; j < locales; j++){
        	if(centroComercial[i][j].idLocal !=0){
            	printf("Nombre del local es %s\n", centroComercial[i][j].nombreLocal);
            	printf("Local numero %d del piso %d\n", j, i);
            	printf("Id del local es %d\n", centroComercial[i][j].idLocal);
            	printf("Precio manejado por el local es %d\n", centroComercial[i][j].precio);
            	printf("Ganancias totales del local es %d\n", centroComercial[i][j].GTotal);
            	printf("El local es de %d\n", centroComercial[i][j].genero);
			}
			else
				printf("local [%d][%d] libre para alquilar\n", i, j);
				disponibles++;
		}
	}
	return disponibles;
}





