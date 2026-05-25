#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int N = 100;

const int NIVEL_P = 6;
const int NIVEL_I = 8;
const int NIVEL_A = 10;

const float TIEMPO_COLOR_P = 1.5;
const float TIEMPO_COLOR_I = 1.3;
const float TIEMPO_COLOR_A = 1;

const int ACIERTO_NIVEL_P = 1;
const int ACIERTO_NIVEL_I = 3;
const int ACIERTO_NIVEL_A = 5;

int main()
{
    char nombre[N];

    // Mejores puntajes

    int mejorP = 0;
    int mejorI = 0;
    int mejorA = 0;

    char nombreP[N] = "";
    char nombreI[N] = "";
    char nombreA[N] = "";

    char jugar = 'S';

    srand(time(NULL));

    do
    {
        printf("Bienvenido al Juego de SIMON ver 1.0\n");

        printf("Ingrese nombre (fin para terminar): ");
        scanf("%s", nombre);

        // TERMINAR JUEGO

        if(strcmp(nombre, "fin") == 0)
        {
            printf("\nRESULTADOS FINALES\n");

            printf("Principiante: %s %d puntos\n",
                   nombreP, mejorP);

            printf("Intermedio: %s %d puntos\n",
                   nombreI, mejorI);

            printf("Avanzado: %s %d puntos\n",
                   nombreA, mejorA);

            return 0;
        }

        /*
        if(nivel == 'p' || nivel == 'P')
        {
            if(puntaje > mejorP)
            {
                mejorP = puntaje;
                strcpy(nombreP, nombre);
            }
        }
    

        printf("Desea jugar otra partida? (S/N): ");
        scanf(" %c", &jugar);

    } while(jugar == 'S' || jugar == 's');

}