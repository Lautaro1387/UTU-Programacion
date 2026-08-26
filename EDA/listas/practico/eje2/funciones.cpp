#include <stdio.h>
#include "cabezales.h"

// Implemente iterativamentelas siguientes operaciones accediendo directamente a la representación y sin usar
// procedimientos auxiliares y sin que las soluciones retornadas compartan memoria con los paráme

struct nodo_lista{
    int dato;
    lista sig;
};


lista Take(int i, lista l){
// Retorna la lista resultado de tomar los primeros i elementos.
// l no comparte memoria con la lista resultado.

// Notas:
// No preciso un aux, porque es una copia, 
// por ende, el original queda como tal

// No compartir memoria es una copia en profundidad (genero un puntero nuevo y me genera una direccion de un nuevo nodo)
// Recorre se usara para ir conectando los nodos

lista resultado = NULL; // como resultado es NULL, l tambien, por ende, no es necesario chequear
lista recorre; // 
while (i > 0 && l != NULL){
    lista aux = new(nodo_lista);
    aux->dato = l->dato;
    aux->sig = NULL;
    if (resultado == NULL){ // primer elemento
        resultado = aux;
        recorre = resultado;
    } else {
        recorre->sig = aux;
        recorre = recorre->sig;
    }
    i--;
    l = l->sig;
}
    return resultado;

    // Si fuera procedimiento, seria el protitpo de la siguiente manera:
    // void take(int n, lista l, lista &resultado); Igual pero sin el return y si fuera con delete, otro while eliminando los nodos anteriores
}

lista Drop(int u, lista l){

}

lista Merge(lista l, lista p){
    // Genera una lista fruto de intercalar ordenadamente las listas.
    // l y p que vienen ordenadas.
    // l y p no comparten memoria con la lista resultado.
    lista resultado = NULL;
    lista recorre;
    
    while (l != NULL && p != NULL){
        lista aux = new(nodo_lista);
        aux->sig = NULL;
        if (l->dato < p->dato){
            aux->dato = l->dato;
            l= l->sig;
        } else {
            aux->dato = p->dato;
            p = p->sig;
        }
        if (resultado == NULL){
            resultado = aux;
        } else {
            recorre->sig = NULL;
        }
        recorre = aux;
    }
    while (l != NULL){
        lista aux = new(nodo_lista);
        aux->dato = l->dato;
        aux->sig = NULL;
        if (resultado == NULL){
            resultado = aux;
        } else {
            recorre->sig = NULL;
        }
        recorre = aux;
        l = l->dato;
    }
      while (p != NULL){
        lista aux = new(nodo_lista);
        aux->dato = p->dato;
        aux->sig = NULL;
        if (resultado == NULL){
            resultado = aux;
        } else {
            recorre->sig = NULL;
        }
        recorre = aux;
        p = p->dato;
    }

return resultado;

}