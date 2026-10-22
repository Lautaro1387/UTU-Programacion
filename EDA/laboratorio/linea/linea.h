#ifndef LINEA_H
#define LINEA_H
#include "../definiciones.h"
#include "../texto/texto.h"

typedef struct nodo_linea * linea; // conjunto de palabra
typedef struct nodo_texto * texto; // conjunto de palabra

// funciones auxiliares

linea CrearLinea();
    // Crea una nueva linea

linea LineaNueva(Cadena palabra);
// crea e inicializa un nodo de palabra con la cadena dada y sig=null.

linea LineaSiguiente(linea l);
// devuelve l->sig.

Cadena LineaPalabra(linea l);
// devuelve l->palabra.

linea TextoDato(texto t);

linea ObtenerLinea(texto t);
// devuelve la cabeza de la lista de palabras en la línea t (t->dato).

linea InsertarPalabraAlInicio(texto t, Cadena palabra);
// inserta el nodo nodo al inicio de la lista l (cambia la cabeza l).

linea InsertarPalabraAlInicioLinea(linea l, Cadena palabra);

Posicion CantidadPalabras(linea l);
// cuenta y retorna el número de nodos en la lista l.

linea LineaExtraerUltimo(linea &l);
// quita el último nodo de la lista l (ajustando el penúltimo a sig=null)
// y lo devuelve. Retorna NULL si la lista queda vacía.

linea InsertarUltimaLinea(linea l, linea nueva_palabra);
// Se usa en: TipoRetorno InsertarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);
// inserta la linea l al final de la lista t (cambia la cabeza t)

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