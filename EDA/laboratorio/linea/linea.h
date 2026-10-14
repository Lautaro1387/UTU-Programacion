#include "definiciones.h"
#include <stdio.h>
#include <string.h>
#include "texto.h"



typedef struct nodo_linea * linea; // conjunto de palabra


// funciones auxiliares

linea CrearLinea();
    // Crea una nueva linea

linea ObtenerLinea(texto t);

linea ImprimirLinea();

linea DestruirLinea();


