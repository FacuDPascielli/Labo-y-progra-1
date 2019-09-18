#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


#define TAM 1


typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    int isEmpty;//1 vacío, 0 lleno.
    eFecha fechaIngreso;
} eAlumno;

void inicializarAlumnos(eAlumno alumnos[], int tam);
void mostrarAlumno(eAlumno x);
void mostrarAlumnos(eAlumno vec[], int tam);
void ordenarAlumnos(eAlumno vec[], int tam);
int menu();
int buscarLibre(eAlumno alumnos[], int tam);
int buscarAlumno(int legajo, eAlumno alumnos[], int tam);
eAlumno newAlumno(int legajo, int edad, char nombre[], int n1, int n2, char sexo, eFecha fecha);
int altaAlumno(eAlumno alumnos[], int tam);
int bajaAlumno(eAlumno alumnos[], int tam);
int menuModificar();
int modificarAlmuno(eAlumno alumnos[], int tam);



int main()
{
    eAlumno lista[TAM];
    char salir = 'n';

    inicializarAlumnos(lista, TAM);

    do
    {
        switch(menu())
        {
        case 1:
            altaAlumno(lista, TAM);
            break;
        case 2:
            bajaAlumno(lista, TAM);
            break;
        case 3:
            modificarAlmuno(lista, TAM);
            break;
        case 4:
            mostrarAlumnos(lista, TAM);
            break;
        case 5:
            printf("Ordenar alumno\n");
            //Ordenar por legajo, por nombre, por sexo. Por legajo y nombre, por legajo, sexo y nombre, etc.
            break;
        case 6:
            printf("Informes\n");
            break;
        case 7:
            printf("Confirma salida? s/n: \n");
            fflush(stdin);
            salir = getch();
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");
    }
    while(salir == 'n');
    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("Menu de opciones\n");
    printf("1- Alta alumno\n");
    printf("2- Baja alumno\n");
    printf("3- Modificar alumno\n");
    printf("4- Listar alumnos\n");
    printf("5- Ordenar alumnos\n");
    printf("6- Informes\n");
    printf("7- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarAlumno(eAlumno x)
{
    printf("  %d  %s  %d  %c  %d %d %.2f %02d/%02d/%d\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam)
{
    printf("****Listado de Alumnos****\n\n");
    int flag = 0;
    printf(" Legajo Nombre Edad Sexo Nota1 Nota2 Promedio FIngreso\n");
    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0)
            {
                mostrarAlumno(vec[i]);
                flag = 1;
            }

    }
    if(flag == 0)
        {
            system("cls");
            printf("\n---No hay alumnos que mostrar---");
        }
    printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam)
{

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].legajo > vec[j].legajo && vec[i].isEmpty == 0 && vec[j].isEmpty == 0)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }

}

void inicializarAlumnos(eAlumno alumnos[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        alumnos[i].isEmpty = 1;
    }
}

