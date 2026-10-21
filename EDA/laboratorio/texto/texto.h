#ifndef TEXTO_H
#define TEXTO_H
#include "../definiciones.h"
#include "../editor/editor.h"
#include "../linea/linea.h"

typedef struct nodo_texto * texto; // conjunto de linea 


texto CrearTexto();


linea ObtenerLinea(texto t);

texto InsertarLinea(texto t, linea l);

unsigned int CantidadLineas(texto t);
void ImprimirTextoCompleto(texto t);


texto TextoPrimera(editor e);
// devuelve el puntero a la primera línea de editor e (i.e. e->primer_linea).

linea TextoDato(texto t);

texto TextoSiguiente(texto t);
// devuelve la siguiente línea después de t (t->sig).

linea TextoContenido(texto t);
// devuelve la cabeza de la lista de palabras en la línea t (t->dato).

void TextoCrearLinea(editor &e, texto despues);
// inserta una nueva línea (nodo vacía) en editor, inmediatamente después de la línea apuntada por despues. Si despues==NULL, agrega la línea al inicio (y actualiza primer_linea). Actualiza ultima_linea si es la última.

texto TextoUltima(editor e);
// devuelve el puntero a la última línea (e->ultima_linea).


Texto CrearTexto();//Lista
TipoRetorno InsertarLineaFinal(Texto t);                           // Debe ser O(1)
TipoRetorno InsertarLineaAlPrincipio(Texto t);                        // Debe ser O(1)
TipoRetorno InsertarLineaEnPosicionTexto(Texto t, Posicion pos);
TipoRetorno BorrarLineaEnPosicion(Texto t, Posicion pos);
TipoRetorno BorrarTodoTexto(Texto t);
TipoRetorno ImprimirTextoCompleto(Texto t);
void DestruirTexto(Texto& t);
#endif
