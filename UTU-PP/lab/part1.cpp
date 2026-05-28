#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // rand - srand
#include <time.h>
#include <unistd.h>
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

    int i,j, n, puntaje = 0, randoms, mejorP = 0, mejorI = 0, mejorA = 0;
    char h, nivel;
    char nombre[100];
    char nombreP[100];
    bool f = false, encontrada = true;
    char jugar = 'S';
    bool caracter = true;
    
    // Generar un número aleatorio y limitarlo al rango de 0 a 3
    srand(time(NULL));
    
    do
    { // Bucle para seguir jugando
        printf("Bienvenido al Juego de SIMON ver. 1.0.\n");
        printf("Ingrese su nombre\n");
        j = 0;

        // Cambiar esta sección del fin
        do
        {
            scanf("%c", &nombre[j]);
            if (nombre[j] != '\n')
                j++;
        } while (j < N && nombre[j] != '\n');

        nombre[j] = '\0';
        i = 0;
        if(strcmp(nombre, "fin") == 0)
            f=true;

        if (!f)
        {
            // do while (para seguir jugando)
            puntaje = 0;
            printf("Ingrese nivel del Juego (p, i, a): ");
            scanf(" %c", &nivel);
            /*
            do
            {

                if (nivel != 'p' && nivel != 'i' && nivel != 'a')
                printf("Nivel incorrecto. \n");
            } while (nivel != 'p' && nivel != 'i' && nivel != 'a');
            */

            switch (nivel)
            {
            case 'p':
            case 'P':
                printf("Pulse <enter> para comenzar el juego. \n");
                scanf("%c", &h); // NO TOCAR NUNCA
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
                do
                {
                    for (i = 0; i <= n; i++)
                        printf("%c ", secuencia[i]);
                    sleep(TIEMPO_COLOR_P);
                    #ifdef _WIN32
                                        system("cls");
                    #else
                                        system("clear");
                    #endif
                    printf("\n");
                    i = 0;
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
                            printf("Pa tu casa manco gg! \n");
                        }
                    } while (encontrada && i <= n);
                    n++;
                } while (encontrada && n < NIVEL_P);
                if(puntaje > mejorP)
                {
                    mejorP = puntaje;
                    strcpy(nombreP, nombre);

                }

                break;

            case 'i':
            case 'I':
                printf("Pulse <enter> para comenzar el juego.\n ");
                scanf("%c", &h);
                while (h != '\n')
                    scanf("%c", &h);
                break;
            case 'a':
            case 'A':
                printf("Pulse <enter> para comenzar el juego.\n ");
                scanf("%c", &h);
                while (h != '\n')
                    scanf("%c", &h);
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
                while (jugar != 'N' && jugar != 'S'){
                    printf("Caracter incorrecto, vuelva a intentarlo: \n");
                    scanf(" %c", &jugar);
                }
                
            }
            else
            jugar = 'S';
        } else 
            jugar = 'N';

        
    } while (jugar == 'S' || jugar == 's');
        printf("Resultados del Juego: \n");
        printf("Principiante: %s %d puntos \n", &nombreP, mejorP);
        printf("Intermedio: %s %d puntos \n", &nombreP, mejorP);
        printf("Avanzado: %s %d puntos \n", &nombreP, mejorP);
    
}