int buscarLibre(eAlumno alumnos[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(alumnos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAlumno(int legajo, eAlumno alumnos[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(alumnos[i].isEmpty == 0 && alumnos[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlumno(eAlumno alumnos[], int tam)
{
    printf("\n****Alta Alumno****\n\n");

    int todoOk = 0;
    int indice;
    int esta;
    int legajo;
    int edad;
    char sexo;
    int nota1;
    int nota2;
    char nombre[20];
    eFecha fecha;

    indice = buscarLibre(alumnos, tam);

    if(indice == -1)
    {
        printf("Sistema completo. No se puede agregar mas alumnos\n");
        system("pause");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        esta = buscarAlumno(legajo, alumnos, tam);
        if(esta != -1)
        {
            printf("El legajo ingresado ya fue registrado en el sistema\n");
            mostrarAlumno(alumnos[esta]);
            system("pause");
        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);

            printf("Ingrese edad: ");
            scanf("%d", &edad);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &sexo);

            printf("Ingrese nota parcial 1: ");
            scanf("%d", &nota1);

            printf("Ingrese nota parcial 2: ");
            scanf("%d", &nota2);

            printf("Ingrese fecha ingreso(dd/mm/aaaa): ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

            alumnos[indice] = newAlumno(legajo, edad, nombre, nota1, nota2, sexo, fecha);
            todoOk = 1;
        }
    }
        return todoOk;
}

eAlumno newAlumno(int legajo, int edad, char nombre[], int n1, int n2, char sexo, eFecha fecha)
{
    eAlumno nuevoAlumno;

    nuevoAlumno.edad = edad;
    nuevoAlumno.legajo = legajo;
    strcpy(nuevoAlumno.nombre, nombre);
    nuevoAlumno.nota1 = n2;
    nuevoAlumno.nota2 = n2;
    nuevoAlumno.sexo = sexo;
    nuevoAlumno.promedio = (float) (n1 + n2) / 2;
    nuevoAlumno.fechaIngreso = fecha;
    nuevoAlumno.isEmpty = 0;

    return nuevoAlumno;
}

int bajaAlumno(eAlumno alumnos[], int tam)
{
    int indice;
    int legajo;
    int todoOk = 0;
    int confirma;

    system("cls");
    printf("\n****Baja Alumno****\n\n");

    printf("Ingrese legajo de persona a dar de baja: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, alumnos, tam);

    if(indice == -1)
        {
            printf("\nNo existe ningun alumno de legajo %d\n", legajo);
            system("pause");
        }else
        {
            mostrarAlumno(alumnos[indice]);
            printf("Confirma baja?(s/n): ");
            fflush(stdin);
            confirma = getche();
            if(confirma == 's')
                {
                    alumnos[indice].isEmpty = 1;
                    todoOk = 1;
                    printf("\nSe ha eliminado el alumno\n");
                }else
                {
                    printf("Se ha cancelado la baja\n");
                }
        }
    system("pause");
    system("cls");
    return todoOk;
}

int modificarAlmuno(eAlumno alumnos[], int tam)
{
    int todoOk = 0;
    int indice;
    int legajo;
    int n1;
    int n2;
    int confirmar;
    int confirmar2;
    int salir;

    system("cls");
    printf("\n****Modificar Alumno****\n\n");

    printf("Ingrese legajo del alumno a modificar: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, alumnos, tam);

    if(indice == -1)
        {
            printf("\nNo existe ningun alumno de legajo %d", legajo);
            system("pause");
        }else
        {
            mostrarAlumno(alumnos[indice]);
            printf("\nEste es el alumno que desea modificar?(s/n): ");
            fflush(stdin);
            confirmar = getche();

            if(confirmar == 's')
                {
                    do
                        {

                    switch(menuModificar())
                    {
                        case 1:
                        printf("\nNota anterior: %d", alumnos[indice].nota1);
                        printf("\nIngrese la nota modificada: ");
                        scanf("%d", &n1);
                        printf("\nLa nueva nota es: %d\n", n1);
                        printf("\nEsta de acuerdo?(s/n): ");
                        fflush(stdin);
                        confirmar2 = getche();
                        if(confirmar2 == 's')
                            {
                                alumnos[indice].nota1 = n1;
                                todoOk = 1;
                                alumnos[indice].promedio = (float) (alumnos[indice].nota1 + alumnos[indice].nota2) / 2;
                                printf("\nModificacion exitosa\n");
                            }else
                            {
                                printf("\nSe ha cancelado la modificacion\n");
                            }
                        break;
                        case 2:
                        printf("\nNota anterior: %d", alumnos[indice].nota2);
                        printf("\nIngrese la nota modificada: ");
                        scanf("%d", &n2);
                        printf("\nLa nueva nota es: %d", n2);
                        printf("\nEsta de acuerdo?(s/n): ");
                        fflush(stdin);
                        confirmar2 = getche();
                        if(confirmar2 == 's')
                            {
                                alumnos[indice].nota2 = n2;
                                todoOk = 1;
                                alumnos[indice].promedio = (float) (alumnos[indice].nota1 + alumnos[indice].nota2) / 2;
                                printf("\nModificacion exitosa\n");
                            }else
                            {
                                printf("\nSe ha cancelado la modificacion\n");
                            }
                        break;
                        case 3:
                            printf("\nConfirma salida?(s/n): ");
                            fflush(stdin);
                            salir = getche();

                        default:
                            printf("\nOpcion invalida");
                    }
                    }while(salir == 'n');
                }else
                {
                    printf("\nSe ha cancelado la modificacion");
                }

        }
    return todoOk;
}

int menuModificar()
{
    int opcion;

    printf("\n*****Menu Modificar*****\n\n");
    printf("1- Nota PP\n");
    printf("2- Nota SP\n");
    printf("3- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
