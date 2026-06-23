#include <stdio.h>


/*
Se debe imprimir en pantalla todos los divisores impares de N mayores o iguales a X.
Ejemplo: N = 36 y X = 3
Se imprime: 9 3

Nota: El orden es descendente (de mayor a menor).
*/
void suma_divisores_impares_desde (int n, int x){

    if (n >= x){
        suma_divisores_impares_desde(n, x + 1);
        if (n % x == 0 && x % 2 != 0)
            printf(" %d ", x);

    }

}

int main(){

    suma_divisores_impares_desde(10, 5);
}