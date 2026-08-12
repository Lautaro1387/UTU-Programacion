#ifndef RACIONAL_H
#define RACIONAL_H

typedef struct
{
    int num;
    int den;
} racional;

racional setNumerador(racional r, int n);
racional setDenominador(racional r, int d);

int getNumerador(racional r);
int getDenominador(racional r);

racional suma(racional r1, racional r2);
racional resta(racional r1, racional r2);
racional mult(racional r1, racional r2);
racional div(racional r1, racional r2);

void imprimir(racional r);

#endif