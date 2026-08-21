#include <stdio.h>
#include "cabezales.h"
// En parcial C++



struct nodo_lista{
    int dato;
    lista sig;
};

bool isElement(int x, lista l){
    // Retorna true si x pertenece a l, false en caso contrario.

    if (x == l->dato){
        return true;
    } else {
        return false;
    }
}

int Length(lista l){
    // Retorna la cantidad de elementos de la lista.
    int cant = 0;
    if (l == NULL){
        return cant;
    } else{
        while (l->sig != NULL){
            cant++;
            l = l->sig;
            return cant;
        }
    }
}

int Last(lista l){
    // Retorna el último elemento de l.
    // Pre: l no es vacía.
     while (l->sig != NULL){
        l = l->sig;
        return l->dato;
    }
}
/*
int Max(lista l){
    // Retorna el máximo elemento de l.
    // Pre: l no es vacía.
    int max = l->dato;
    while (l->sig != NULL){
        if (l->sig max){
            
    }
}

}
*/


/*
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
// rreturn l == null && p == null;