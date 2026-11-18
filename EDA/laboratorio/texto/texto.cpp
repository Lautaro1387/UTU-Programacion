#include "../definiciones.h"
#include "../linea/linea.h"
#include "../texto/texto.h"
#include <cstring>
#include <stdio.h>


struct nodo_texto {
    linea dato;
    texto sig;
};


texto CrearTextoNull(){
    texto t = new(nodo_texto);
    t->dato = NULL;
    t->sig = NULL;
    return t;
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
    texto aux = CrearTextoNull();

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


// devuelve el puntero a la última línea (e->ultima_linea).

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
    
texto InsertarPalabraAlInicio(texto t, Cadena palabra){
    // inserta el nodo nodo al inicio de la lista l (cambia la cabeza l).
    // hacerla de forma recursiva luego para repetir mas de 1 caso.
    if (t == NULL)
        t = CrearTextoNull();
    
        linea aux = CrearLinea();
        aux = GuardarPalabraEnLinea(aux, palabra);
        if (t->dato == NULL){
            t->dato = CrearLinea();
            t->dato = aux;
        }
        else {
            // aux->sig = t->dato;
            aux = LineaSiguienteIgualLinea(aux, t->dato); 
            t->dato = aux;
        }
        if (CantidadPalabras(t->dato) > MAX_CANT_PALABRAS_X_LINEA){
            linea iter2 = t->dato;
            linea ant2 = iter2;
            
            while (ObtenerSiguienteLinea(iter2) != NULL){
                ant2 = iter2;
                iter2 = ObtenerSiguienteLinea(iter2);
            }
            //if (LineaPalabra(iter2) == NULL)
            //return ERROR;
            
            Cadena copia = new char[strlen(LineaPalabra(iter2)) + 1];
            strcpy(copia, LineaPalabra(iter2));
            
            linea pal = CrearLinea();
            pal = GuardarPalabraEnLinea(pal, copia);
            
            // strcpy(LineaPalabra(iter2), LineaPalabra(pal));
            ant2 = CambiarSig(ant2);
            delete (iter2);
            t->sig = InsertarPalabraAlInicio(t->sig, LineaPalabra(pal));
        }
    return t;
}
texto insertar_Palabra_En_Texto(texto t, linea nueva_linea, Posicion posicionLinea, Posicion posicionPalabra){
    texto iter = t;

    while (iter != NULL && posicionLinea > 1) {
        iter = iter->sig;
        posicionLinea--;
    }
    if (iter->dato == NULL && posicionLinea == 1){
        iter->dato = CrearLinea();
        iter->dato = GuardarPalabraEnLinea(iter->dato, LineaPalabra(nueva_linea));
    } else
        iter->dato = Insertar_Palabra_En_Linea(iter->dato, nueva_linea, posicionPalabra);

    if (CantidadPalabras(iter->dato) > 3) {
		linea iter2 = iter->dato;
		linea ant2 = iter2;

		while (ObtenerSiguienteLinea(iter2) != NULL){
			ant2 = iter2;
			iter2 = ObtenerSiguienteLinea(iter2);
		}
        
        Cadena copia = new char[strlen(LineaPalabra(iter2)) + 1];
        strcpy(copia, LineaPalabra(iter2));
            
        linea pal = CrearLinea();
        pal = GuardarPalabraEnLinea(pal, copia);
            
        ant2 = CambiarSig(ant2);
        delete (iter2);
        iter->sig = InsertarPalabraAlInicio(iter->sig, LineaPalabra(pal));
	}	
    return t;
}


texto insertarLineaAlInicio(texto t, Cadena palabra){
    texto aux = CrearTexto();
    aux->dato = CrearLinea();
    aux->dato = GuardarPalabraEnLinea(aux->dato, palabra);

    if (t == NULL)
        return aux;

    aux->sig = t;
    return aux;
}


texto ObtenerPosicionLinea(texto t, Posicion posicionLinea, Posicion posicionPalabra){
    texto iter = t;
    if (t != NULL) {
        if (t->dato != NULL ) {
            while (iter != NULL && posicionLinea > 1) {
                iter = iter->sig;
                posicionLinea--;
            }
            if (posicionLinea == 1) {                
                iter->dato = ObtenerPosicionPalabra(iter->dato, posicionPalabra);
                return t;
            }
        }else {
            t->sig = ObtenerPosicionLinea(t->sig, posicionLinea - 1, posicionPalabra);
            return t;
        }

    }
}
texto EliminarTodaLinea(texto t){
    if (t == NULL) {
        return NULL;
    }
    t->sig = EliminarTodaLinea(t->sig);
    t->dato = EliminarTodaPalabra(t->dato);
    delete t;
    return NULL;
}

texto ObtenerPosicionLinea2(texto t, Posicion posicionLinea) {

    if (t == NULL || posicionLinea < 1) {
        return t;
    }

    texto iter = t;
    texto ant = NULL;
    if (t != NULL) {
        while (iter != NULL && posicionLinea > 1) {
            ant = iter;
            iter = iter->sig;
            posicionLinea--;
        }
        if (iter == NULL)
            return t;
         if (posicionLinea == 1){
            
            if (iter == t){
                // Si iter es NULL, la posición no existía; devolvemos t sin cambios
                t = iter->sig;
            } 
            if (ant == NULL)
                t = iter->sig; // Era la primera línea
            else
                ant->sig = iter->sig; // Era una línea del medio o del final
            // Liberamos las palabras y luego el nodo de la línea
            iter->dato = EliminarTodaPalabra(iter->dato);
            delete iter;
            return t;
        }
    }
}


texto EliminarOcurrenciasEnLineaTexto(texto t, Posicion posicionLinea, Cadena palabraABorrar){
    
    texto iter = t;
    if (t == NULL)
            return NULL;
        else {
            while (iter != NULL && posicionLinea > 1){
                iter = iter->sig;
                posicionLinea--;
            }
            if (iter != NULL && posicionLinea == 1 && iter->dato != NULL){
                iter->dato = EliminarOcurrenciasEnLinea(iter->dato, palabraABorrar);
            }
            return t;
        }
}


texto EliminarOcurrenciasPalabraEnTexto(texto t, Cadena palabraABorrar){

    texto iter = t;
    if (t == NULL)
        return NULL;
    else {
        while (iter != NULL){
            iter->dato = EliminarOcurrenciasEnTexto(iter->dato, palabraABorrar);
            iter = iter->sig;
        }
        return t;
    }
}


linea extraerPrimeraPalabra(texto &t){

    if (t == NULL)
        return NULL;

    while (t != NULL && t->dato == NULL){
        texto aux = t;
        t = t->sig;
        delete aux;
    }
    if (t == NULL)
        return NULL;

    linea primeraLinea = t->dato;
    t->dato = LineaSiguiente(primeraLinea);
    LineaSiguienteIgualLinea(primeraLinea, NULL);

    return primeraLinea;
}

texto comprimirTexto(texto t){
    if (t == NULL)
        return NULL;

    else if (TextoDato(t) == NULL) {
        texto aux = t;
        t = t->sig;
        delete aux;
        return comprimirTexto(t);
    } else {
        int cant = CantidadPalabras(t->dato);
        linea ultima = t->dato;
        while (LineaSiguiente(ultima) != NULL)
            ultima = LineaSiguiente(ultima);

        while (cant < MAX_CANT_PALABRAS_X_LINEA && t->sig != NULL) {
            // incrusta 
            linea siguienteLinea = extraerPrimeraPalabra(t->sig);
            if (siguienteLinea != NULL) {
                // Mover palabras de la siguiente línea a la línea actual
                LineaSiguienteIgualLinea(ultima, siguienteLinea);
                ultima = siguienteLinea;
                cant++;
                // Actualizar la línea siguiente después de mover palabras
                
            }
        }
        t->dato = comprimirLinea(t->dato);
        t->sig = comprimirTexto(t->sig);
    }
    return t;
}


texto LimitarHistorial(texto historial){
    // Limitar el historial a MAX_CANT_ULTIMAS_PALABRAS palabras.
    int contador = 0;
    linea iter = historial->dato;
    linea ant = NULL;
    
    while (iter != NULL) {
        contador++;
        if (contador > MAX_CANT_ULTIMAS_PALABRAS) {
            // Eliminar el resto del historial.
            // l->sig == NULL
            CambiarSig(ant); // Desconectar el resto del historial.
            delete iter; // Liberar memoria del resto del historial.
        }
        ant = iter;
        iter = LineaSiguiente(iter);
    }
    
    return historial;
}

texto AgregarAlHistorial(texto historial, Cadena palabra) {    
    // Agregar una palabra al historial.
    
    if (historial == NULL) {
        historial = CrearTexto();
        historial->dato = GuardarPalabraEnLinea(historial->dato, palabra);
    } else {
        historial = InsertarPalabraAlInicio(historial, palabra);
    }
    
    // Limitar el historial a MAX_CANT_ULTIMAS_PALABRAS palabras.
    historial = LimitarHistorial(historial);
    
    return historial;
}