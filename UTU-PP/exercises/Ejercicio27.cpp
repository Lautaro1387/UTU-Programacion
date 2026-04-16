#include <stdio.h>

// leer una palabra de 5 caratacteres y luego imprimirla al reves

const int TAM = 5;

int main() {
    char palabra[TAM];
    int i;

    printf("Ingrese una palabra de 5 caracteres: ");
    
    for (i=0; i<=TAM; i++){
        scanf("%c", &palabra[i]);
    }

    printf("La palabra de 5 caracteres es: ");
    for (i=TAM-1; i>=0; i--){

        printf("%c", palabra[i]);
    }
    printf("\n");


}