#include <stdio.h>


const int TAM = 5;

float promedio(float arreglo[], int TAM) {

    int i; 
    float suma = 0.0;

    for (i = 0; i<TAM; i++)
        suma = suma + arreglo[i];

    return (suma/TAM);
}

int main (){
    
    float arregloReales[TAM] = {2.4, 3.5, 4.0, 7.7, 5.0};

    printf("Promedio %.2f\n ", promedio(arregloReales, TAM));

    
}