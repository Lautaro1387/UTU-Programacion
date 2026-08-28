#ifndef RACIONAL_H
#define RACIONAL_H
// Prototipos

typedef struct nodo_lista * lista;

lista Take(int i, lista l);
// Retorna la lista resultado de tomar los primeros i elementos.
// l no comparte memoria con la lista resultado.
lista Drop(int u, lista l);
// Retorna la lista resultado de no tomar los primeros u elementos.
// l no comparte memoria con la lista resultado.
lista Merge(lista l, lista p);
// Genera una lista fruto de intercalar ordenadamente las listas.
// l y p que vienen ordenadas.
// l y p no comparten memoria con la lista resultado.
lista Append(lista l, lista p);
// Agrega la lista p al final de la lista l.
// l y p no comparten memoria con la lista resultado.

#endif