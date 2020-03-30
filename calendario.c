#include <stdio.h>
#include <string.h>
#include "user.h"
int menu()
{
    int opc;
    printf("Seleccione la accion:\n");
    printf("1: Ingresar usuario\n");
    printf("2: Mostrar por mes\n");
    printf("0: Salir\n");
    scanf("%d", &opc);

    return opc;
}

void addUser(User mat[][5], int sizes[])
{
    int dia, mes, year;
    char name[20];

    printf("Nombre: ");
    scanf("%s", &name);

    printf("Anio: ");
    scanf("%d", &year);

    printf("Mes: ");
    scanf("%d", &mes);

    printf("Dia: ");
    scanf("%d", &dia);

    if (sizes[mes - 1] < 5)
    {
        User u;
        strcpy(u.name, name);
        u.dia = dia;
        u.year = year;
        mat[mes - 1][sizes[mes - 1]] = u;
        sizes[mes - 1]++;
    }
    else
        printf("No hay mas espacio para el mes %d\n", mes);
}

void BuscarMes(User mat[][5], int sizes[])
{
    int mes;
    printf("Mes: ");
    scanf("%d", &mes);

    int i;
    for (i = 0; i < sizes[mes - 1]; i++)
    {
        User u = mat[mes - 1][i];
        printf("Nombre: %s\nFecha de nacimiento: %d/%d/%d\n", u.name, u.dia, mes, u.year);
    }
}


int main()
{
    User mat[12][5];
    int sizes[12] = {};

    int opc;
    do
    {
        opc = menu();

        switch (opc)
        {
        case 1:
            addUser(mat, sizes);
            break;

        case 2:
            BuscarMes(mat, sizes);
            break;

        case 0:
            break;

        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (opc != 0);
}
