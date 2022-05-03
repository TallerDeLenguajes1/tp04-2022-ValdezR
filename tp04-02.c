#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//#include<conio.h>

struct Tarea{
    int tareaID;  //Numerado en ciclo iterativo
    char *descripcion; //Ingresado por el usuario
    int duracion; //Entre 10 y 100
}typedef Tarea;

void cargarTareas(Tarea **tareas, int cantidadTareas);
void mostrarTareas(Tarea **tareas, int cantidadTareas);
void controlTareas(Tarea **tareaRealizada, Tarea **tareaPendientei, int cantidadTareas);
void buscar_tarea(Tarea **tareas, int cantidadTareas, int idAux);


int main()
{
    srand(time(NULL));
    int cantidadTareas;
    Tarea **tareasPendientes= (Tarea **) malloc(sizeof(Tarea) * cantidadTareas);
    Tarea **tareasRealizadas= (Tarea **) malloc(sizeof(Tarea) * cantidadTareas);

    printf("Ingrese la cantidad de tareas a realizar:   ");
    scanf("%d", &cantidadTareas);
    fflush(stdin);
    
    cargarTareas(tareasPendientes, cantidadTareas);
    mostrarTareas(tareasPendientes, cantidadTareas);
    controlTareas(tareasRealizadas,tareasPendientes,cantidadTareas);

    printf("\n----------------------\nTareas realizadas\n----------------------\n");
    mostrarTareas(tareasRealizadas, cantidadTareas);
    printf("\n----------------------\nTareas pendientes\n----------------------\n");
    mostrarTareas(tareasPendientes, cantidadTareas);

    printf("\n----------------------\nBuscar tarea\n----------------------\n");
    int idAux;
    printf("Ingrese el ID de la tarea buscada (no mayor que %d)", cantidadTareas);
    scanf(" %d", &idAux);

    buscar_tarea(tareasRealizadas,cantidadTareas,idAux);
    
    buscar_tarea(tareasPendientes,cantidadTareas,idAux);

    getch();
    return 0;
}
//FUNCIONES

void cargarTareas(Tarea **tareas, int cantidadTareas){

    char buff[100];
    for (int i = 0; i < cantidadTareas; i++)
    {
        tareas[i]= (Tarea *) malloc(sizeof(Tarea));
        tareas[i]->tareaID= i + 1;
        printf("\nIngrese la descripcion de la tarea %d: ",i+1);
        gets(buff);
        tareas[i]->descripcion= (char *) malloc(sizeof(char) * strlen(buff));
        strcpy(tareas[i]->descripcion, buff);
        tareas[i]->duracion= rand() % (90) + 10;
    }   
}


void mostrarTareas(Tarea **tareas, int cantidadTareas)
{
    printf("\nListado de tareas: ");
    for (int i = 0; i < cantidadTareas; i++)
    {
        if (tareas[i])
        {
            printf("\nID de la tarea: %d", tareas[i]->tareaID);
            printf("\nDuracion de la tarea: %d min", tareas[i]->duracion);
            printf("\nDescriocion de la tarea: %s\n", tareas[i]->descripcion);
        }
    }
    
}

void controlTareas(Tarea **tareaRealizada, Tarea **tareaPendiente, int cantidadTareas)
{
    char buff;

    printf("-*-*-*-*-*-*-*-*-*-*-*-\nControl de tareas\n-*-*-*-*-*-*-*-*-*-*-*\n");
    for (int i = 0; i < cantidadTareas; i++)
    {
        printf("La tarea: %s, con ID %d, se realizo?\n s para si, n para no\n", tareaPendiente[i]->descripcion, tareaPendiente[i]->tareaID);
        // getc(buff);
        scanf("%c", &buff);
        fflush(stdin);
        if (buff =='s')
        {
            tareaRealizada[i]= (Tarea *) malloc(sizeof(Tarea));
            tareaRealizada[i]= tareaPendiente[i];
            tareaPendiente[i]= NULL;
        }else{
            tareaRealizada[i]= NULL;
        }
    }
    printf("\nSe controlaron todas las tareas.\n");   
}

void buscar_tarea(Tarea **tareas, int cantidadTareas, int idAux)
{    
    for (int i = 0; i < cantidadTareas; i++)
    {
        if (tareas[i] != NULL && tareas[i]->tareaID == idAux)
        {
            printf("La tarea buscada con ID = %d esta pendientes\n", tareas[i]->tareaID);
            printf("Tarea: %s\n", tareas[i]->descripcion);
            printf("Duracion: %d\n", tareas[i]->duracion);
        }
    }
}