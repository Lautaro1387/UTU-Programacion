// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// editor.c
// Modulo de implementacion de editor.

#include <string.h>
#include <iostream>
#include "editor.h"
#include "../definiciones.h"
// Incluir los modulos realizados.
#include "../linea/linea.h"
#include "../texto/texto.h"
#include "../diccionario/diccionario.h"

using namespace std;

struct nodo_editor
{
	/* acá deben figurar los campos/estructuras que usted considere necesarios
	para implementar el editor. Ej: texto, diccionario, etc. Recordar que cada módulo
	debe implementarse independientemente e incluirse */
	// editor debe de tener una estructura asociada a lineas
	Diccionario dic;
	texto primer_linea;
	texto ultima_linea;
};

editor CrearEditor()
{
	// Crea la estructura editor.
	editor e = new (nodo_editor);
	/* crear el resto de las estructuras que se incluyan en el editor
	usando las funciones correspondientes de cada modulo */
	e->primer_linea = NULL;
	e->ultima_linea = NULL;
	return e;
}

TipoRetorno InsertarLinea(editor &e)
{
	// Inserta una nueva línea vacía al final del texto.
	// Este requerimiento debe ser resuelto en O(1) peor caso.
	// Ver más detalles en la letra del obligatorio.

	if (e->primer_linea == NULL) { // documento vacio
		e->primer_linea = InsertarLineaTextoVacio(e->primer_linea);
		e->ultima_linea = e->primer_linea;
	}
	else
		e->ultima_linea = InsertarLineaTextoVacio(e->ultima_linea);
	return OK;
}

TipoRetorno InsertarLineaEnPosicion(editor &e, Posicion posicionLinea)
{
	// Inserta una nueva línea vacía en la posición indicada.
	// Ver más detalles en la letra del obligatorio.

	/*
	texto iter = e->primer_linea;
	texto ant = iter;
	while (iter != NULL && posicionLinea > 1){
		ant = iter;
		iter = TextoSiguiente(iter);
		posicionLinea--;
		}
		if (posicionLinea == 1){
			e->primer_linea = InsertarLineaEnPosicionTexto(e->primer_linea, aux);
			*/
	if (posicionLinea < 1)
		return ERROR;
	texto aux = CrearTexto();
	if (e->primer_linea == NULL) {
		e->primer_linea = aux;
		return OK;
	}
	e->primer_linea = InsertarLineaEnPosicionTexto(e->primer_linea, aux, posicionLinea);
	e->ultima_linea = TextoUltima(e->primer_linea);
	return OK;
}

TipoRetorno BorrarLinea(editor &e, Posicion posicionLinea) {
	texto aux = e->primer_linea;
	if (posicionLinea < 1 || e->primer_linea == NULL || TextoDato(e->primer_linea) == NULL)
		return ERROR;
	e->primer_linea = ObtenerPosicionLinea2(e->primer_linea, posicionLinea);
	return OK;
}

TipoRetorno BorrarTodo(editor &e) {
	// Borra todas las líneas del texto.
	// Ver más detalles en la letra del obligatorio.
	e->primer_linea = EliminarTodaLinea(e->primer_linea);
	return OK;
}

TipoRetorno BorrarOcurrenciasPalabraEnTexto(editor &e, Cadena palabraABorrar) {
	// Borra todas las ocurrencias de una palabra en el texto.
	// Ver más detalles en la letra del obligatorio.
	e->primer_linea = EliminarOcurrenciasPalabraEnTexto(e->primer_linea, palabraABorrar);
	return OK;
}

TipoRetorno ImprimirTexto(editor &e) {
	// Imprime el texto por pantalla.
	// Ver más detalles en la letra del obligatorio.
	if (e->primer_linea == NULL) {
		printf("Texto vacio");
		return OK;
	}
	texto iter = e->primer_linea;
	int i = 0;
	linea l;
	while (iter != NULL) {
		l = ObtenerLinea(iter);
		i++;
		printf("%d: ", i);
		while (l != NULL) {
			printf("%s ", LineaPalabra(l));
			l = ObtenerSiguienteLinea(l);
		}
		printf("\n");
		iter = TextoSiguiente(iter);
	}
	return OK;
}

