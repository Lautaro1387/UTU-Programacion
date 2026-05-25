#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

const int N = 100;

// Largo secuencia
const int NIVEL_P = 6;
const int NIVEL_I = 8;
const int NIVEL_A = 10;

// Tiempo mostrar colores
const float TIEMPO_COLOR_P = 1.5;
const float TIEMPO_COLOR_I = 1.3;
const float TIEMPO_COLOR_A = 1;

// Puntajes
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
        int i = 0;

        printf("Bienvenido al Juego de SIMON ver. 1.0.\n");
        printf("Ingrese su nombre (fin = fin del juego): ");

        do
        {
            scanf("%c", &nombre[i]);

            if(nombre[i] != '\n')
            {
                i++;
            }

        } while(i < N && nombre[i] != '\n');

        nombre[i] = '\0';

        // Fin del juego
        if(strcmp(nombre, "fin") == 0)
        {
            printf("\nRESULTADOS DEL JUEGO\n");

            printf("Principiante: %s %d puntos\n", nombreP, mejorP);
            printf("Intermedio: %s %d puntos\n", nombreI, mejorI);
            printf("Avanzado: %s %d puntos\n", nombreA, mejorA);

            return 0;
        }

        char nivel;

        do
        {
            printf("Ingrese nivel del Juego (p, i, a): ");
            scanf(" %c", &nivel);

            if(nivel != 'p' && nivel != 'P' &&
               nivel != 'i' && nivel != 'I' &&
               nivel != 'a' && nivel != 'A')
            {
                printf("Nivel incorrecto.\n");
            }

        } while(nivel != 'p' && nivel != 'P' &&
                nivel != 'i' && nivel != 'I' &&
                nivel != 'a' && nivel != 'A');

        printf("Pulse ENTER para comenzar.\n");

        getchar();

        int largo;
        float tiempo;
        int puntajeAcierto;

        switch(nivel)
        {
            case 'p':
            case 'P':
                largo = NIVEL_P;
                tiempo = TIEMPO_COLOR_P;
                puntajeAcierto = ACIERTO_NIVEL_P;
                break;

            case 'i':
            case 'I':
                largo = NIVEL_I;
                tiempo = TIEMPO_COLOR_I;
                puntajeAcierto = ACIERTO_NIVEL_I;
                break;

            case 'a':
            case 'A':
                largo = NIVEL_A;
                tiempo = TIEMPO_COLOR_A;
                puntajeAcierto = ACIERTO_NIVEL_A;
                break;
        }

        char secuencia[100];
        char ingreso[100];

        // Generar secuencia
        for(i = 0; i < largo; i++)
        {
            int randoms = rand() % 4;

            switch(randoms)
            {
                case 0:
                    secuencia[i] = 'R';
                    break;

                case 1:
                    secuencia[i] = 'A';
                    break;

                case 2:
                    secuencia[i] = 'V';
                    break;

                case 3:
                    secuencia[i] = 'N';
                    break;
            }
        }

        bool encontrada = true;
        int puntaje = 0;

        int n = 0;

        do
        {
            // Mostrar secuencia acumulada
            for(i = 0; i <= n; i++)
            {
                printf("%c\n", secuencia[i]);

                usleep(tiempo * 1000000);

#ifdef _WIN32
                system("cls");
#else
                system("clear");
#endif
            }

            printf("Ingrese la secuencia:\n");

            i = 0;

            do
            {
                scanf(" %c", &ingreso[i]);

                // Pasar a mayúscula
                if(ingreso[i] >= 'a' && ingreso[i] <= 'z')
                {
                    ingreso[i] = ingreso[i] - 32;
                }

                if(ingreso[i] == secuencia[i])
                {
                    i++;
                }
                else
                {
                    encontrada = false;
                }

            } while(encontrada && i <= n);

            if(encontrada)
            {
                puntaje += puntajeAcierto;

                printf("Correcto!\n");
                printf("Puntaje: %d\n", puntaje);
            }
            else
            {
                printf("Perdiste!\n");
            }

            n++;

        } while(encontrada && n < largo);

        // Actualizar récord
        switch(nivel)
        {
            case 'p':
            case 'P':

                if(puntaje > mejorP)
                {
                    mejorP = puntaje;
                    strcpy(nombreP, nombre);
                }

                break;

            case 'i':
            case 'I':

                if(puntaje > mejorI)
                {
                    mejorI = puntaje;
                    strcpy(nombreI, nombre);
                }

                break;

            case 'a':
            case 'A':

                if(puntaje > mejorA)
                {
                    mejorA = puntaje;
                    strcpy(nombreA, nombre);
                }

                break;
        }

        printf("Desea jugar otra partida? (S/N): ");
        scanf(" %c", &jugar);

    } while(jugar == 'S' || jugar == 's');

}