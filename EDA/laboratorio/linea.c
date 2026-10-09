#include <stdio.h>
#include "definiciones.h"
typedef struct nodo_texto * texto;
typedef struct nodo_linea * linea;
typedef struct nodo_Cadena * Cadena;

struct nodo_texto{
    linea dato;
    texto sig;
};

struct nodo_linea{
   Cadena palabra;
   linea sig; 
};
struct nodo_Cadena{
    char letra;
    Cadena sig;
};



