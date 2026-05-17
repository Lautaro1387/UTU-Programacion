#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

int main()
{
    char nombre[30];

    char secuencia[MAX];
    char ingreso[MAX];

    char nivel;

    int largoNivel;
    int puntos;

    int ronda;
    int puntaje = 0;

    int i;
    int correcto;

    srand(time(NULL));

    printf("====== JUEGO SIMON ======\n\n");

    /* pedir nombre */

    printf("Ingrese nombre: ");
    scanf("%s", nombre);

    /* terminar */

    if(nombre[0] == 'f' &&
       nombre[1] == 'i' &&
       nombre[2] == 'n')
    {
    }

    /* pedir nivel */

    printf("\nNiveles:\n");
    printf("p = Principiante\n");
    printf("i = Intermedio\n");
    printf("a = Avanzado\n");

    printf("\nIngrese nivel: ");
    scanf(" %c", &nivel);

    /* configurar nivel */

    switch(nivel)
    {
        case 'p':

            largoNivel = 6;
            puntos = 1;

            break;

        case 'i':

            largoNivel = 8;
            puntos = 3;

            break;

        case 'a':

            largoNivel = 10;
            puntos = 5;

            break;

        default:

            printf("Nivel incorrecto");

    }

    /* juego */

    for(ronda = 1; ronda <= largoNivel; ronda++)
    {
        printf("\nRONDA %d\n", ronda);

        /* generar color */

        int numero;

        numero = rand() % 4;

        switch(numero)
        {
            case 0:
                secuencia[ronda - 1] = 'R';
                break;

            case 1:
                secuencia[ronda - 1] = 'A';
                break;

            case 2:
                secuencia[ronda - 1] = 'V';
                break;

            case 3:
                secuencia[ronda - 1] = 'N';
                break;
        }

        /* mostrar secuencia */

        printf("Secuencia:\n");

        for(i = 0; i < ronda; i++)
        {
            putchar(secuencia[i]);
            printf(" ");
        }

        printf("\n");

        /* pedir secuencia */

        printf("Ingrese la secuencia:\n");

        for(i = 0; i < ronda; i++)
        {
            scanf(" %c", &ingreso[i]);
        }

        /* comparar */

        correcto = 1;

        for(i = 0; i < ronda; i++)
        {
            if(secuencia[i] != ingreso[i])
            {
                correcto = 0;
            }
        }

        /* resultado */

        if(correcto == 1)
        {
            puntaje = puntaje + puntos;

            printf("Correcto\n");
            printf("Puntaje: %d\n", puntaje);
        }
        else
        {
            printf("Incorrecto\n");
            printf("Puntaje final: %d\n", puntaje);

            break;
        }

        /* pausa */

        printf("\nPresione ENTER para continuar...");
        getchar();
        getchar();
    }

    printf("\nFin del juego\n");

}