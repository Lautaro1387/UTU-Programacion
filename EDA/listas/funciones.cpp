#include <stdio.h>
#include "cabezales.h"
// En parcial C++

// liberar memoria 
// C++ -> delete() (usaremos esta) - new 
// C -> free()- malloc 
// Definiciones completa y notas del profe + audio

/*
    para hacer referencia al dato l->dato
    para pasar al proximo l->sig
    para hacer referencia al proximo es l->sig->dato
    para pasar al otro otra vez l->sig->sig

    si haces l->dato y esta vacio, explota
*/

struct nodo_lista {

    int dato;
    lista sig;

};

lista crear(){
// Devuelve una lista vacia
    return NULL;
}

lista cons(lista l, int n){
    // pos: agergar n al comienzo de la lista
    lista aux = new(nodo_lista);
    aux->dato = n;
    aux->sig = l;
    return aux;
    /*
        si quiero invocarla es asi (en el main):
        lista lis;
        lis = crear();

        lis = cons(lis, 2);
        list = cons(lis, -3);
    */
}
lista lis;

// Procedimiento
// si quiero que siga siendo la misma lista, debo de actualizarlo todo el tiempo
// Le estamos pasando la dirección de L (por el &)
void consP(lista &l, int n){

    lista aux = new(nodo_lista);
    aux-> dato = n;
    aux->sig = l;
    l = aux; // Siempre se puede hacer si el pasaje es por referencia, si no lo es, se acaba el procedimiento y se acaba porque es local
    
    // Si se invoca es asi: consP(lis, 8);
}

// Primero de la lista
int head(lista l){
    return l->dato;
}

lista tail(lista l){
    return l->sig;
}

bool isEmpty(lista l){
    // POS: retorna ture si l es vacia, false en caso contrario
    return l == NULL;
}

/*
//forma interactivo
int contar(lista l){
    int cant = 0;
    while (l != NULL){
        cant++;
        l = l->sig; // no pierdo el valor de l, porque es una copia
    }
    return cant;
}
*/

// forma recursiva
int contar(lista l){
    // POS: retorna la cantidad de elementos de l
    if (isEmpty(l)){ // tambien es valido i == NULL
        return 0;
    } else {
        return (1+contar(tail(l)));    
    }
}

int sumar(lista l){
   // PRE: l no vacia
   // POS: retorna la suma de los elementos de l
    int sum = 0;
    while(l != NULL){
        sum += l->dato; // sum = sum + l-<dato
        l = l->sig;
    }
    return sum;
}
/*
// forma mas optima de sumar
int sumar(lista l){
    // PRE: l no vacia
    // POS: retorna la suma de los elementos de l
    int sum = 0;
    while (l != NULL){
        sum += l->dato;
        l = l->sig;
    }
    return sum += l->dato;
}

// forma recursiva para sumar
int sumar(lista l){
    // PRE: l no vacia
    // POS: retorna la suma de los elementos de l
    if (l->sig == NULL){
        return l->dato;
    } else {
        return l->dato = sumar(l->sig); // tail(l)
    }
}

// otra caso de forma recursiva
int sumar(lista l){
    if(isEmpty(tail(l))){
        return head(l);
    } else {
        return head(l) + sumar(tail(l));
    }
}
*/

bool pertenece(lista l, int x){
    // POS: retorna true si X esta en la lista, en caso contrario retorna false
    while (l != NULL && l->dato != x) // por circuito corto se puede hacer
        l = l->sig;
    return l != NULL;
}


lista eliminar(lista l, int x){
    // POS: retorna la lsita sin el eleemnto x y libera la memoria correspondiente al nodo
    // Tenes que ver el caso donde tiene uno solo (chequear luego)
    lista recorre = l, ant;

    while (recorre != NULL && recorre->dato != x){
        ant = recorre; // creo una copia y lo recorro con la copia
        recorre = recorre -> sig;
    }
    if (recorre == NULL){
        return l;
    } else if (recorre == l){
        l = l->sig;
        delete(recorre);
        return l;
    } else {
        ant->sig = recorre->sig;
        delete(recorre);
        return l;
    }

    // si quisiera invocarlo (en el main):
    // lis = eliminar(lis, 2)

}
/*
// forma iteractiva
lista destruir(lista l){
    // POS: Elimina todos los elementos de l y librerar memoria
    lista aux;
    while (l != NULL){
        aux = l;
        l = l->sig;
        delete(aux);
    }
    return l;
}

*/
// forma recursiva
lista destruir(lista l){
    // POS: Elimina todos los elementos de l y librerar memoria
    lista aux;
    if (isEmpty(l)){
        return NULL; 
    } else{
        aux = l;
        l = l->sig;
        delete(aux);
        return destruir(l);
    }
}

/*
// forma iteractiva con estructura interna (nodo_lista)
lista snoc(lista l, int n){
    // POS: Agrega n al final de la lista
    lista aux = new(nodo_lista);
    aux->dato = n;
    aux->sig = NULL;
    if(l == NULL){
        return aux;
    } else {
        lista recorre = l;
        while (recorre->sig != NULL)
        recorre = recorre->sig;
        recorre->sig = aux;
        return l;
    }
}

*/

// forma recursiva con estructura interna (nodo_lista)
lista snoc(lista l, int n){
    // POS: Agrega n al final de la lista
    // int n, es el resto
    if (isEmpty(l)){
        lista aux = new(nodo_lista);
        aux->dato = n;
        aux->sig = NULL;
        return aux;
    } else {
        l->sig = snoc(l->sig, n); // fundamental para recursividad
        return l;
    }

}

// snoc sin utilizar estructura interna de forma recursiva
/*
lista snoc(lista l, int n){ // si esto lo asigna a N, pierdo la lista original
if(isEmpty(l)){
    return cons(crear(), n);
} else {
    return cons(snoc(tail(l), n), head(l));
}

}
*/

// Procedimiento para imprimir
void imprimir(lista l){

    if (l == NULL){
        printf("<Lista vacia>");
    } else {
        printf("<<");
        while (l->sig != NULL){
            printf("%d->", l->dato);
            l = l->sig;
        }
        printf("%d>>\n", l->dato);
    }
}