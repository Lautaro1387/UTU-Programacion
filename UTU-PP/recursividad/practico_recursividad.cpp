#include <stdio.h>



/*
a) Dado un natural n, determinar si es par o impar. Se pide definir esta operación
sin usar operadores de division, ni modulo.
*/

bool esPar(int numero){
    if(numero == 0)
        return true; // paso base
    if (numero == 1)
        return false; // paso base
    else    
        return esPar(numero - 2); // paso recursivo
}

/*
b) Dado un natural n, calcular la suma de todos los naturales pares que existen
entre 0 y n.
*/

int sumaPares(int n){
    
    if(n == 0)
        return 0;
    else
        if (n % 2 == 0)
            return (n + sumaPares(n - 2));
        else
            return sumaPares(n - 1);
}

// c) Dado un natural n, imprimir en pantalla una linea con n asteriscos.

void imprimirAsteriscos(int n){

    if (n > 0)
    {
        printf(" * ");
        imprimirAsteriscos(n-1); // paso recursivo
    }
}


/*
d) Dado un natural n, imprimir en pantalla los primeros n numeros naturales en
orden decreciente (n, n-1, n-2, …, 2, 1).
*/

void imprimirNumNaturales(int numm){

    if (numm > 0){ 
        printf("%d \n", numm);
        imprimirNumNaturales(numm - 1);
    }
}

/*
e) Dado un natural n, imprimir en pantalla los primero n numeros naturales en
orden creciente (1, 2, 3, …, n-1, n)
*/

void imprimirNumNaturalesCreciente(int numm){

    if (numm > 0){
        imprimirNumNaturales(numm - 1);
        printf("%d \n", numm);
    }
}

// f) Dados dos naturales n y m, (con n>0) calcular el valor de la potencia n^m
// precondicion n > 0
int Potencia(int n, int m){

    if (m == 0)
        return 1; // paso base
    else    
        return n*Potencia(n, m - 1); // paso recursivo
}
/*
n = 2, m = 3
2*potencia(2, 2) 
    --> 2*potencia(2, 1)
        --> 2*potencia(2, 0)
            --> return 1
*/

int main(){

    imprimirNumNaturales(5);
}