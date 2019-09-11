#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    /*
    strlen(nombre) --> Me devuelve el largo de la cadena.
    strcpy(nombre, nombre2) --> Copia la cadena de la derecha a la de la izquierda, sería como hacer nombre = nombre2
    strncpy(nombre, nombre2, 5) --> Hace lo mismo que strcpy pero hasta el caracter que pasemos por la funcion.
    */
    char n1[10] = "Juan";
    char n2[10] = "Juana";
    //int x;
    //int y;

    //x = strcmp(n1, n2);//Cuando el de la derecha está antes en el diccionario que el de la izquierda me devuelve 1, si son iguales me devuelve 0 y si el de la izquierda está antes, me devuelve -1.
    //y = stricmp(n1, n2);//Hace lo mismo que strcmp pero sin ser sensible a minúsculas y mayúsculas.
    //strupr(n1);//Pasa cadena a mayúsculas.
    //strlwr(n2);//Pasa cadena a minúsculas

    n2[0] = toupper(n2[0]);//Pasa a mayuscula la primer letra.
    printf("%s\n",n1);
    printf("%s\n",n2);

    return 0;
}
