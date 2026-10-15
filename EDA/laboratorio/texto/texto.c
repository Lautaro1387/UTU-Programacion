#include <stdio.h>
#include "../definiciones.h"
#include "texto.h"

struct nodo_texto{
    linea dato;
    texto sig;

};
linea ObtenerLinea(texto t){
    // check proximo  
    return t->dato;
}


