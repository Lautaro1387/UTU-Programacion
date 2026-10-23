#ifndef TEXTO_H
#define TEXTO_H
#include "../definiciones.h"

typedef struct nodo_texto * texto; // conjunto de linea
typedef struct nodo_linea * linea; // conjunto de linea
typedef struct nodo_editor * editor; // conjunto de texto



texto CrearTexto();
// Crea un nuevo nodo de texto vacio

linea ObtenerLinea(texto t);
// devuelve la cabeza de la lista de palabras en la línea t (t->dato).

texto InsertarLineaTextoVacio(texto t);
// Se usa: TipoRetorno InsertarLinea(editor & e);
// inserta la linea l al final de la lista t (cambia la cabeza t) y devuelve el puntero a la nueva línea creada.

texto InsertarLineaTexto(linea l, linea nueva_palabra, texto iter);
// Se usa en: TipoRetorno InsertarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);
// inserta la linea l en el medio de la lista t, manteniendo el orden de las lineas.

texto InsertarUltimaLineaTexto(texto t, linea l);
// Se usa en: TipoRetorno InsertarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);
// inserta la linea l al final de la lista t (cambia la cabeza t) y devuelve el puntero a la nueva línea creada.

texto TextoUltimaLinea(editor e);
// Se usa en: TipoRetorno InsertarLineaEnPosicion(editor & e, Posicion posicionLinea){
// devuelve el puntero a la última línea (e->ultima_linea).

texto insertarLineaAlInicio(texto t, Cadena palabra);

texto TextoPrimera(editor e);
// devuelve el puntero a la primera línea de editor e (i.e. e->primer_linea).

texto TextoUltima(texto t);
// devuelve el puntero a la última línea (e->ultima_linea).

texto InsertarLineaEnPosicionTexto(texto iter, texto ant, texto aux);

linea TextoDato(texto t);

texto TextoSiguiente(texto t);
// devuelve la siguiente línea después de t (t->sig).

linea TextoContenido(texto t);
// devuelve la cabeza de la lista de palabras en la línea t (t->dato).

linea InsertarPalabraAlInicio(texto t, Cadena palabra);
// inserta el nodo nodo al inicio de la lista l (cambia la cabeza l).


/*

unsigned int CantidadLineas(texto t);
void ImprimirTextoCompleto(texto t);
void TextoCrearLinea(editor &e, texto despues);
// inserta una nueva línea (nodo vacía) en editor, inmediatamente después de la línea apuntada por despues. Si despues==NULL, agrega la línea al inicio (y actualiza primer_linea). Actualiza ultima_linea si es la última.
texto CrearTexto();//Lista
    TipoRetorno InsertarLineaFinal(texto t);                           // Debe ser O(1)
    TipoRetorno InsertarLineaAlPrincipio(texto t);                        // Debe ser O(1)
    TipoRetorno BorrarLineaEnPosicion(texto t, Posicion pos);
    TipoRetorno BorrarTodoTexto(texto t);
    void DestruirTexto(texto &t);
*/
#endif