TipoRetorno ComprimirTexto(editor &e)
{
	// Comprime las palabras del texto. Para implementar esta operación no debe generarse un nuevo documento.
	// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}


TipoRetorno InsertarPalabra(editor &e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar) {
	// Inserta una palabra en una línea.
	// Ver más detalles en la letra del obligatorio.

	if (posicionLinea < 1 || posicionPalabra < 1 || e->primer_linea == NULL)
		return ERROR;

		linea nueva_linea = CrearLinea();
		nueva_linea = GuardarPalabraEnLinea(nueva_linea, palabraAIngresar);
		e->primer_linea = insertar_Palabra_En_Texto(e->primer_linea, nueva_linea, posicionLinea, posicionPalabra);
		if (CantidadPalabras(TextoDato(e->primer_linea)) > 3) {
			linea iter2 = TextoDato(e->primer_linea);
			linea ant2 = iter2;

			while (ObtenerSiguienteLinea(iter2) != NULL){
				ant2 = iter2;
				iter2 = ObtenerSiguienteLinea(iter2);
			}
			if (LineaPalabra(iter2) == NULL)
				return ERROR;

			Cadena copia = new char[strlen(LineaPalabra(iter2)) + 1];
			strcpy(copia, LineaPalabra(iter2));
			
			linea pal = CrearLinea();
			pal = GuardarPalabraEnLinea(pal, copia);

			// strcpy(LineaPalabra(iter2), LineaPalabra(pal));
			ant2 = CambiarSig(ant2);
			delete (iter2);
			InsertarPalabraAlInicio(TextoSiguiente(e->primer_linea), LineaPalabra(pal));
		}	
	return OK;
}

TipoRetorno BorrarPalabra(editor &e, Posicion posicionLinea, Posicion posicionPalabra) {
	// Borra la palabra en la posición indicada.
	// Ver más detalles en la letra del obligatorio.
	// texto aux = e->primer_linea;
	 
	if (posicionLinea < 1 || posicionPalabra < 1 || e->primer_linea == NULL || TextoDato(e->primer_linea) == NULL)
		return ERROR;
	e->primer_linea = ObtenerPosicionLinea(e->primer_linea, posicionLinea, posicionPalabra);
	return OK;
}

TipoRetorno BorrarOcurrenciasPalabraEnLinea(editor &e, Posicion posicionLinea, Cadena palabraABorrar)
{
	// Borra todas las ocurrencias de una palabra en la línea indicada.
	// Ver más detalles en la letra del obligatorio.
	if (posicionLinea < 1) 
		return ERROR;
	e->primer_linea = EliminarOcurrenciasEnLineaTexto(e->primer_linea, posicionLinea, palabraABorrar);
	return OK;
}

TipoRetorno ImprimirLinea(editor &e, Posicion posicionLinea) {
	// Imprime la línea por pantalla.
	// Ver más detalles en la letra del obligatorio.

	texto iter = e->primer_linea;
	while (iter != NULL && posicionLinea > 1){
		iter = TextoSiguiente(iter);
		posicionLinea--;
	}
	
	if (posicionLinea == 1){
		ImprimirT(TextoDato(iter));
		return OK;
	} else
		return ERROR;
}

TipoRetorno IngresarPalabraDiccionario(editor &e, Cadena palabraAIngresar)
{
	// Agrega una palabra al diccionario.
	// Esta operación debe realizarse en a lo sumo O(log n) promedio.
	// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno BorrarPalabraDiccionario(editor &e, Cadena palabraABorrar)
{
	// Borra una palabra del diccionario.
	// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirDiccionario(editor &e)
{
	// Muestra las palabras del diccionario alfabéticamente.
	// Esta operación debe realizarse en O(n) peor caso.
	// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirTextoIncorrecto(editor &e)
{
	// Muestra las palabras del texto que no se encuentran en el diccionario.
	// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirUltimasPalabras(editor &e)
{
	// Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS palabras ingresadas al texto.
	// Ver más detalles en la letra del obligatorio.
	return NO_IMPLEMENTADA;
}

TipoRetorno DestruirEditor(editor &e)
{
	// Destruye la estructura editor y libera la memoria asociada.
	return NO_IMPLEMENTADA;
}

/*
InsertarPalabra:


	texto iter = CrearTexto();
	texto nueva_linea = CrearTexto();
	InsertarPalabraAlInicio(nueva_linea, palabraAIngresar);

		while (iter != NULL && posicionLinea > 1){
			iter = TextoSiguiente(iter);
			posicionLinea--;
		}


	if (posicionLinea == 1){
		linea aux = TextoDato(iter);
		while (aux != NULL && posicionPalabra > 1){
			aux = ObtenerSiguienteLinea(aux);
			posicionPalabra--;
		}

		// Crear una funcion de ingresarLineaAlInicio de tipo linea
		linea nueva_palabra = InsertarPalabraAlInicioLinea(nueva_palabra, palabraAIngresar);
		if(TextoDato(iter) == NULL){
			iter = InsertarUltimaLineaTexto(iter, nueva_palabra);
			// iter->dato = nueva_palabra;
			// nueva_palabra->sig = NULL;
		}
		if(posicionPalabra == 1){
			if (ObtenerSiguienteLinea(aux) == NULL){
				// insertar la palabra al final de la linea
				aux = InsertarUltimaLinea(aux, nueva_palabra);
				// aux->sig = nueva_palabra;
				// nueva_palabra->sig = NULL;
			} else {
				// modificiar InsertarLineaTexto el primer parametro para que sea de tipo linea y no texto
				iter = InsertarLineaTexto(aux, nueva_palabra, iter);
				// nueva_palabra = InsertarLineaTexto(nueva_palabra, LineaSiguiente(aux));
				// aux->sig = nueva_palabra;
			}
			if (CantidadPalabras(TextoDato(iter)) > 3){
				linea iter2 = TextoDato(iter);
				linea pal = CrearLinea();
				while (ObtenerSiguienteLinea(iter2) != NULL)
				iter2 = ObtenerSiguienteLinea(iter2);
				strcpy(LineaPalabra(iter2), LineaPalabra(pal));
				delete(iter2);
				InsertarPalabraAlInicio(TextoSiguiente(iter), LineaPalabra(pal));
			}
		}
		return OK;
	}
	return ERROR;

*/
