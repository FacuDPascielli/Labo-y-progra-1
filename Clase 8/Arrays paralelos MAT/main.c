#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

void mostrarAlumnos(int leg[], char nom[][20], int ed[], char sex[], int n1[], int n2[], float prom[], int tam);
void mostrarAlumno(int leg, char nom[], int ed, char sex, int n1, int n2, float prom);
void ordenarAlumnosXLegajo(int leg[], char nom[][20], int ed[], char sex[], int n1[], int n2[], float prom[], int tam, int criterio);
void ordenarAlumnosSexLeg( int leg[], char nom[][20], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void ordenarAlumnosXNombre( char nom[][20],  int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void getString(char string[], char mensaje[], char mensajeError[], int tamCadena);



int main()
{
    int legajos[TAM] = {4, 2, 6, 7, 3};
    int edades[TAM] = {18, 19,20,21,22};
    char sexos[TAM] = {'m','f','f','m','f'};
    int notaP1[TAM] = {4, 2, 6, 7, 3};
    int notaP2[TAM] = {4, 2, 6, 7, 3};
    float promedios[TAM] = {4, 2, 6, 7, 3};
    char nombres[TAM][20] = {"Juan", "Carla", "Maria", "Ernesto", "Rosa"};
/*
    for(int i = 0; i < TAM; i++)
    {
        printf("\n\nIngrese legajo: ");
        scanf("%d", &legajos[i]);
        while(legajos[i] < 0)
        {
            printf("\nError, ingreso un numero negativo. Ingrese legajo: ");
            scanf("%d", &legajos[i]);
        }

        printf("\nIngrese nombre: ");
        fflush(stdin);
        getString(nombres[i], "Ingrese nombre.", "Error. Reingrese nombre.", TAM);


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
        while(notaP1[i] < 1 || notaP1[i] > 10)
        {
            printf("\nError. Ingrese nota del primer parcial (1 - 10): ");
            scanf("%d", &notaP1[i]);
        }

        printf("\nIngrese nota del segundo parcial(1-10): ");
        scanf("%d", &notaP2[i]);
        while(notaP2[i] < 1 || notaP2[i] > 10)
        {
            printf("\nError. Ingrese nota del segundo parcial (1 - 10): ");
            scanf("%d", &notaP2[i]);
        }

        promedios[i] = (float) (notaP1[i] + notaP2[i]) /2;
    }
*/
        ordenarAlumnosXLegajo(legajos, nombres, edades, sexos, notaP1, notaP2, promedios, TAM, 1);
        mostrarAlumnos(legajos, nombres, edades, sexos, notaP1, notaP2, promedios, TAM);
        ordenarAlumnosSexLeg(legajos, nombres, edades, sexos, notaP1, notaP2, promedios, TAM);
        mostrarAlumnos(legajos, nombres, edades, sexos, notaP1, notaP2, promedios, TAM);
        ordenarAlumnosXNombre(nombres, legajos, edades, sexos, notaP1, notaP2, promedios, TAM);
        mostrarAlumnos(legajos, nombres, edades, sexos, notaP1, notaP2, promedios, TAM);

    return 0;
}

void mostrarAlumnos(int leg[], char nom[][20], int ed[], char sex[], int n1[], int n2[], float prom[], int tam)
{
    printf("  Legajo         Nombre Edad  Sexo  Nota 1  Nota 2  Promedios \n\n");
    for(int i = 0; i < tam; i++)
    {
        mostrarAlumno(leg[i], nom[i], ed[i], sex[i], n1[i], n2[i], prom[i]);
    }
    printf("\n\n");
}

void mostrarAlumno(int leg, char nom[], int ed, char sex, int n1, int n2, float prom)
{
    printf("  %d %20s %d  %c  %d  %d  %.2f\n", leg, nom, ed, sex, n1, n2, prom);
}

void ordenarAlumnosXLegajo(int leg[], char nom[][20], int ed[], char sex[], int n1[], int n2[], float prom[], int tam, int criterio)
{
    int auxInt;
    char auxChar;
    float auxFloat;
    int swap;
    char auxStr[20];

    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(criterio == 0)
            {
                if(leg[j] < leg[i])
                {
                    swap = 1;

                }
            }
            else if(leg[j] > leg[i])
            {
                swap = 1;
            }
            if(swap)
            {
                auxInt = leg[j];
                leg[j] = leg[i];
                leg[i] = auxInt;

                auxInt = ed[j];
                ed[j] = ed[i];
                ed[i] = auxInt;

                auxChar = sex[j];
                sex[j] = sex[i];
                sex[i] = auxChar;

                auxInt = n1[j];
                n1[j] = n1[i];
                n1[i] = auxInt;

                auxInt = n2[j];
                n2[j] = n2[i];
                n2[i] = auxInt;

                auxFloat = prom[j];
                prom[j] = prom[i];
                prom[i] = auxFloat;

                strcpy(auxStr, nom[j]);
                strcpy(nom[j], nom[i]);
                strcpy(nom[i], auxStr);
            }

            swap = 0;

        }
    }
}

void ordenarAlumnosXNombre( char nom[][20],  int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam){
char aux[20];
float auxFloat;
int auxInt;
char auxChar;

    for(int i=0; i < tam -1; i++){
        for( int j = i +1; j < tam; j++){
            if(strcmp(nom[i], nom[j]) > 0){

                strcpy(aux, nom[i]);
                strcpy(nom[i], nom[j]);
                strcpy(nom[j], aux);

                  auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                 sex[i] = sex[j];
                 sex[j] = auxChar;

                auxInt = n1[i];
                 n1[i] = n1[j];
                 n1[j] = auxInt;

                auxInt = n2[i];
                 n2[i] = n2[j];
                 n2[j] = auxInt;

              auxFloat = prom[i];
               prom[i] = prom[j];
               prom[j] = auxFloat;
            }
        }
    }
}

void ordenarAlumnosSexLeg( int leg[], char nom[][20], int age[], char sex[], int n1[], int n2[], float prom[], int tam)
{

    int auxInt;
    float auxFloat;
    char auxChar;
    char auxStr[20];
    int swap = 0;

    for(int i=0; i < tam-1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {

            if( sex[i] > sex[j])
            {
                swap = 1;
            }
            else if( sex[i] == sex[j] && leg[i] > leg[j])
            {

                swap = 1;
            }

            if( swap )
            {

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                sex[i] = sex[j];
                sex[j] = auxChar;

                auxInt = n1[i];
                n1[i] = n1[j];
                n1[j] = auxInt;

                auxInt = n2[i];
                n2[i] = n2[j];
                n2[j] = auxInt;

                auxFloat = prom[i];
                prom[i] = prom[j];
                prom[j] = auxFloat;

                strcpy(auxStr, nom[j]);
                strcpy(nom[j], nom[i]);
                strcpy(nom[i], auxStr);
            }

            swap = 0;
        }
    }
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
