#include <stdio.h>
#include "definiciones.h"
#include "linea.h"
#include "../texto/texto.h"


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

linea LineaSiguiente(linea l){
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

linea InsertarPalabraAlInicio(texto t, Cadena palabra){
    // inserta el nodo nodo al inicio de la lista l (cambia la cabeza l).
    linea aux = CrearLinea();
    aux->palabra = palabra;
    aux->sig = NULL;
     if (t->dato == NULL){
        return aux;
    } else {
        aux->sig = TextoDato(t);
        t->dato = aux;
        if (CantidadPalabras(t->dato) > 3){
            linea iter = TextoDato(t);
            linea aux = CrearLinea();
            while (iter->sig != NULL)
                iter = LineaSiguiente(iter);
            strcp(iter->palabra, aux->palabra);
            delete(iter);
            InsertarPalabraAlInicio(t->sig, aux->palabra);
        }
    }
}


texto insertarLineaAlInicio(texto t, Cadena palabra){
    return insertarPalabraAlInicio(t->dato, palabra);
}

Posicion CantidadPalabras(linea l);
// cuenta y retorna el número de nodos en la lista l.

linea LineaExtraerUltimo(linea &l);
// quita el último nodo de la lista l (ajustando el penúltimo a sig=null)
// y lo devuelve. Retorna NULL si la lista queda vacía.

























linea agregarPalabra(texto t, linea l, ){
    if(l->palabra[0] == ' '){
        palabra[0]
    }
}


