#ifndef LINEA_H
#define LINEA_H
#include "../definiciones.h"


typedef struct nodo_linea * linea; // conjunto de palabra

// funciones auxiliares

linea CrearLinea();
// Crea una nueva linea
linea LineaNueva(Cadena palabra);
// crea e inicializa un nodo de palabra con la cadena dada y sig=null.
linea ObtenerSiguienteLinea(linea l);
// devuelve l->sig.

Cadena LineaPalabra(linea l);
// devuelve l->palabra.

// void InsertarPalabraEnLinea(linea l, Cadena palabra);
// inserta la palabra en la linea l.

linea GuardarPalabraEnLinea(linea l, Cadena palabra);
// inserta la palabra en la linea l.

linea LineaSiguiente(linea l);

linea LineaIgualLinea(linea l, linea nueva_linea);
// establece el puntero sig de l a sig.

linea LineaSiguienteIgualLinea(linea l, linea nueva_linea);
// establece el puntero sig de l a nueva_linea.

linea Insertar_Palabra_En_Linea(linea l, linea nueva_linea, Posicion posicionPalabra);

linea InsertarPalabraAlInicioLinea(linea l, Cadena palabra);

Posicion CantidadPalabras(linea l);
// cuenta y retorna el número de nodos en la lista l.

linea CambiarSig(linea l);

linea LineaExtraerUltimo(linea &l);
// quita el último nodo de la lista l (ajustando el penúltimo a sig=null)
// y lo devuelve. Retorna NULL si la lista queda vacía.

linea InsertarUltimaLinea(linea l, linea nueva_palabra);
// Se usa en: TipoRetorno InsertarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);
// inserta la linea l al final de la lista t (cambia la cabeza t)

Cadena ObtenerPalabra(linea l, Posicion pos);
// InsertarPalabra(linea &l, Posicion pos, Cadena palabra)

linea ObtenerPosicionPalabra(linea l, Posicion posicionPalabra);

linea EliminarTodaPalabra(linea l);

linea EliminarOcurrenciasEnLinea(linea l, Cadena palabraABorrar);

void ImprimirT(linea l);
// ExtraerUltimaPalabra(linea l);

// No dar bola
void LineaInsertarDespues(linea ant, linea nodo);
// inserta nodo justo después del nodo ant en la lista (este es el caso de inserción intermedia o final).

linea ObtenerSiguienteLinea(linea l);
// linea ObtenerLinea(texto t, Posicion pos);
// linea InsertarPalabraEnLinea(texto t,Posicion pos, Cadena palabra);
// TipoRetorno InsertarPalabraEnLinea(linea l, Posicion pos, Cadena palabra);
// TipoRetorno BorrarPalabraEnLinea(linea l, Posicion pos);
// TipoRetorno BorrarOcurrenciasEnLinea(linea l, Cadena palabra);
// void ImprimirLineaContenido(linea l);
// void DestruirLinea(linea& l);


#endif