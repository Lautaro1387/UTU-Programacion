#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // rand - srand
#include <time.h>
#include <unistd.h> // sleep
#include <string.h> // comparar string fin

const int N = 100; // nombre;
// Largo de la secuencia de colores dependiendo el nivel
const int NIVEL_P = 6;
const int NIVEL_I = 8;
const int NIVEL_A = 10;

// Tiempo en segundos que muestra cada colores dependiendo el nivel
const float TIEMPO_COLOR_P = 1.5;
const float TIEMPO_COLOR_I = 1.3;
const float TIEMPO_COLOR_A = 1;

const int ACIERTO_NIVEL_P = 1;
const int ACIERTO_NIVEL_I = 3;
const int ACIERTO_NIVEL_A = 5;

int main()
{

    int i, j, n, puntaje = 0, randoms, mejorP = 0, mejorI = 0, mejorA = 0;
    char h, nivel;
    char nombre[100];
    char nombreP[100];
    bool f = false, encontrada;
    char jugar = 'S';
    bool caracter = true;

    // Generar un número aleatorio y limitarlo al rango de 0 a 3
    srand(time(NULL));

    do
    { // Bucle para seguir jugando
        printf("Bienvenido al Juego de SIMON ver. 1.0.\n");
        printf("Ingrese su nombre\n");
        getchar();
        j = 0;

        // Cambiar esta sección del fin
        do // while
        {
            scanf("%c", &nombre[j]);

            if (nombre[j] != '\n')
                j++;
        } while (j < N && nombre[j] != '\n');

        nombre[j] = '\0';

        i = 0;
        if (strcmp(nombre, "fin") == 0)
            f = true;

        if (!f)
        {
            puntaje = 0;
            printf("Ingrese nivel del Juego (p, i, a): ");
            scanf(" %c", &nivel);

            switch (nivel)
            {
            case 'p':
            case 'P':
                printf("Pulse <enter> para comenzar el juego. ");
                scanf("%c", &h);
                getchar();

                char secuencia[NIVEL_P];
                char ingreso[NIVEL_P];
                for (i = 0; i < NIVEL_P; i++)
                {
                    randoms = rand() % 4;
                    switch (randoms)
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
                n = 0;
                encontrada = true;


                do
                {
                    for (i = 0; i <= n; i++)
                    {
                             #ifdef _WIN32
                            system("cls");  // Comando para Windows
                        #else
                            system("clear"); // Comando para Linux y macOS
                        #endif
                        printf("%c", secuencia[i]);
                        sleep(TIEMPO_COLOR_P);
                               #ifdef _WIN32
                            system("cls");  // Comando para Windows
                        #else
                            system("clear"); // Comando para Linux y macOS
                        #endif

                    }
                    i = 0;

                    do
                    {
                        scanf(" %c", &ingreso[i]);
                            #ifdef _WIN32
                            system("cls");  // Comando para Windows
                        #else
                            system("clear"); // Comando para Linux y macOS
                        #endif
                        sleep(TIEMPO_COLOR_P);
                        if (secuencia[i] == ingreso[i])
                        {
                            i++;
                            puntaje = puntaje + ACIERTO_NIVEL_P;
                        }
                        else
                            encontrada = false;
                    } while (encontrada && i <= n);
                    n++;
                } while (encontrada && n < NIVEL_P);
                if (puntaje > mejorP)
                {
                    mejorP = puntaje;
                    strcpy(nombreP, nombre);
                }
                break;
            case 'i':
            case 'I':
            {

                printf("Pulse <enter> para comenzar el juego. ");
                scanf("%c", &h);
                getchar();
                char secuencia[NIVEL_I];
                char ingreso[NIVEL_I];
                for (i = 0; i < NIVEL_I; i++)
                {
                    randoms = rand() % 4;
                    switch (randoms)
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
                n = 0;
                encontrada = true;
                do
                {
                    for (i = 0; i <= n; i++)
                    {
                             #ifdef _WIN32
                            system("cls");  // Comando para Windows
                        #else
                            system("clear"); // Comando para Linux y macOS
                        #endif
                        printf("%c", secuencia[i]);
                        sleep(TIEMPO_COLOR_I);
                        system("clear");
                    }
                    printf("\n");
                    i = 0;
                    do
                    {
                        scanf(" %c", &ingreso[i]);
                        if (secuencia[i] == ingreso[i])
                        {
                            i++;
                            puntaje = puntaje + ACIERTO_NIVEL_I;
                        }
                        else
                            encontrada = false;
                    } while (encontrada && i <= n);
                    n++;
                } while (encontrada && n < NIVEL_I);
                if (puntaje > mejorP)
                {
                    mejorP = puntaje;
                    strcpy(nombreP, nombre);
                }
            }
            break;
            case 'a':
            case 'A':
            {

                printf("Pulse <enter> para comenzar el juego. ");
                scanf("%c", &h);
                getchar();
                char secuencia[NIVEL_A];
                char ingreso[NIVEL_A];
                for (i = 0; i < NIVEL_A; i++)
                {
                    randoms = rand() % 4;
                    switch (randoms)
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
                n = 0;
                encontrada = true;
                do
                {
                    for (i = 0; i <= n; i++)
                    {
                        printf("%c", secuencia[i]);
                        sleep(TIEMPO_COLOR_A);
                        system("clear");
                    }
                    printf("\n");
                    i = 0;
                    do
                    {
                        scanf(" %c", &ingreso[i]);
                        if (secuencia[i] == ingreso[i])
                        {
                            i++;
                            puntaje = puntaje + ACIERTO_NIVEL_A;
                        }
                        else
                            encontrada = false;
                    } while (encontrada && i <= n);
                    n++;
                } while (encontrada && n < NIVEL_A);
                if (puntaje > mejorP)
                {
                    mejorP = puntaje;
                    strcpy(nombreP, nombre);
                }
            }
            break;
            default:
                printf("Caracter incorrecto, ingrese otro\n");
                caracter = false;
                break;
            }

            if (caracter)
            {
                printf("Debe ingresar S(s) o N(n). Vuelva a intentarlo: \n ");
                scanf(" %c", &jugar);
                while (jugar != 'N' && jugar != 'S')
                {
                    printf("Caracter incorrecto, vuelva a intentarlo: \n");
                    scanf(" %c", &jugar);
                }
            }
            else
                jugar = 'S';
        }
        else
            jugar = 'N';

    } while (jugar == 'S' || jugar == 's');

    /*
    printf("Resultados del Juego: \n");
    printf("Principiante: %s %d puntos \n", &nombreP, mejorP);
    printf("Intermedio: %s %d puntos \n", &nombreP, mejorP);
    printf("Avanzado: %s %d puntos \n", &nombreP, mejorP);
    */
}
