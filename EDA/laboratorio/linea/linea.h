#ifndef LINEA_H
#define LINEA_H
#include "../definiciones.h"

typedef struct nodo_linea * linea; // conjunto de palabra
typedef struct nodo_texto * texto; // conjunto de palabra



// funciones auxiliares

linea CrearLinea();
    // Crea una nueva linea

linea LineaNueva(Cadena palabra);
// crea e inicializa un nodo de palabra con la cadena dada y sig=null.

linea InsertarPalabraAlInicio(texto t, Cadena palabra);
// inserta el nodo nodo al inicio de la lista l (cambia la cabeza l).

linea LineaSiguiente(linea l);
// devuelve l->sig.
Cadena LineaPalabra(linea l);
// devuelve l->palabra.

Posicion CantidadPalabras(linea l);
// cuenta y retorna el número de nodos en la lista l.

linea LineaExtraerUltimo(linea &l);
// quita el último nodo de la lista l (ajustando el penúltimo a sig=null)
// y lo devuelve. Retorna NULL si la lista queda vacía.


Cadena ObtenerPalabra(linea l, Posicion pos);

// InsertarPalabra(linea &l, Posicion pos, Cadena palabra)

// ExtraerUltimaPalabra(linea l);

// No dar bola
void LineaInsertarDespues(linea ant, linea nodo);
// inserta nodo justo después del nodo ant en la lista (este es el caso de inserción intermedia o final).











linea ObtenerSiguienteLinea(linea l);
// linea ObtenerLinea(texto t, Posicion pos);
linea InsertarPalabraEnLinea(texto t,Posicion pos, Cadena palabra);
void EstablecerSiguienteLinea(linea l, linea siguiente);
TipoRetorno InsertarPalabraEnLinea(linea l, Posicion pos, Cadena palabra);
TipoRetorno BorrarPalabraEnLinea(linea l, Posicion pos);
TipoRetorno BorrarOcurrenciasEnLinea(linea l, Cadena palabra);
void ImprimirLineaContenido(linea l);
void DestruirLinea(linea& l);


#endif