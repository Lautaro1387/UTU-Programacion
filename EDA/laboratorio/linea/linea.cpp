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


linea LineaIgualLinea(linea l, linea nueva_linea){
    // establece la linea siguiente.
    if (l != NULL)
        return nueva_linea;
}

linea LineaSiguienteIgualLinea(linea l, linea nueva_linea){
    // establece la linea siguiente.
    if (l != NULL)
        l->sig = nueva_linea;
    return l;
}
/*
void InsertarPalabraEnLinea(linea l, Cadena palabra){
    // inserta la palabra en la linea l.
    if (l != NULL)
    l->palabra = palabra;
}
*/

linea GuardarPalabraEnLinea(linea l, Cadena palabra){
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

linea CambiarSig(linea l){
    if (l == NULL)
        return NULL;
    else
        l->sig = NULL;
    return l;
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
    if (l == NULL)
        return 0;
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

linea Insertar_Palabra_En_Linea(linea l, linea nueva_linea, Posicion posicionPalabra) {
    
    linea iter = l;
    linea aux = nueva_linea;
    linea ant = NULL;

    if (aux == NULL)
        return l;

    if (l == NULL)
        return aux;

    if (l->palabra == NULL && l->sig == NULL) {
            delete l;
            return aux;
    }

    while (iter != NULL && posicionPalabra > 1) {
        ant = iter;
        iter = iter->sig;
        posicionPalabra--;
    }

    if (posicionPalabra == 1) {
        if (ant == NULL) {
            aux->sig = iter;
            return aux; // insertar la palabra al final de la linea
        }
        else {
            aux->sig = iter;
            ant->sig = aux;
            return l;
        }
    } else
        return l;
}

void ImprimirT(linea l){
    linea iter = l;

    while (iter != NULL){
        printf("%s", iter->palabra);
        iter = iter->sig;
    }
}


linea ObtenerPosicionPalabra(linea l, Posicion posicionPalabra){
    linea iter = l;
    if (l != NULL) {
        while (iter != NULL && posicionPalabra > 1){
            iter = iter->sig;
            posicionPalabra--;
        }
        // if (posicionLinea == 1){
            iter = NULL;
            return l;
        //}
    }
}

linea EliminarTodaPalabra(linea l){
    if (l->sig == NULL)
        return NULL;
    else {
        return EliminarTodaPalabra(l->sig);
    }
}

linea EliminarOcurrenciasEnLinea(linea l, Cadena palabraABorrar) {
    if (l == NULL)
        return NULL;
    else {
        if (l->palabra == palabraABorrar) {
            l->palabra == NULL;
            return EliminarOcurrenciasEnLinea(l->sig, palabraABorrar);
        } else
            return EliminarOcurrenciasEnLinea(l->sig, palabraABorrar);
    }
}


Posicion CantidadPalabras(linea l);
// cuenta y retorna el número de nodos en la lista l.

linea LineaExtraerUltimo(linea &l);
// quita el último nodo de la lista l (ajustando el penúltimo a sig=null)
// y lo devuelve. Retorna NULL si la lista queda vacía.





