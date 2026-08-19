#include <stdio.h>


// ARREGLAR EJERCICIO

// Leer una palabra de hasta 20 caracteres, y luego imprimirla al derecho y al revés en mayúsculas

const int TAM = 20;


int main(){

    char palabra[TAM];
    int i;

    printf("Ingrese una palabra de hasta 20 caracteres:");
    

    // si ingresa exactamente 20 caracteres o mas
    for(i=0; i<TAM; i++){

        scanf("%c", &palabra[i]);

    }

    // si ingresa menos caracteres de 20 seria con DO WHILE, pero para arrays, es mejor usar for, porque el do while es mas para string 
    
        for (i=0; i<TAM; i++){
            if (palabra[i] >= 'a' && palabra[i] <= 'z'){ 
                printf("La palabra 1: %c", palabra[i]-32);
            }
            else 
                printf("La palabra 2: %c", palabra[i]);
            
    for (i=TAM-1; i>=0; i--){
         if (palabra[i] >= 'a' && palabra[i] <= 'z'){ 
                printf("La palabra 3: %c", palabra[i]-32);
            }
            else 
                printf("La palabra 4: %c", palabra[i]);
    }
    }    
}