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

texto InsertarLinea(texto t, linea l){
    texto aux = CrearTexto();
    aux->dato = l;
    aux->sig = NULL;
    if (t == NULL){
        return aux;
    } else {
        aux->sig = t;
        return aux;
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