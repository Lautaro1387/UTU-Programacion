#include "definiciones.h"
#include <stdio.h>
#include <string.h>
#include "texto.h"



typedef struct nodo_linea * linea; // conjunto de palabra

struct nodo_linea{
   Cadena palabra;
   linea sig;
};


// funciones auxiliares

linea CrearLinea();
    // Crea una nueva linea

linea ObtenerLinea(linea l);

linea ImprimirLinea();

linea DestruirLinea();


