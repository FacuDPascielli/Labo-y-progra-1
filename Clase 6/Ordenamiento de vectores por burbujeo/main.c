#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarVectorInt(int vec[], int tam);

int main()
{
    int vec[TAM] = {7,5,8,1,3};
    int aux;

    printf("Vector sin ordenar \n\n");
    mostrarVectorInt(vec, TAM);

    for(int i = 0; i < TAM-1; i++)
    {
        for(int j = i + 1; j < TAM; j++)
        {
            if(vec[j] < vec[i])//Para ordenar de menor a mayor, el signo del if debe ser <, para ordenar de mayor a menor el signo debe ser >.
            {
                aux = vec[j];
                vec[j] = vec[i];
                vec[i] = aux;
            }
        }
    }

    printf("Vector ordenado de menor a mayor\n\n");
    mostrarVectorInt(vec, TAM);

    return 0;
}

void mostrarVectorInt(int vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n\n");
}
