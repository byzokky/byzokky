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
    
    FILE *r = fopen("reporte.txt", "rb"); 
	fclose(r);
	FILE *s = fopen("save", "wb");
	fclose(s);
	FILE *d = fopen("demo", "rb");
	fclose(d);

	do{
		opc = menu();
		switch(opc){
		case 1: system ("cls");
				mostrarLocal(centroComercial, pisos, locales);
				break;
		
		
		case 2: system ("cls");
				alquilarLocal(centroComercial, pisos, locales);
				break;
		
		
		case 3: system ("cls");
				eliminarLocal(centroComercial, pisos, locales);
				break;
		
		
		case 4: r = fopen( "reporte.txt", "w" );
				fprintf( r, "REPORTE LOCALES DEL CENTRO VERTICAL DE AUTOGESTION\n" );
				fprintf( r, "==================================================\n" );
				for (i = 0; i < pisos; i++){
			        for (j = 0; j < locales; j++){
			        	if(centroComercial[i][j].idLocal !=0){
			            	fprintf("Nombre del local es %s\n", centroComercial[i][j].nombreLocal);
			            	fprintf("Local numero %d del piso %d\n", j, i);
			            	fprintf("Id del local es %d\n", centroComercial[i][j].idLocal);
			            	fprintf("Precio manejado por el local es %d\n", centroComercial[i][j].precip);
			            	fprintf("Ganancias totales del local es %d\n", centroComercial[i][j].GTotal);
			            	fprintf("El local es de %d\n", centroComercial[i][j].genero);
						}
						else
							fprintf("local [%d][%d] libre para alquilar\n", i, j);
					}
				}
				fflush(r);
				fclose(r);
				printf("Se genero reporte.txt.\n");
				system("notepad reporte.txt");
				break;
				
				
		case 5: system ("cls");
				editarLocal(centroComercial, pisos, locales);
				break;
		
		
		case 6: system ("cls");
				TopVentas(centroComercial);
				break;
				
				
		case 7: system ("cls");
				comprarEn(centroComercial, pisos, locales);
				break;
				
				
		case 8: system ("cls");
				gananciasCC(centroComercial, pisos, locales);
				break;
				
				
		case 9: system ("cls");
				int disponibles = planosCC(centroComercial, pisos, locales);
				printf("\n%d locales libre", disponibles);
				break;
		
		
		case 10: system ("cls");
				 int opc = ordenamientos();
				 switch(opc){
					 case 1: seletion_sort(centroComercial, pisos, locales);
							 break;
					 case 2: insert_sort(centroComercial, pisos, locales);
							 break;
					 case 3: merge_sort(centroComercial, pisos, locales);
							 break;
					 case 4: quick_sort(centroComercial, pisos, locales);
							 break;
					 case 0: printf("gracias por ordenar\n");
					 		 break;
					 default:
						 printf("opcion invalida");
				 }
				 break;
		
		
		case 11: s = fopen( "save", "wb" );
				 if(s == NULL);{
				 	printf("no se a podido abrir el archivo save");
				 }
				 else{
				 	fwrite(&pisos, sizeof(pisos),1,s);
				 	fwrite(&locales, sizeof(locales),1,s);
					 for (i = 0; i < pisos; i++){
				        for (j = 0; j < locales; j++){
							fwrite(&centroComercial[i][j], sizeof(local_t), 1, s);
						}
					 }
				 }
				 fflush(s);
				 fclose(s);
				 break;
		
		
		case 12: d = fopen( "demo", "rb");
				 if(d == NULL);{
				 	printf("no se a podido abrir el archivo demo");
				 }
				 else{
				 	fread(&pisos, sizeof(pisos),1,d);
				 	fread(&locales, sizeof(pisos),1,d);
				 	local_t centroComercial =  malloc(sizeof(local_t*) * pisos);
				    for(i = 0; i < pisos; i++){
				        centroComercial[i] = malloc(sizeof(local_t) * locales);
				        for (j = 0; j < pisos; j++)
				            centroComercial[i][j].idLocal = 0;
				    }
				 	for (i = 0; i < pisos; i++){
				        for (j = 0; j < locales; j++){
				        	fread(&centroCmercial[i][j], sizeof(local_t), 1, d);
				        }
				 }
				 fclose(d);
				 break;
				
		
		case 0: system ("cls");
				printf ("gracias por venir");
				break;
				
				
		default:
			printf("opcion invalida\n");
			break;
			
		}while (opc!=0);
	}
	return 0;
}
