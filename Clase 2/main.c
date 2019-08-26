#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[20];
    char sexo;
    char nombreMayorNota[20];
    char nombreMenorNota[20];
    char sexoMayorNota;
    char sexoMenorNota;
    char confirmar;
    int nota;
    int acumulador = 0;
    int acumuladorM = 0;
    int notaMenor = 0;
    int notaMayor = 0;
    int contador = 0;
    int contadorM = 0;
    int flag = 0;
    float promedio;
    float promedioM;

    do
        {
        printf("Ingrese nombre: \n");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese sexo f/m: \n");
        fflush(stdin);
        scanf("%c", &sexo);

        while(sexo != 'f' && sexo != 'm')
            {
                printf("Error. Ingrese sexo f/m: \n");
                fflush(stdin);
                scanf("%c", &sexo);
            }

        printf("Ingrese nota 1 - 10: \n");
        scanf("%d", &nota);

        while(nota < 0 || nota > 10)
            {
                printf("Error. Ingrese nota 1 - 10: \n");
                scanf("%d", &nota);
            }

        if(flag == 0)
            {
                notaMayor = nota;
                notaMenor = nota;
                flag = 1;
            }else
            {
                if(nota > notaMayor)
                {
                    notaMayor = nota;
                    strcpy(nombreMayorNota, nombre);
                    sexoMayorNota = sexo;
                }
                if(nota < notaMenor)
                   {
                    notaMenor = nota;
                    strcpy(nombreMenorNota, nombre);
                    sexoMenorNota = sexo;
                   }

            }



        acumulador = acumulador+nota;
        if(sexo == 'f')
            {
                acumuladorM = acumuladorM + nota;
                contadorM++;
            }
        contador++;

        printf("Desea ingresar otra persona? s/n");
        fflush(stdin);
        scanf("%c", &confirmar);

        }while(confirmar == 's');

    promedio = acumulador/contador;
    promedioM = acumuladorM/contadorM;

    printf("La mayor nota es %d y pertenece a %s de sexo %c\n", notaMayor, nombreMayorNota, sexoMayorNota);
    printf("La menor nota es %d y pertenece a %s de sexo %c\n", notaMenor, nombreMenorNota, sexoMenorNota);
    printf("El promedio total de notas es de %f", promedio);
    printf("El promedio de notas de mujeres es de %f", promedioM);

    return 0;
}
