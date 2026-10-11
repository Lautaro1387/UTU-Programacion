#include "linea.h"

typedef struct nodo_texto * texto; // conjunto de linea 

struct nodo_texto{
    linea dato;
    texto sig;

};


texto CrearTexto();
unsigned int CantidadLineas(texto t);
void ImprimirTextoCompleto(texto t);