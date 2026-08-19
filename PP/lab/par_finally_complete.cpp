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

    int i, j, n, puntaje, randoms, mejorP = 0, mejorI = 0, mejorA = 0;
    char h, nivel, nombre[N], nombreP[N], nombreI[N], nombreA[N];
    bool f = false, caracter = true, encontrada;
    char jugar = 'S';

    // Genera un número aleatorio y limitarlo al rango de 0 a 3
    srand(time(NULL));

    nombreP[0] = '\0';
    nombreI[0] = '\0';
    nombreA[0] = '\0';

    do
    {
        printf("Bienvenido al Juego de SIMON ver. 1.0.\n");
        printf("Ingrese su nombre (fin=fin del juego)\n");
        j = 0;

        scanf("%c", &nombre[j]);

        while (nombre[0] == '\n')
        {
            printf("Debe ingresar nombre del Jugador o fin para finalizar el juego. Vuelva a intentar. \n");
            scanf("%c", &nombre[j]);
        }
        while (nombre[j] != '\n' && j < N)
        {
            j++;
            scanf("%c", &nombre[j]);
        }

        nombre[j] = '\0';

        i = 0;
        if (strcmp(nombre, "fin") == 0)
            f = true;

        if (!f)
        {
            puntaje = 0;
            do
            {
                printf("Ingrese nivel del Juego (p, i, a): ");
                scanf(" %c", &nivel);
                if (nivel != 'p' && nivel != 'i' && nivel != 'a')
                    printf("Nivel del juego no es valido. Vuelva a intentarlo. \n");

            } while (nivel != 'p' && nivel != 'i' && nivel != 'a');

            switch (nivel)
            {
            case 'p':
            case 'P':
            {
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
                        sleep(TIEMPO_COLOR_P);
                        system("cls");
                        printf("%c", secuencia[i]);
                        sleep(TIEMPO_COLOR_P);
                        system("cls");
                    }

                    i = 0;
                    puntaje = 0;
                    do
                    {
                        scanf(" %c", &ingreso[i]);

                        if (secuencia[i] == ingreso[i])
                        {
                            i++;
                            puntaje = puntaje + ACIERTO_NIVEL_P;
                        }
                        else
                        {
                            encontrada = false;
                            printf("Incorrecto, fin del juego \n");
                        }
                    } while (encontrada && i <= n);
                    n++;

                } while (encontrada && n < NIVEL_P);

                if (puntaje >= mejorP)
                {
                    mejorP = puntaje;
                    strcpy(nombreP, nombre);
                }
                break;
            }
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
                        sleep(TIEMPO_COLOR_I);
                        system("cls");
                        printf("%c", secuencia[i]);
                        sleep(TIEMPO_COLOR_I);
                        system("cls");
                    }
                    i = 0;
                    puntaje = 0;
                    do
                    {
                        scanf(" %c", &ingreso[i]);

                        if (secuencia[i] == ingreso[i])
                        {
                            i++;
                            puntaje = puntaje + ACIERTO_NIVEL_I;
                        }
                        else
                        {
                            encontrada = false;
                            printf("Incorrecto, fin del juego \n");
                        }
                    } while (encontrada && i <= n);
                    n++;

                } while (encontrada && n < NIVEL_I);
                if (puntaje >= mejorI)
                {
                    mejorI = puntaje;
                    strcpy(nombreI, nombre);
                }
                break;
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
                        sleep(TIEMPO_COLOR_A);
                        system("cls");
                        printf("%c", secuencia[i]);
                        sleep(TIEMPO_COLOR_A);
                        system("cls");
                    }

                    i = 0;
                    puntaje = 0;
                    do
                    {
                        scanf(" %c", &ingreso[i]);
                        if (secuencia[i] == ingreso[i])
                        {
                            i++;
                            puntaje = puntaje + ACIERTO_NIVEL_A;
                        }
                        else
                        {
                            encontrada = false;
                            printf("Incorrecto, fin del juego \n");
                        }
                    } while (encontrada && i <= n);
                    n++;
                } while (encontrada && n < NIVEL_A);
                if (puntaje >= mejorA)
                {
                    mejorA = puntaje;
                    strcpy(nombreA, nombre);
                }
                break;
            }
            break;
            default:
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
        if (!f)
            getchar();
    } while (jugar == 'S' || jugar == 's');
    printf("Resultados del Juego: \n");
    printf("Principiante: %s - %d puntos \n", nombreP, mejorP);
    printf("Intermedio: %s - %d puntos \n", nombreI, mejorI);
    printf("Avanzado: %s - %d puntos \n", nombreA, mejorA);
}
