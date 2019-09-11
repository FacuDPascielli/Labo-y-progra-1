#include <stdio.h>
#include <stdlib.h>

void mostrarNombres(char mat [][20]);//Terminar esta funcion y hacer una funcion que ordene alfabéticamente los nombres.

int main()
{
    char nombres[5][20];

    for(int i = 0; i < 5; i++)
        {
            printf("Ingrese un nombre: ");
            fflush(stdin);
            gets(nombres[i]);
        }

    printf("\n\n");

    for(int i = 0; i < 5; i++)
        {
            printf("%s\n", nombres[i]);
        }
    return 0;
}
