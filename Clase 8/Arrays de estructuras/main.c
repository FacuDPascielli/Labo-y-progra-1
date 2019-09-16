#include <stdio.h>
#include <stdlib.h>

#define TAM 2
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    char nombre[20];
    int edad;
    int legajo;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaDeIngreso;
}eAlumno;

int main()
{
    eAlumno lista[TAM]/* = {{}}//--> Es para hardcodear arrays de estructuras. */;

    for(int i = 0; i < TAM, i++)
        {
    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(lista[i].nombre);

    printf("\nIngrese legajo: ");
    scanf("%d", &lista[i].legajo);

    printf("\nIngrese edad: ");
    scanf("%d", &lista[i].edad);

    printf("\nIngrese sexo: ");
    fflush(stdin);
    scanf("%c", &lista[i].sexo);

    printf("\nIngrese nota del primer parcial: ");
    scanf("%d", &lista[i].nota1);

    printf("\nIngrese nota del segundo parcial: ");
    scanf("%d", &lista[i].nota2);

    printf("\nIngrese fecha de ingreso dd/mm/aaa: ");
    scanf("%02d/%02d/%d", &lista[i].fechaDeIngreso.dia, lista[i].fechaDeIngreso.mes, lista[i].fechaDeIngreso.anio);

    /*printf("\nIngrese dia de ingreso: ");
    scanf("%d", &lista[i].fechaDeIngreso.dia);

    printf("\nIngrese mes de ingreso: ");
    scanf("%d", &lista[i].fechaDeIngreso.mes);

    printf("\nIngrese anio de ingreso: ");
    scanf("%d", &lista[i].fechaDeIngreso.anio);*/

    lista[i].promedio = (float) ((lista[i].nota1 + lista[i].nota2) / 2);
        }
    return 0;
}
