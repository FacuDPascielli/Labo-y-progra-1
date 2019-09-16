#include <stdio.h>
#include <stdlib.h>

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
    eAlumno alumno1;

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(alumno1.nombre);

    printf("\nIngrese legajo: ");
    scanf("%d", &alumno1.legajo);

    printf("\nIngrese edad: ");
    scanf("%d", &alumno1.edad);

    printf("\nIngrese sexo: ");
    fflush(stdin);
    scanf("%c", &alumno1.sexo);

    printf("\nIngrese nota del primer parcial: ");
    scanf("%d", &alumno1.nota1);

    printf("\nIngrese nota del segundo parcial: ");
    scanf("%d", &alumno1.nota2);

    printf("\nIngrese dia de ingreso: ");
    scanf("%d", &alumno1.fechaDeIngreso.dia);

    printf("\nIngrese mes de ingreso: ");
    scanf("%d", &alumno1.fechaDeIngreso.mes);

    printf("\nIngrese anio de ingreso: ");
    scanf("%d", &alumno1.fechaDeIngreso.anio);

    alumno1.promedio = (float) ((alumno1.nota1 + alumno1.nota2) / 2);

    printf("\nNombre: %s",alumno1.nombre);
    printf("\nEdad: %d",alumno1.edad);
    printf("\nSexo: %c",alumno1.sexo);
    printf("\nLegajo: %d",alumno1.legajo);
    printf("\nNota PP: %d",alumno1.nota1);
    printf("\nNota SP: %d",alumno1.nota2);
    printf("\nPromedio: %.2f",alumno1.promedio);
    printf("\nFecha de ingreso: %02d/%02d/%d", alumno1.fechaDeIngreso.dia, alumno1.fechaDeIngreso.mes, alumno1.fechaDeIngreso.anio);


    return 0;
}
