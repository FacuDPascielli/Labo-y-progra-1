#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getString(char string[], char mensaje[], char mensajeError[], int tamCadena);

int main()
{
    char nombre[10];
    getString(nombre, "Ingrese nombre", "Error. Nombre muy largo. Reingrese nombre", 10);

    printf("%s", nombre);

    return 0;
}
void getString(char string[], char mensaje[], char mensajeError[], int tamCadena)
{
    char auxStr[100];

    printf("%s: ", mensaje);
    gets(auxStr);

    while(strlen(auxStr) > tamCadena - 1)
        {
            printf("%s: ",mensajeError);
            gets(auxStr);
        }

    strcpy(string, auxStr);
}
