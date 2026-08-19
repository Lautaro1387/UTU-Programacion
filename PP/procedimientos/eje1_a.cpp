// Una función que reciba un carácter y devuelva TRUE si se trata de un blanco,
// tabulador o fin de línea o FALSE en caso contrario.

#include <stdio.h>
#include <stdbool.h>



bool check_caracter(char caracter){

    if (caracter == '\t' || caracter == '\n' || caracter == ' ')
        return true;
    else
        return false;
}

int main() {

    char caracter;

    printf ("Ingresa un caracter: ");
    scanf("%c", &caracter);

    if (check_caracter(caracter))
        printf("El caracter es taburador, salto de linea o espacio en blanco [%c]", caracter);
    else
        printf("El caracter es otro [%c]", caracter);
}

// FINALIZADO
