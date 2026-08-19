#include <stdio.h>
#include "cabezales.h"

// Dado un arreglo de numeros entero,s retornar el mayor numero entero. Resolverlo en forma recursiva.

/*
racional crearRacional()
{
    racional aux = new(nodoRacional);
    return aux;
}
racional setNumerador(racional r, int n)
{
    r->num = n;
    return r;
}
racional setDenominador(racional r, int n)
{
    r->den = n;
    return r;
}
int getNumerador(racional r)
{
    return r->num;
}
int getDenominadordor(racional r)
{
    return r ->den;
}
racional suma(racional r1, racional r2)
{
    racional sum = crearRacional();
    sum ->num = r1->num * r2 ->den + r2 ->num * r1 -> den;
    sum ->den = r1 -> den * r2 ->den;
    return sum;
}
racional eliminarRacional(racional r)
{
    delete r;
    return NULL;
}
void imprimir(racional r)
{
    printf("%d%d", r->num, r->den);
}
*/

struct nodo_racional {
    int num;
    int den;
};

int crearArreglo(int arr[], int tam){

    int i;

    for (i = 0; i<tam; i++){
        scanf("%d", &arr[i]);
    }
    return arr[i];


}

// Funcion
int mayor(int arr[], int n){
    
    // Caso base
    if (n == 1){
        return arr[0];
    } else { 
        int MAX = mayor(arr, n-1);
        if (arr[n-1] > MAX) {
            return arr[n-1];
        } else {
            return MAX;
        }
      } 

}

// Procedimiento
void mayor(int arr[], int n, int &resul){
    // pre n > 0
    if (n == 1 ){
        resul = arr[0];
    } else {
        int MAX;
        mayor(arr, n-1, MAX);
        if (arr[n-1] > MAX){
            resul = arr[n-1];
        } else {
            resul = MAX;
        }
    }
}
