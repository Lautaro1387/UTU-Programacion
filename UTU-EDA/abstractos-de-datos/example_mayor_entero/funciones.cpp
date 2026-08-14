#include <stdio.h>
#include "cabezales.h"


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

int mayor(int arr[], int n){
    
    // Caso base
    int i;

    if (arr[i] > arr[i-1]) {
        
    }

    // Paso inductivo
}
