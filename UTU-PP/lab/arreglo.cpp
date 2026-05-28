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

    int i, j, n, puntaje = 0, randoms, mejorP = 0, mejorI = 0, mejorA = 0, mejor_usuario = 0;
    int nivel_usuario;
    int tiempo_usuario;
    int puntaje_usuario;
    char c ;
    char h, nivel;
    char nombre[N];
    char nombreP, nombreI, nombreA, mejor_nombre;
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
        if(strcmp(nombre, "fin") == 0)
            f=true;

        if (!f)
        {
            // do while (para seguir jugando)
            puntaje = 0;
            printf("Ingrese nivel del Juego (p, i, a): ");
            scanf(" %c", &nivel);

            switch (nivel)
            {
            case 'p':
            case 'P':
                nivel_usuario = NIVEL_P;
                puntaje_usuario = ACIERTO_NIVEL_P;
                tiempo_usuario = TIEMPO_COLOR_P;
                mejor_usuario = mejorP;
                // mejor_nombre = nombreP;
                break;
            case 'i':
            case 'I':
                nivel_usuario = NIVEL_I;
                puntaje_usuario = ACIERTO_NIVEL_I;
                tiempo_usuario = TIEMPO_COLOR_I;
                mejor_usuario = mejorI;
                // mejor_nombre = nombreI;
                break;
            case 'a':
            case 'A':
                nivel_usuario = NIVEL_A;
                puntaje_usuario = ACIERTO_NIVEL_A;
                tiempo_usuario = TIEMPO_COLOR_A;
                mejor_usuario = mejorA;
                // mejor_nombre = nombreA;
                break;
            default:
                printf("Caracter incorrecto, ingrese otro\n");
                caracter = false;
                break;
            }

            char secuencia[nivel_usuario];
            char ingreso[nivel_usuario];
            printf("Pulse <enter> para comenzar el juego. ");
            scanf("%c", &h); // NO TOCAR
            getchar();

            for (i = 0; i < nivel_usuario; i++)
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
                    sleep(tiempo_usuario);
                }
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
                        puntaje = puntaje + puntaje_usuario;
                    }
                    else
                        encontrada = false;
                } while (encontrada && i <= n);
                n++;
            } while (encontrada && n < nivel_usuario);
            if (puntaje > mejor_usuario)
            {
                mejor_usuario = puntaje;
                strcpy(mejor_nombre, nombre);
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
        printf("Resultados del Juego: \n");
        printf("Principiante: %s %d puntos \n", &nombreP, mejorP);
        printf("Intermedio: %s %d puntos \n", &nombreI, mejorI);
        printf("Avanzado: %s %d puntos \n", &nombreA, mejorP);
    
}
