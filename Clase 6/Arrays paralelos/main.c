#include <stdio.h>
#include <stdlib.h>

#define TAM 1

void mostrarAlumnos(int leg[], int ed[], char sex[], int n1[], int n2[], float prom[], int tam);
void mostrarAlumno(int leg, int ed, char sex, int n1, int n2, float prom);
//armar funcion ordenar alumnos por legajo
int main()
{
    int legajos[TAM];
    int edades[TAM];
    char sexos[TAM];
    int notaP1[TAM];
    int notaP2[TAM];
    float promedios[TAM];

    for(int i = 0; i < TAM; i++)
        {
            printf("\n\nIngrese legajo: ");
            scanf("%d", &legajos[i]);
            while(legajos[i] < 0)
                {
                    printf("\nError, ingreso un numero negativo. Ingrese legajo: ");
                    scanf("%d", &legajos[i]);
                }

            printf("\nIngrese edad(18-99): ");
            scanf("%d", &edades[i]);
            while(edades[i] < 18 || edades[i] > 99)
                {
                    printf("\nError. Ingrese una edad mayor o igual a 18 y menor a 99: ");
                    scanf("%d", &edades[i]);
                }

            printf("\nIngrese sexo f/m: ");
            fflush(stdin);
            scanf("%c", &sexos[i]);
            while(sexos[i] != 'f' && sexos[i] != 'm')
                {
                    printf("\nError. Ingrese sexo f/m: ");
                    fflush(stdin);
                    scanf("%c", &sexos[i]);
                }

            printf("\nIngrese nota del primer parcial(1-10): ");
            scanf("%d", &notaP1[i]);
            while(notaP1[i] < 0 || notaP1[i] > 10)
                {
                    printf("\nError. Ingrese nota del primer parcial (1 - 10): ");
                    scanf("%d", &notaP1[i]);
                }

            printf("\nIngrese nota del segundo parcial(1-10): ");
            scanf("%d", &notaP2[i]);
            while(notaP2[i] < 0 || notaP2[i] > 10)
                {
                    printf("\nError. Ingrese nota del segundo parcial (1 - 10): ");
                    scanf("%d", &notaP2[i]);
                }

            promedios[i] = (float) (notaP1[i] + notaP2[i]) /2;
        }
    mostrarAlumnos(legajos, edades, sexos, notaP1, notaP2, promedios, TAM);

    return 0;
}

void mostrarAlumnos(int leg[], int ed[], char sex[], int n1[], int n2[], float prom[], int tam)
{
    printf("Legajo  Edad  Sexo  Nota 1  Nota 2  Promedios \n\n");
    for(int i = 0; i < tam; i++)
        {
            printf("%d  %d  %c  %d  %d  %.2f\n", leg[i], ed[i], sex[i], n1[i], n2[i], prom[i]);
        }
    printf("\n\n");
}

void mostrarAlumno(int leg, int ed, char sex, int n1, int n2, float prom)
{
    printf("%d  %d  %c  %d  %d  %.2f\n", leg, ed, sex, n1, n2, prom);
}
