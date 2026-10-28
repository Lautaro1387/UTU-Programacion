#include <stdio.h>
#include "../definiciones.h"
#include "../linea/linea.h"
#include "../texto/texto.h"


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
/* // Se uso en INsertarPalabra Version anterior
texto InsertarLineaTexto(linea l, linea nueva_palabra, texto iter){
    // insertar la linea l en el medio de la lista t, manteniendo el orden de las lineas.
    if (l == NULL)
    return iter;
    LineaIgualLinea(l, nueva_palabra);
    return iter;
}
*/

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
texto insertar_Palabra_En_Texto(texto t, linea nueva_linea, Posicion posicionLinea, Posicion posicionPalabra){
    texto iter = t;
    if (t->dato == NULL){
        t = InsertarUltimaLineaTexto(t, nueva_linea);
        return t;
    }
    else {
        while (iter != NULL && posicionLinea > 1) {
            iter = iter->sig;
            posicionLinea--;
        }
        if (iter->dato == NULL){
            iter = InsertarUltimaLineaTexto(iter, nueva_linea);
            return iter;
        }
        else {
            if (posicionLinea == 1)
            iter->dato = Insertar_Palabra_En_Linea(iter->dato, nueva_linea, posicionPalabra);
            return t;
        } 
    }
}

linea InsertarPalabraAlInicio(texto t, Cadena palabra){
    // inserta el nodo nodo al inicio de la lista l (cambia la cabeza l).
    // hacerla de forma recursiva luego para repetir mas de 1 caso.
    linea aux = CrearLinea();
    GuardarPalabraEnLinea(aux, palabra);
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
    GuardarPalabraEnLinea(aux->dato, palabra);

    if (t == NULL)
        return aux;

    aux->sig = t;
    return aux;
}


texto ObtenerPosicionLinea(texto t, Posicion posicionLinea, Posicion posicionPalabra){
    texto iter = t;
    if (t != NULL) {
        while (iter != NULL && posicionLinea > 1){
            iter = iter->sig;
            posicionLinea--;
        }
        if (posicionLinea == 1){
            iter->dato = ObtenerPosicionPalabra(iter->dato, posicionPalabra);
            return t;
        }
    }
}


texto ObtenerPosicionLinea2(texto t, Posicion posicionLinea){
    texto iter = t;
    if (t != NULL) {
        while (iter != NULL && posicionLinea > 1){
            iter = iter->sig;
            posicionLinea--;
        }
        if (posicionLinea == 1){
            iter = NULL;
            return t;
        }
    }
}

texto EliminarTodaLinea(texto t){
    if (t->sig == NULL) {
        t->dato = EliminarTodaPalabra(t->dato);
        return NULL;
    }
    else {
        return EliminarTodaLinea(t->sig);
    }
}

texto EliminarOcurrenciasEnLineaTexto(texto t, Posicion posicionLinea, Cadena palabraABorrar){

    texto iter = t;
    if (t != NULL) {
        while (iter != NULL && posicionLinea > 1){
            iter = iter->sig;
            posicionLinea--;
        }
        if (posicionLinea == 1){
            iter->dato = EliminarOcurrenciasEnLinea(iter->dato, palabraABorrar);
            return t;
    } else
        return NULL;
    }
}

texto EliminarOcurrenciasPalabraEnTexto(texto t, Cadena palabraABorrar){

    texto iter = t;
    if (t == NULL)
        return NULL;
    else {
        while (iter != NULL){
            iter->dato = EliminarOcurrenciasEnLinea(iter->dato, palabraABorrar);
            iter = iter->sig;
        }
        return t;
    }
}