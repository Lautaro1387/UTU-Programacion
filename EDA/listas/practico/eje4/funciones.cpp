#include <stdio.h>
#include "cabezales.h"

// Implemente iterativamentelas siguientes operaciones accediendo directamente a la representación y sin usar
// procedimientos auxiliares y sin que las soluciones retornadas compartan memoria con los paráme

struct nodo_lista{
    int dato;
    lista sig;
};

// Forma recursiva 
lista Take(int i, lista l){
// Retorna la lista resultado de tomar los primeros i elementos.
// l no comparte memoria con la lista resultado.

// Notas:
// No preciso un aux, porque es una copia, 
// por ende, el original queda como tal

// No compartir memoria es una copia en profundidad (genero un puntero nuevo y me genera una direccion de un nuevo nodo)
// Recorre se usara para ir conectando los nodos






}
