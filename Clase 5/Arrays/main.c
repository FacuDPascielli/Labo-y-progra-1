#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[5];
    int bandera = 0;
    int mayor;
    int indiceMayor;


    for(int i = 0; i < 5; i++)
        {
            printf("Ingrese un numero positivo: ");
            scanf("%d", &numeros[i]);
            while(numeros[i] < 0)
                {
                    printf("Error. Ingrese un numero positivo: ");
                    scanf("%d", &numeros[i]);
                }

        }
    for(int i = 0; i < 5; i++)
            {
                if(bandera == 0)
                {
                    mayor = numeros[i];
                    indiceMayor = i;
                    bandera = 1;
                }else
                {
                    if(numeros[i] > mayor)
                        {
                            mayor = numeros[i];
                        }
                }
            }
        printf("\nEl mayor numero es %d y esta en la posicion/es ", mayor, indiceMayor);

    for(int i = 0; i < 5; i++)
            {
                if(mayor == numeros[i])
                    {
                        printf("%d ", i);
                    }
            }
    return 0;
}
