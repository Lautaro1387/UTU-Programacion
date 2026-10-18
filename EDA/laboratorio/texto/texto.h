#ifndef TEXTO_H
#define TEXTO_H

#include "../linea/linea.h"

typedef struct nodo_texto * texto; // conjunto de linea 


texto CrearTexto();


linea ObtenerLinea(texto t);

unsigned int CantidadLineas(texto t);
void ImprimirTextoCompleto(texto t);


#endif
