#ifndef RACIONAL_H
#define RACIONAL_H
// Prototipos

// Siempre colocar pre y pos condiciones en los cabezales solamente

typedef struct nodo_lista * lista;
 
// Constructores

lista crear();
// pre: no tiene
// pos: retorna una lista vacia

lista cons(lista l, int n);

lista snoc(lista l, int n);


// Nos devuelve el primer elemento de la lista
int head(lista l);
// PRE: l no vacia
// POS: retorna el primer elemento de la lista


// Nos devuelve el resto de la lista
lista tail(lista l);
// PRE: l no vacia
// POS: retorna la lista nueva
// el primer elemento("resto" de la lista)

// Las que devuelven booleanos son predicados
// Predicado
bool isEmpty(lista l);

// Predicado
bool pertenece(lista l, int x);

// Observador al sumar
int contar(lista l);

int sumar(lista l);

lista eliminar(lista l, int x);

lista destruir(lista l);



#endif