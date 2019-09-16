#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarNombres(char mat [][20]);//Terminar esta funcion y hacer una funcion que ordene alfabéticamente los nombres.
void ordenarMatChar(char mat[][20], int tam);

int main()
{
    char nombres[5][20] = {"Juan", "Alicia", "Ernesto", "Alvaro", "Sofia"};
/*
    for(int i = 0; i < 5; i++)
    {
        printf("Ingrese un nombre: ");
        fflush(stdin);
        gets(nombres[i]);
    }
*/
    printf("\n\n");

    printf("Nombres sin ordenar: \n");
    mostrarNombres(nombres);

    ordenarMatChar(nombres, 5);
    printf("Nombres ordenados: \n");
    mostrarNombres(nombres);

    return 0;
}
void mostrarNombres(char mat [][20])
{
    for(int i = 0; i < 5; i++)
    {
        printf("\n%s\n", mat[i]);
    }
    printf("\n\n");
}

void ordenarMatChar(char mat[][20], int tam)
{
    char aux[20];
    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(strcmp(mat[i], mat[j]) == 1)//Si pusiera "> 0" se ordenaría de mayor a menor.
            {
                strcpy(aux, mat[j]);
                strcpy(mat[j], mat[i]);
                strcpy(mat[i], aux);
            }


        }
    }
}
