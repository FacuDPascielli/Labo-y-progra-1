#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sexos[5];
    int contadorM = 0;
    int contadorF = 0;

    for(int i = 0; i < 5; i++)
        {
            printf("Ingrese un sexo f/m: ");
            fflush(stdin);
            scanf("%c", &sexos[i]);

            while(sexos[i] != 'f' && sexos[i] != 'm')
                {
                    printf("Error. Ingrese un sexo f/m: ");
                    fflush(stdin);
                    scanf("%c", &sexos[i]);
                }
        }
    for(int i = 0; i < 5; i++)
        {
            if(sexos[i] == 'f')
                {
                    contadorF++;
                }else
                {
                    contadorM++;
                }
        }
        printf("Se ingresaron %d sexos masculinos y %d sexos femeninos.\n", contadorM, contadorF);
    return 0;
}
