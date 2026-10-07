#include <stdio.h>
#include "definiciones.h"
typedef struct nodo_texto * texto;
typedef struct nodo_linea * linea;
typedef struct nodo_palabra * palabra;

struct texto{
    linea dato;
    linea sig;
};

struct nodo_linea{
   Cadena palabras;
   linea sig; 
};
struct nodo_palabra{
    char letra;
    palabra sig;
};


//hola palabra recibida

/*for (i = 0; i < 4; i++){
    palabraAsociada[i]=palabrarecibida[i]

}*/


