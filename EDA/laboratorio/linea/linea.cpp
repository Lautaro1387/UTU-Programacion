#include <stdio.h>
#include "../definiciones.h"
#include "linea.h"
#include <cstring>


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
    return l->sig;
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

linea GuardarPalabraEnLinea(linea l, Cadena palabra){
    // inserta la palabra en la linea l.
    if (l == NULL)
        return l;
    else {
        Cadena copia = new char[strlen(palabra) + 1];
        strcpy(copia, palabra);
        l->palabra = copia;
        return l;
    }
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
            // insertar la palabra al final de la linea
            aux->sig = iter;
            return aux; 
        }
        else {
            // Insertar palabra en el medio y en el principio
            aux->sig = iter;
            ant->sig = aux;
            return l;
        }
    } else
        return l;
}

void ImprimirT(linea l){
    if (l == NULL)
        printf("Linea vacia");
        linea iter = l;
    while (iter != NULL){
        // colocarle indice de la linea actual
        printf("%s", iter->palabra);
        iter = iter->sig;
    }
}


linea ObtenerPosicionPalabra(linea l, Posicion posicionPalabra){
    linea iter = l;
    linea ant;
    if (l != NULL) {
        while (iter != NULL && posicionPalabra > 1){
            ant = iter;
            iter = iter->sig;
            posicionPalabra--;
        }
        if (posicionPalabra == 1){
            ant = iter->sig;
            if (iter == l){
                l = iter->sig;
            }
            delete iter;
            // iter = NULL;
            return l;
        }
    }
}

linea EliminarTodaPalabra(linea l){
    if (l->sig == NULL)
        return NULL;
    else {
        return EliminarTodaPalabra(l->sig);
    }
}

// Borrar todas las ocurrencias de palabraABorrar en la línea l.
linea EliminarOcurrenciasEnTexto(linea l, Cadena palabraABorrar) {
    if (l == NULL)
        return NULL;
    else {
        int comp = strcmp(palabraABorrar, l->palabra);
        if (comp == 0) {
            delete(l->palabra);
            return EliminarOcurrenciasEnTexto(l->sig, palabraABorrar);
        } else
            l->sig = EliminarOcurrenciasEnTexto(l->sig, palabraABorrar);
            return l;
    }
}


linea EliminarOcurrenciasEnLinea(linea l, Cadena palabraABorrar) {
    if (l == NULL)
        return NULL;
    else {
        int comp = strcasecmp(palabraABorrar, l->palabra);
        if (comp == 0) {
            linea sig = l->sig;
            delete l;
            return EliminarOcurrenciasEnLinea(sig, palabraABorrar); 
        } else {
            // no coincide
            l->sig = EliminarOcurrenciasEnLinea(l->sig, palabraABorrar);
            return l;
        }
    }
}

linea comprimirLinea(linea l){
    if (l == NULL)
        return NULL;
    else {
        if (l->palabra == NULL) {
            linea aux = l;
            l = l->sig;
            delete aux;
            return comprimirLinea(l);
        } else {
            l->sig = comprimirLinea(l->sig);
        }
        return l;
    }
}