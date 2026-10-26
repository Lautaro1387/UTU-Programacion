#include <stdio.h>
#include "../definiciones.h"
#include "linea.h"
#include <string.h>


struct nodo_linea {
   Cadena palabra;
   linea sig;
};

linea CrearLinea(){
    // Crea un nuevo nodo de línea vacio
    linea l = new(nodo_linea);
    l->palabra = NULL;
    l->sig = NULL;
    return l;
}


void LineaIgualLinea(linea l, linea nueva_linea){
    // establece la linea siguiente.
    if (l != NULL)
        l = nueva_linea;
}

void LineaSiguienteIgualLinea(linea l, linea nueva_linea){
    // establece la linea siguiente.
    if (l != NULL)
    l->sig = nueva_linea;
}
/*

void InsertarPalabraEnLinea(linea l, Cadena palabra){
    // inserta la palabra en la linea l.
    if (l != NULL)
    l->palabra = palabra;
}
*/

linea InsertarPalabraEnLinea(linea l, Cadena palabra){
    // inserta la palabra en la linea l.
    if (l != NULL)
        l->palabra = palabra;
    return l;
}

linea ObtenerSiguienteLinea(linea l){
    // devuelve la linea siguiente.
    if (l == NULL)
        return NULL;
    else
        return l->sig;
}

Cadena LineaPalabra(linea l){
    // devuelve la palabra
    if (l == NULL)
        return NULL;
    else
        return l->palabra;
}

Posicion CantidadPalabras(linea l){
// Cant de palabras
    if ( l == NULL){
        return 0;
    }
    else {
        return 1 + CantidadPalabras(l->sig);
    }
}

Cadena ObtenerPalabra(linea l, Posicion pos) {
    // Obtener la palabra en una posición.
    if (l == NULL){
        return NULL;
    } else {
        linea iter = l;
        while (iter != NULL && pos > 1){
            iter = iter->sig;
            pos--;
        }
        return iter->palabra;
    }
}

linea InsertarUltimaLinea(linea l, linea nueva_palabra){
    if (l == NULL){
        return nueva_palabra;
    } else {
        linea iter = l;
        while (iter->sig != NULL)
            iter = iter->sig;
        iter->sig = nueva_palabra;
        return l;
    }
}


linea InsertarPalabraAlInicioLinea(linea l, Cadena palabra){
    linea aux = CrearLinea();
    aux->palabra = palabra;
    if (l == NULL){
        return aux;
    } else {
        aux->sig = l;
        return aux;
    }
}


Posicion CantidadPalabras(linea l);
// cuenta y retorna el número de nodos en la lista l.

linea LineaExtraerUltimo(linea &l);
// quita el último nodo de la lista l (ajustando el penúltimo a sig=null)
// y lo devuelve. Retorna NULL si la lista queda vacía.





