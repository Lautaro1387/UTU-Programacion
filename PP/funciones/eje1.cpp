#include <stdio.h>




int sumar(int a, int b) {
    return (a + b);
}

int main (){
    
    int a, b;
    printf ("Ingrese 2 numeros para sumar: \n");
    scanf("%d %d", &a, &b);

    printf("Suma es: %d", sumar(a, b));

}