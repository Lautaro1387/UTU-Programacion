#include <stdio.h>
#include "../definiciones.h"
#include "texto.h"


struct nodo_linea {
   Cadena palabra;
   linea sig;
};

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

texto TextoSiguiente(texto t){
    if (t == NULL)
    return NULL;
    else
    return t->sig;
}

// No usada actualmente
texto InsertarUltimaLineaTexto(texto t, linea l){
    texto aux = CrearTexto();
    aux->dato = l;
    if (t == NULL){
        return aux;
    } else {
        texto iter = t;
        while (iter->sig != NULL)
            iter = iter->sig;
        iter->sig = aux;
        return t;
    }
}

texto InsertarLineaTexto(linea l, linea nueva_palabra, texto iter){
    // insertar la linea l en el medio de la lista t, manteniendo el orden de las lineas.

    nueva_palabra->sig = l->sig;
    l->sig = nueva_palabra;
    return iter;
}

// devuelve el puntero a la última línea (e->ultima_linea).


texto TextoPrimera(editor e){
    // devuelve el puntero a la primera línea de editor e (i.e. e->primer_linea).
    if (e == NULL)
        return NULL;
    else
        return e->primer_linea;
}

texto TextoUltima(editor e){
    // devuelve el puntero a la última línea (e->ultima_linea).
    if (e->ultima_linea == NULL){
        return NULL;
    } else {
        while (e->ultima_linea->sig != NULL){
            e->ultima_linea = e->ultima_linea->sig;
        }
        return e->ultima_linea;
    }
}

texto InsertarLineaEnPosicionTexto(texto iter, texto ant, texto aux){

    if (iter == NULL){
			aux->sig = iter;
			ant->sig = aux;
            return aux;
		} else {
			aux->sig = iter;
			ant->sig = aux;
            return aux;
		}
}


texto insertarLineaAlInicio(texto t, Cadena palabra){
    return InsertarPalabraAlInicio(TextoDato(t), palabra);
}