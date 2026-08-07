#include "cabezales.h"
#include <stdio.h> // PREGUNTAR


racional setNumerador(racional r, int n)
{
    r.num = n;
    return r;
}

racional setDenominador(racional r, int d)
{
    r.den = d;
    return r;
}

int getNumerador(racional r)
{
    return r.num;
}

int getDenominador(racional r)
{
    return r.den;
}

racional suma(racional r1, racional r2)
{
    racional aux;

    aux.num = r1.num * r2.den + r1.den * r2.num;
    aux.den = r1.den * r2.den;

    return aux;
}
/*
racional resta(racional r1, racional r2)
{
    
}

racional mult(racional r1, racional r2)
{
    
}
*/

racional div(racional r1, racional r2)
{
    racional aux;

    aux.num = r1.num * r2.den;
    aux.den = r1.den * r2.num;

    return aux;
}

void imprimir(racional r)
{
    printf("%d/%d", r.num, r.den);
}

// fin del racional.cpp