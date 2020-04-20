#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V_SIZE 10

int cont;

// Herramientas
void gen_rand(int v[], int size);
void print_vect(int v[], int size);
void swap(int v[], int o, int d);

//Algoritmos
void insert_sort(int v[], int size);

int main(int argc, char *argv[])
{
 int v[V_SIZE];

 printf("############ Ordenando por Inserción ##########\n");
 gen_rand(v, V_SIZE);
 printf("No. Aleatorios: ");
 print_vect(v, V_SIZE);
printf("Números ordenados: ");
insert_sort(v, V_SIZE);
print_vect(v, V_SIZE);
return 0;
}
void gen_rand(int v[], int size)
{
 int i;

 cont = cont + 1;
 srand(time(NULL)*cont);
 for(i=0; i<size; i++)
 v[i]=rand()%100;
}


void print_vect(int v[], int size)
{
 int i;
 printf("[ ");
 for(i=0; i<size; i++)
 printf("%d ", v[i]);
 printf("]\n");
}


void insert_sort(int v[], int size)
{
 int i, j, temp;
 for(i=0; i<size; i++)
 {
 temp=v[i];
 j=i-1;
 while(j>=0 && v[j] >temp)
 {
 v[j+1] = v[j];
 j--;
 }

 v[j+1] = temp;
 }
}
