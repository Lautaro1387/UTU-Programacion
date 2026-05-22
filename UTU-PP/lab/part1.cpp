#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // rand - srand
#include <time.h>
#include <unistd.h>
// sleep(2);
// system("clear");

const int N = 100; // nombre;
// Largo de la secuencia de colores dependiendo el nivel
const int NIVEL_P = 6;
const int NIVEL_I = 8;
const int NIVEL_A = 10;

//Tiempo en segundos que muestra cada colores dependiendo el nivel
const float TIEMPO_COLOR_P = 1.5;
const float TIEMPO_COLOR_I = 1.3;
const float TIEMPO_COLOR_A = 1;

const int ACIERTO_NIVEL_P = 1;
const int ACIERTO_NIVEL_I = 3;
const int ACIERTO_NIVEL_A = 5;

int main(){

    int i, puntaje, randoms, j;
    char nombre[100];
    char h,nivel;
    char centinela[]={'f','i','n','\0'};
    bool t = true, encontrada = true;
    // Generar un número aleatorio y limitarlo al rango de 0 a 3
    srand(time(NULL));
    randoms = rand() % 4;


    printf("Bienvenido al Juego de SIMON ver. 1.0.\n");
    printf("Ingrese su nombre\n");
    i=0;
    do
    {
        scanf("%c",&nombre[i]);
        if(nombre[i]!='\n')
            i++;
    }while( i<N && nombre[i]!='\n');
    nombre[i]= '\0';
    i=0;
    do
    {
        if(nombre[i]==centinela[i])
            i++;
        else
            t=false;
    }while(nombre[i]!='\0' && t);
    if(!t)
    {
       // do while
            printf("Ingrese nivel del Juego (p, i, a): ");
            scanf(" %c",&nivel);
        
            switch(nivel)
            {
                case 'p':case 'P' :
                                    printf("Pulse <enter> para comenzar el juego.");
                                    
                                    while (h!='\n') {
                                    scanf("%c",&h);
                                }
                                scanf("%c",&h);
                                
                                
                                
                                char secuencia[NIVEL_P];
                                char ingreso[NIVEL_P];
                                for (i=0; i < NIVEL_P; i++) { //
                                    switch (randoms)
                                    {
                                        case 0:
                                        secuencia[i]='R';
                                           break;
                                           case 1:
                                           secuencia[i]='A';
                                           break;
                                           case 2:
                                           secuencia[i]='V';
                                           break;
                                           case 3:
                                           secuencia[i]='N';
                                           break;
                                           
                                        }
                                    }       
                                    do { 
                                            printf("%c \n", secuencia[j]);
                                            //sleep(TIEMPO_COLOR_P);
                                            // system("clear");
                                            scanf(" %c \n", &ingreso[j]);
                                            if (secuencia[j] == ingreso[j])
                                            {
                                                j++;
                                                puntaje = puntaje + ACIERTO_NIVEL_P;
                                                printf("test - correcto");
                                            }
                                        else {
                                            encontrada = false;
                                            printf("test - incorrecto");
                                            }
                                        
                                    } while(encontrada && j < NIVEL_P );
                                break;
                                t=false;

                                            // Problema actual en secuencia[i] queda el valor de f y si lo detecta como correcto si coloco ese valor
                                            
                                            // 
                                            
                                           

                case 'i':case 'I' : printf("Pulse <enter> para comenzar el juego.\n ");
                                   scanf("%c",&h);
                                   while(h!='\n')
                                    scanf("%c",&h);
                                   secuencia[NIVEL_I];
                                   break;
                case 'a':case 'A' :printf("Pulse <enter> para comenzar el juego.\n ");
                                   scanf("%c",&h);
                                   while(h!='\n')
                                    scanf("%c",&h);
                                   secuencia[NIVEL_A];
                                   break;
                default : printf("Caracter incorrecto, ingrese otro\n");
                          break;
            }
            printf("%c %d", puntaje);



    }
} 

