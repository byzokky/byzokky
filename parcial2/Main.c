#include "FuncionesCC.h"
#include <stdio.h>

int main(){
	int opc;
	int i;
	int j;
	int pisos;
	int locales;
    printf("cantidad de pisos: ");
    scanf("%d", &pisos);
    printf("cantidad de locales: ");
    scanf("%d", &locales);
	local_t centroComercial =  malloc(sizeof(local_t*) * pisos);
	
    for(i = 0; i < pisos; i++){
        centroComercial[i] = malloc(sizeof(local_t) * locales);
        for (j = 0; j < pisos; j++)
            centroComercial[i][j].idLocal = 0;
    }
    
    FILE *r = fopen( "reporte.txt", "rb" ); 
	fclose( r );

	do{
		opc = menu();
		switch(opc){
		case 1: mostrarLocal(centroComercial, pisos, locales);
				break;
		
		
		case 2: alquilarLocal(centroComercial, pisos, locales);
				break;
		
		
		case 3: eliminarLocal(centroComercial, pisos, locales);
				break;
		
		
		case 4: r = fopen( "reporte.txt", "w" );
				fprintf( r, "REPORTE LOCALES DEL CENTRO VERTICAL DE AUTOGESTION\n" );
				fprintf( r, "==================================================\n" );
				for (i = 0; i < pisos; i++){
			        for (j = 0; j < locales; j++){
			        	if(centroComercial[i][j] !=0){
			            	fprintf("Nombre del local es %s\n", centroComercial[i][j].nombreLocal);
			            	fprintf("Local numero %d del piso %d\n", j, i);
			            	fprintf("Id del local es %d\n", centroComercial[i][j].idLocal);
			            	fprintf("Precio manejado por el local es %d\n", centroComercial[i][j].precip);
			            	fprintf("Ganancias totales del local es %d\n", centroComercial[i][j].GTotal);
						}
						else
							fprintf("local [%d][%d] libre para alquilar\n", i, j);
					}
				}
				fclose( r );
				printf( "Se genero reporte.txt.\n" );
				system( "notepad reporte.txt" );
				break;
				
				
		case 5: editarLocal(centroComercial, pisos, locales);
				break;
		
		
		case 6: TopVentas(centroComercial);
				break;
				
				
		case 7: comprarEn(centroComercial, pisos, locales);
				break;
				
				
		case 8: gananciasCC(centroComercial, pisos, locales);
				break;
				
				
		case 9: planosCC(centroComercial);
				break;
				
		
		case 0: printf ("gracias por venir");
				break;
				
				
		default:
			printf("opcion invalida\n");
			break;
			
		}while (opc!=0);
	}
	return 0;
}
