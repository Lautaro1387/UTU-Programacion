#include <stdio.h>
/*

a) Un procedimiento que reciba como parámetro un arreglo de enteros y lo liste por
pantalla.

*/ 

const int TAM = 5;

void lista_array(int arre[], int tam){

    int i;

    for(i=0;i<tam;i++)
        printf("%d", arre[i]);
}


int main(){

    int arre[TAM];
    int i;
    char c;
    for (i = 0; i<TAM; i++)
        scanf("%d", &arre[i]);
    printf("Arreglo de enteros: ");
    lista_array(arre, TAM);

}

// FALTA CHEQUEAR EL LIMITE
