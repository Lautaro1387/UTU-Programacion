#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "../definiciones.h"

typedef struct nodo_diccionario * Diccionario;

Diccionario CrearDiccionario();
TipoRetorno BorrarPalabraDiccionario(Diccionario& d, Cadena palabraABorrar);//
bool IngresarPalabraDiccionarioD(Diccionario& d, Cadena palabraAIngresar);//
bool PerteneceDiccionario(Diccionario d, Cadena palabra);
void ImprimirDiccionarioD(Diccionario d);//
void DestruirDiccionario(Diccionario& d);

#endif