#ifndef TEXTO_H
#define TEXTO_H
#include "../definiciones.h"
#include "../linea/linea.h"


typedef struct nodo_texto * texto; // conjunto de linea

texto CrearTexto();
// Crea un nuevo nodo de texto vacio

texto CrearTextoNull();
// Crea un nuevo nodo de texto vacio con dato=NULL

linea ObtenerLinea(texto t);
// devuelve la cabeza de la lista de palabras en la línea t (t->dato).

texto InsertarLineaTextoVacio(texto t);
// Se usa: TipoRetorno InsertarLinea(editor & e);
// inserta la linea l al final de la lista t (cambia la cabeza t) y devuelve el puntero a la nueva línea creada.

texto InsertarUltimaLineaTexto(texto t, linea l);
// Se usa en: TipoRetorno InsertarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);
// inserta la linea l al final de la lista t (cambia la cabeza t) y devuelve el puntero a la nueva línea creada.

texto insertarLineaAlInicio(texto t, Cadena palabra);
// Se usa en: TipoRetorno InsertarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);
// inserta la linea l al inicio de la lista t (cambia la cabeza t)

texto TextoUltima(texto t);
// devuelve el puntero a la última línea (e->ultima_linea).

texto InsertarLineaEnPosicionTexto(texto e, texto aux, Posicion pos);
// Se usa en: TipoRetorno InsertarLineaEnPosicion(editor & e, Posicion posicionLinea);
// inserta la linea aux en la posición pos de la lista e (cambia la cabeza

linea TextoDato(texto t);
// devuelve la cabeza de la lista de palabras en la línea t (t->dato).

texto TextoSiguiente(texto t);
// devuelve la siguiente línea después de t (t->sig).

texto InsertarPalabraAlInicio(texto t, Cadena palabra);
// inserta el nodo nodo al inicio de la lista l (cambia la cabeza l).

texto insertar_Palabra_En_Texto(texto t, linea nueva_linea, Posicion posicionLinea, Posicion posicionPalabra);
// inserta la palabra en la línea t en la posición indicada.

texto ObtenerPosicionLinea(texto t, Posicion posicionLinea, Posicion posicionPalabra);
// devuelve el puntero a la línea en la posición indicada y elimina la palabra en la posición indicada.

texto ObtenerPosicionLinea2(texto t, Posicion posicionLinea);
// devuelve el puntero a la línea en la posición indicada y elimina toda la línea.

texto EliminarOcurrenciasEnLineaTexto(texto t, Posicion posicionLinea, Cadena palabraABorrar);
// elimina todas las ocurrencias de palabraABorrar en la línea indicada.

texto EliminarOcurrenciasPalabraEnTexto(texto t, Cadena palabraABorrar);
// elimina todas las ocurrencias de palabraABorrar en el texto.

texto EliminarTodaLinea(texto t);
// elimina todas las líneas del texto y libera la memoria asociada.

texto comprimirTexto(texto t);
// comprime el texto t eliminando los nodos que tengan dato=NULL. Retorna la cabeza de la lista resultante.

linea extraerPrimeraPalabra(texto &t);
// extrae la primera palabra de la línea t y la devuelve. Si la línea queda vacía, se elimina del texto.

texto AgregarAlHistorial(texto historial, Cadena palabra);
// agrega una palabra al historial y limita el historial a MAX_CANT_ULTIMAS_PALABRAS palabras.

texto LimitarHistorial(texto historial);
// limita el historial a MAX_CANT_ULTIMAS_PALABRAS palabras.

#endif
