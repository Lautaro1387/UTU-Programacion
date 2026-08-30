#include <stdio.h>
#include "cabezales.h"
// En parcial C++

// ✅​❌​

struct nodo_lista{
    int dato;
    lista sig;
};


// ✅
bool isElement(int x, lista l){ 
    // Retorna true si x pertenece a l, false en caso contrario.
    while (l != NULL){
        if (l->dato == x)
            return true;
        else
            l = l->sig;
    }
    return false;
}

// ✅
int Length(lista l){
    // Retorna la cantidad de elementos de la lista.
    int cant = 0;
    if (l == NULL){
        return cant;
    } else{
        while (l != NULL){
            l = l->sig;
            cant++;
        }
        return cant;
    }
}

// A efectos practicos de int Length(lista l), se puede hacer de la siguiente manera:
/*
int Length(lista l){
    int cant = 0;
    while (l != NULL){
        l = l->sig;
        cant++;
    }
    return cant;
}
*/

// ✅
int Last(lista l){
    // Retorna el último elemento de l.
    // Pre: l no es vacía.
     while (l->sig != NULL){
        l = l->sig;
    }
    return l->dato;
}

// ✅
int Max(lista l){
    // Retorna el máximo elemento de l.
    // Pre: l no es vacía.
    int max = l->dato;
    while (l->sig != NULL){
        if  (l->sig->dato > max)
            max = l->sig->dato;
        l = l->sig;
    }
    return max;
}

// ✅
float Average(lista l){
 // Retorna si la lista no es vacía el promedio de sus elementos. // Pre: l no es vacía.
    float suma = 0.0;
    int cant = 0;
    while (l != NULL){
        suma = suma + l->dato;
        cant++;
        l = l->sig;
}

    return suma/cant;
}


lista Insert(int x, lista l){
// Inserta ordenadamente el elemento x en la lista ordenada l.
    lista aux = new(nodo_lista);
    aux->dato = x;
    lista head = l;
    
    if (l == NULL){
        aux->sig = NULL;
        return aux;
    }
    if (l->dato > x){
        aux->sig = l->sig;
        return aux;
    }
    while (l->sig != NULL){
        if (l->sig->dato < x)
            l = l->sig;
        head = aux;
    }
        return head;
}


// PENDIENTE Terminar Insert y hacer: Snoc, Remove, Equals

/*
aux->sig = l->sig;
l->sig = aux;


lista Remove(int x, lista l){
    
lista recorre = l, aux;
while (l != NULL && l->dato == x){
    
}
}

*/


bool Equals(lista l, lista p){

    // Verifica si las listas l y p 
    // son iguales (mismos elementos en el mismo orden).

    while (l != NULL && p != NULL && l->dato == p->dato){
        l = l->sig;
        p = p->sig;
    }
    if (l == NULL && p == NULL){
        return true;
    } else {
        return false;
    }
}
// return l == null && p == null;