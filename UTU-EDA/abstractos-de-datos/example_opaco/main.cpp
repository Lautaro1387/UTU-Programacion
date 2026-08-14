#include <stdio.h>
#include "cabezales.h"

int main()
{
    racional rac1, rac2, res;
    rac1 = crearRacional();
    rac2 = crearRacional();
    rac1 = setNumerador(rac1,2);
    rac1 = setDenominador(rac1,3);

    rac2 = setNumerador(rac2,4);
    rac2 = setDenominador(rac2,5);

    res = suma(rac1, rac2);
    /*
    imprimir(rac1);
    printf(" + ");
    imprimir(rac2);
    printf(" = ");
    imprimir(res);
    printf("\n");
*/
    // imprimir(suma(rac1, rac2));
    printf("%d/%d", getNumerador(rac1), getDenominador(rac1));
    return 0;
}