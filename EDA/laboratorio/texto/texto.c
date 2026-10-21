#include <stdio.h>
#include "../definiciones.h"
#include "texto.h"

struct nodo_texto {
    linea dato;
    texto sig;
};

linea ObtenerLinea(texto t){
    // check proximo  
    return t->dato;
}

texto crearTextoNull(texto t){
    return NULL;
}

texto CrearTexto(){
    texto t = new(nodo_texto);
    t->dato = CrearLinea();
    t->sig = NULL;
    return t;
}

texto InsertarLineaTexto(texto t, linea l){
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

linea TextoDato(texto t){
    if (t == NULL)
        return NULL;
    else
        return t->dato;
}

texto TextoSiguiente(texto t){
    if (t == NULL)
        return NULL;
    else
        return t->sig;
}


// devuelve el puntero a la última línea (e->ultima_linea).


texto TextoPrimeraLinea(editor e){
    // devuelve el puntero a la primera línea de editor e (i.e. e->primer_linea).
    if (e == NULL)
        return NULL;
    else
        return e->primer_linea;
}

texto TextoUltimaLinea(editor e){
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

texto InsertarLineaEnPosicionTexto(Texto iter, Texto ant, Texto aux){

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

/*

texto InsertarLineaTexto(editor e){

    texto aux = CrearTexto();

    if (e->primer_linea == NULL){ // documento vacio
		e->primer_linea = aux;
		e->ultima_linea = aux;
	} else {
		e->ultima_linea->sig = aux;
		e->ultima_linea = aux;
	}
}
*/