#include "diccionario.h"
#include <iostream>
#include <cstring>

using namespace std;

struct nodo_diccionario {
    Cadena palabra;
    Diccionario izq;
    Diccionario der;
};

Diccionario CrearDiccionario() {
    return NULL;
}

Diccionario CrearNodo(Cadena palabra) {
    Diccionario  nuevo = new (nodo_diccionario);
    nuevo->palabra = new char[strlen(palabra) + 1];//Preguntar si se puede utilizar esta funcion stlen R:si se puede
    strcpy(nuevo->palabra, palabra);
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

// inserat en orden O(log n)

bool IngresarPalabraDiccionarioD(Diccionario& d, Cadena palabraAIngresar) {
    if (d == NULL) {
        d = CrearNodo(palabraAIngresar);
        return true;
    }

    int comp = strcmp(palabraAIngresar, d->palabra);
    if (comp < 0) {
        return IngresarPalabraDiccionarioD(d->izq, palabraAIngresar);
    } else if (comp > 0) {
        return IngresarPalabraDiccionarioD(d->der, palabraAIngresar);
    } else {
        // La palabra ya existe en el diccionario
        return false;
    }
}

// O(log n)

bool PerteneceDiccionario(Diccionario d, Cadena palabra) {
    if (d == NULL) return false;

    int comp = strcmp(palabra, d->palabra);
    if (comp == 0) return true;
    if (comp < 0) return PerteneceDiccionario(d->izq, palabra);
    return PerteneceDiccionario(d->der, palabra);
}

//imprimir O(n) peor caso


void ImprimirDiccionarioD(Diccionario d){

if (d != NULL) {
        ImprimirDiccionarioD(d->izq);
        cout << d->palabra << endl;
        ImprimirDiccionarioD(d->der);
    }
}



//eliminar nodo abb

Diccionario ObtenerMinimo(nodo_diccionario* nodo){
    nodo_diccionario* actual = nodo;
    while (actual && actual->izq != NULL) {
        actual = actual->izq;
    }
    return actual;
}

TipoRetorno BorrarPalabraDiccionario(Diccionario& d, Cadena palabraABorrar) {
    if (d == NULL) return ERROR;

    int comp = strcmp(palabraABorrar, d->palabra);
    if (comp < 0) {
        return BorrarPalabraDiccionario(d->izq, palabraABorrar);
    } else if (comp > 0) {
        return BorrarPalabraDiccionario(d->der, palabraABorrar);
    } else {
        //nodo hoja
        if (d->izq == NULL) {
            nodo_diccionario* temp = d->der;
            delete[] d->palabra;
            delete d;
            d = temp;
        } else if (d->der == NULL) {
            nodo_diccionario* temp = d->izq;
            delete[] d->palabra;
            delete d;
            d = temp;
        } else {
            //nodo con 2 hijos
            nodo_diccionario * temp = ObtenerMinimo(d->der);//es lo mismo?          
            
            // Copiar la palabra del sucesor
            delete[] d->palabra;
            d->palabra = new char[strlen(temp->palabra) + 1];//Preguntar si se puede utilizar esta funcion strlen
            strcpy(d->palabra, temp->palabra);

            // Eliminar el sucesor
            BorrarPalabraDiccionario(d->der, temp->palabra);
        }
        return OK;
    }
}


void DestruirDiccionario(Diccionario& d) {
    if (d != NULL) {
        DestruirDiccionario(d->izq);
        DestruirDiccionario(d->der);
        delete[] d->palabra;
        delete d;
        d = NULL;
    }
}