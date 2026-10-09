#include "definiciones.h"
#include <stdio.h>
#include <string.h>



typedef struct nodo_linea * linea;

struct nodo_linea{
   Cadena palabra;
   linea sig; 
};


linea CrearLinea();
    // Crea una nueva linea
