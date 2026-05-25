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
    
    int i,n, puntaje = 0, randoms;
    char nombre[100];
    char h, nivel;
    char centinela[] = {'f', 'i', 'n', '\0'};
    bool t = true, encontrada = true;
    char jugar = 'S';
    bool caracter = true;
    
    // Generar un número aleatorio y limitarlo al rango de 0 a 3
    srand(time(NULL));
    
    do { // Bucle para seguir jugando
    printf("Bienvenido al Juego de SIMON ver. 1.0.\n");
    printf("Ingrese su nombre\n");
    i = 0;
    
    
    // Cambiar esta sección del fin
    do
    {
        scanf("%c", &nombre[i]);
        if (nombre[i] != '\n')
        i++;
    } while (i < N && nombre[i] != '\n');
    
    nombre[i] = '\0';
    i = 0;
    do
    {
        if (nombre[i] == centinela[i])
        i++;
        else
        t = false;
    } while (nombre[i] != '\0' && t);
    
    if (!t)
    {
        // do while (para seguir jugando)
        
        // TEST
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
            while(h != '\n')
                scanf("%c", &h);
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
            n=0;
            do
            {
                    for(i=0;i<=n;i++)
                    printf("%c", secuencia[i]);
                    sleep(TIEMPO_COLOR_P);
                    system("clear"); // Comando para Linux / macOS
                    printf("\n");
                    i=0;
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
             } while(encontrada && n < NIVEL_P);
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
            printf("Puntaje: %d ", puntaje);
        
    

    }
    if (caracter) {
        printf("Desea jugar otra partida? (S/N): ");
        scanf(" %c", &jugar);
    }


    } while(jugar == 'S');
}
