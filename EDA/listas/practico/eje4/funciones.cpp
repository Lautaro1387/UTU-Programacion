#include <stdio.h>
#include "cabezales.h"

// Implemente iterativamentelas siguientes operaciones accediendo directamente a la representación y sin usar
// procedimientos auxiliares y sin que las soluciones retornadas compartan memoria con los paráme

struct nodo_lista{
    int dato;
    lista sig;
};

lista Null(){
    return NULL;
}
// Crea la lista vacía.

lista Cons(int x, lista l){

    // Inserta el elemento x al principio de la lista l.
    lista aux = new(nodo_lista);
    aux->dato = x;
    aux->sig = l;
    return aux;   
}

bool IsEmpty(lista l){
    // POS: retorna ture si l es vacia, false en caso contrario (comentario agregado por mi)
    // Retorna true si l es vacía, false en caso contrario (comentario del practico ya agregado)
    return l == NULL;
}
int Head(lista l){
    // Retorna el primer elemento de la lista.
    // Pre: l no vacía.
    return l->dato;
}

lista Tail(lista l){
    // Retorna la lista sin su primer elemento.
    // Pre: l no vacía.
     return l->sig;
}
// Implemente las siguientes operaciones recursivamente utilizando exclusivamente las operaciones anteriores
// (sin acceder a la representación interna):

bool IsElement(int x, lista l);
// Retorna true si x pertenece a l, false en caso contrario.

lista Remove(int x, lista l){ // CHEQUEAR

    // Retorna la lista fruto de eliminarx en l.
    // l no comparte memoria con la lista resultado.
    if (IsEmpty(l)){
        return Null();
    } else {
        if (Head(l)  == x)
            return Remove(x, Tail(l));
        else
            return Cons(Head(l), Remove(x, Tail(l)));
    }

}
int Length(lista l){
    if (IsEmpty(l)){
        return Null();
    } else {
        return 1 + Lenght(l);
    }
}
// Retorna la cantidad de elementos de la lista.

lista Snoc(int x, lista l){
    // Retorna la lista fruto de insertar el elemento x al final de la lista l.
    // l no comparte memoria con la lista resultado.
    
}
lista Append(lista l, lista p){
    // Retorna la lista fruto de agregar la lista p al final de la lista l.
    // l y p no comparten memoria con la lista resultado.


    
}
int Last(lista l);
// Retorna el último elemento.
// Pre: l no vacía.

int HowMany(int x, lista l);
// Cuenta las ocurrencias del natural x en la lista l

int Max(lista l);
// Retorna el máximo elemento de l.
// Pre: l no vacía.

bool IsSorted(lista l);
// Retorna true si l está ordenada, false en caso contrario.

lista Change(int x, int y, lista l);
// Retorna una nueva lista fruto de cambiar x por y en l.
// l no comparte memoria con la lista resultado.

lista InsBefore(int x, int y, lista l);
// Retorna una nueva lista fruto de insertar x antes de y en l.
// l no comparte memoria con la lista resultado.

lista InsAround(int x, int y, lista l);
// Retorna una nueva lista fruto de insertar x antes y después de y en l.
// l no comparte memoria con la lista resultado.

bool Equals(lista l, lista p);
// Retorna true si las listas l y p son iguales (mismos elementos en el mismo orden)
// false en caso contrario.

void Show(lista l);
// Muestra los elementos de la lista l separados por comas.


// PENDIENTES
// TAKE y DROP de forma recursiva sin representacion interna