#ifndef TEXTO_H
#define TEXTO_H
#include "../definiciones.h"

typedef struct nodo_texto * texto; // conjunto de linea
typedef struct nodo_linea * linea; // conjunto de linea


texto CrearTexto();

linea ObtenerLinea(texto t);

texto InsertarLinea(texto t, linea l);

texto InsertarLineaTexto(texto t, linea l);

texto TextoUltimaLinea(editor e);

texto TextoPrimera(editor e);
// devuelve el puntero a la primera línea de editor e (i.e. e->primer_linea).

texto TextoUltima(editor e);
// devuelve el puntero a la última línea (e->ultima_linea).

texto InsertarLineaEnPosicionTexto(texto iter, texto ant, texto aux);


unsigned int CantidadLineas(texto t);
void ImprimirTextoCompleto(texto t);


linea TextoDato(texto t);

texto TextoSiguiente(texto t);
// devuelve la siguiente línea después de t (t->sig).

linea TextoContenido(texto t);
// devuelve la cabeza de la lista de palabras en la línea t (t->dato).

void TextoCrearLinea(editor &e, texto despues);
// inserta una nueva línea (nodo vacía) en editor, inmediatamente después de la línea apuntada por despues. Si despues==NULL, agrega la línea al inicio (y actualiza primer_linea). Actualiza ultima_linea si es la última.


texto CrearTexto();//Lista
TipoRetorno InsertarLineaFinal(texto t);                           // Debe ser O(1)
TipoRetorno InsertarLineaAlPrincipio(texto t);                        // Debe ser O(1)
TipoRetorno BorrarLineaEnPosicion(texto t, Posicion pos);
TipoRetorno BorrarTodoTexto(texto t);
void DestruirTexto(texto &t);
#endif
