#include <stdio.h>
#include "../definiciones.h"
#include "texto.h"
#include <string.h>
#include "../linea/linea.h"


struct nodo_texto {
    linea dato;
    texto sig;
};


texto crearTextoNull(texto t){
    return NULL;
}

texto CrearTexto(){
    texto t = new(nodo_texto);
    t->dato = CrearLinea();
    t->sig = NULL;
    return t;
}

linea ObtenerLinea(texto t){
    // check proximo  
    if (t == NULL)
        return NULL;
    return t->dato;
}


linea TextoDato(texto t){
    if (t == NULL)
        return NULL;
    return t->dato;
}


texto TextoSiguiente(texto t){
    if (t == NULL)
        return NULL;
    return t->sig;
}

texto InsertarLineaTextoVacio(texto t){
    texto aux = CrearTexto();
    // aux->dato = l;
    // aux->sig = NULL;

    if (t == NULL)
        return aux;

    texto iter = t;
    while (iter->sig != NULL)
        iter = iter->sig;
    iter->sig = aux;
    return t;
}

// No usada actualmente
texto InsertarUltimaLineaTexto(texto t, linea l){
    texto aux = CrearTexto();
    aux->dato = l; // l-palabra
    // aux->sig = NULL;

    if (t == NULL)
        return aux;

    texto iter = t;
    while (iter->sig != NULL)
        iter = iter->sig;
    iter->sig = aux;
    return t;
}

texto InsertarLineaTexto(linea l, linea nueva_palabra, texto iter){
    // insertar la linea l en el medio de la lista t, manteniendo el orden de las lineas.
    if (l == NULL)
        return iter;
    LineaIgualLinea(l, nueva_palabra);
    return iter;
}

// devuelve el puntero a la última línea (e->ultima_linea).


texto TextoPrimera(texto t){
    // devuelve el puntero a la primera línea de editor e (i.e. e->primer_linea).
    return t;
}

texto TextoUltima(texto t){
    // devuelve el puntero a la última línea (e->ultima_linea).
    if (t == NULL)
        return NULL;
    while (t->sig != NULL)
        t = t->sig;
    return t;
}

texto InsertarLineaEnPosicionTexto(texto e, texto aux, Posicion pos){
    if (aux == NULL || pos == 0)
        return e;

    texto iter = e;
    texto ant = NULL;
    while (iter != NULL && pos > 1){
        ant = iter;
        iter = iter->sig;
        pos--;
    }
    if (pos > 1)
        return e;

    aux->sig = iter;
    if (ant == NULL)
        return aux;

    ant->sig = aux;
    return e;
}

linea InsertarPalabraAlInicio(texto t, Cadena palabra){
    // inserta el nodo nodo al inicio de la lista l (cambia la cabeza l).
    // hacerla de forma recursiva luego para repetir mas de 1 caso.
    linea aux = CrearLinea();
    InsertarPalabraEnLinea(aux, palabra);
    if (t == NULL || TextoDato(t) == NULL){
        if (t != NULL)
            t->dato = aux;
        return aux;
    }

    aux = LineaIgualLinea(aux, TextoDato(t));
    if (t != NULL)
        t->dato = aux;
    return aux;
}



texto insertarLineaAlInicio(texto t, Cadena palabra){
    texto aux = CrearTexto();
    aux->dato = CrearLinea();
    InsertarPalabraEnLinea(aux->dato, palabra);

    if (t == NULL)
        return aux;

    aux->sig = t;
    return aux;
}