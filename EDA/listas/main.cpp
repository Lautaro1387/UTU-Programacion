#include <stdio.h>
#include "cabezales.h"

int main()
{
    lista lis;

    lis = crear();
    // lis = cons(lis, 4);
    lis = snoc(lis, 4);

    printf("%d", lis);
}