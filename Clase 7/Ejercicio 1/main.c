#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getString(char string[], char mensaje[], char mensajeError[], int tamCadena);
void mayusculaPrimerLetra(char str[]);

int main()
{
    char nombre[20];
    char apellido[20];
    char nombreCompleto[41];
    int i = 0;

    getString(nombre, "Ingrese nombre", "Error. Ingreso un nombre muy largo.", 20);
    getString(apellido, "Ingrese apellido", "Error. Ingreso un apellido muy largo.", 20);

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwr(nombreCompleto);
    mayusculaPrimerLetra(nombreCompleto);

    while(nombreCompleto[i] != '\0')
        {
            if(nombreCompleto[i] == ' ')
                {
                    nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
                }
            i++;
        }

    printf("%s", nombreCompleto);
    return 0;
}

void getString(char string[], char mensaje[], char mensajeError[], int tamCadena)
{
    char auxStr[100];

    printf("%s: ", mensaje);
    fflush(stdin);
    gets(auxStr);

    while(strlen(auxStr) > tamCadena - 1)
        {
            printf("%s: ",mensajeError);
            fflush(stdin);
            gets(auxStr);
        }

    strcpy(string, auxStr);
}

void mayusculaPrimerLetra(char str[])
{
    str[0] = toupper(str[0]);
}
