#include <stdio.h>
#include <string.h>

struct User
{
    char name[20];
    int dia;
    int year;
};

typedef struct User User;

int menu();

void addUser(User mat[][5], int sizes[]);

void BuscarMes(User mat[][5], int sizes[]);
