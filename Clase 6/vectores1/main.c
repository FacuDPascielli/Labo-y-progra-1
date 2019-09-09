#include <stdio.h>
#include <stdlib.h>

void mostrarVectorInt(int vec[], int tam);
void mostrarVectorChar(char vec[], int tam);
void mostrarVectorFloat(float vec[], int tam);

int main()
{
    int numeros[] = {1, 2, 3, 4, 5, 6};
    char vocales[] = {'a', 'e', 'i', 'o', 'u'};
    float reales[] = {12.5, 32.6, 1.2, 2.3, 123.4, 32.2, 4.2, 6.5, 7.4, 10.9};

    mostrarVectorInt(numeros, 6);
    mostrarVectorChar(vocales, 5);
    mostrarVectorFloat(reales, 10);

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

void mostrarVectorChar(char vec[], int tam)
{
    for(int i = 0; i < tam; i++)
        {
            printf("%c ", vec[i]);
        }
    printf("\n\n");
}

void mostrarVectorFloat(float vec[], int tam)
{
    for(int i = 0; i < tam; i++)
        {
            printf("%.2f ", vec[i]);
        }
    printf("\n\n");
}
