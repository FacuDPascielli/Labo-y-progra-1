#include <stdio.h>
#include <stdlib.h>

void mostrarVectorInt(int vec[], int tam);
void ordenarVectorInt(int vec[], int tam, int criterio);//El criterio ordenaría con 0 ascendente y 1 descendente

int main()
{
    int numeros[] = {2,5,8,1,9,3};
    printf("Vector sin ordenar\n\n");
    mostrarVectorInt(numeros, 6);

    ordenarVectorInt(numeros, 6, 0);
    printf("\nVector ordenado de manera ascendente\n\n");
    mostrarVectorInt(numeros, 6);

    ordenarVectorInt(numeros, 6, 1);
    printf("\nVector ordenado de manera descendente\n\n");
    mostrarVectorInt(numeros, 6);

    return 0;
}
void ordenarVectorInt(int vec[], int tam, int criterio)
{
    int aux;
    for(int i = 0; i < tam-1; i++)
        {
            for(int j = i + 1; j < tam; j++)
                {
                    if(criterio == 0)
                        {
                            if(vec[j] < vec[i])
                            {
                                aux = vec[j];
                                vec[j] = vec[i];
                                vec[i] = aux;
                            }
                        }else
                        {
                            if(vec[j] > vec[i])
                            {
                                aux = vec[j];
                                vec[j] = vec[i];
                                vec[i] = aux;
                            }
                        }

                }
        }
}

void mostrarVectorInt(int vec[], int tam)
{
    for(int i = 0; i < tam; i++)
        {
            printf("%d ", vec[i]);
        }
    printf("\n\n");
}
