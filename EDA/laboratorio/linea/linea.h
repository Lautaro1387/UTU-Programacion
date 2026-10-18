#ifndef LINEA_H
#define LINEA_H

#include "../definiciones.h"
#include <stdio.h>
#include <string.h>



typedef struct nodo_linea * linea; // conjunto de palabra


// funciones auxiliares

linea CrearLinea();
    // Crea una nueva lineaaaaa
linea ImprimirLinea();

linea DestruirLinea();


#endif