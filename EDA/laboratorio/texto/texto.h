#include "linea.h"

typedef struct nodo_texto * texto;

struct nodo_texto{
    linea dato;
    texto sig;
};