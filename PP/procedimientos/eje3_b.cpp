#include <stdio.h>
/*

b) Un procedimiento que, dados dos enteros (m y n) dibuje en pantalla un rectángulo de
asteriscos formado por m filas y n columnas.

*/


void rectangulo(int m, int n){

    int i, j;

    for(i = 0; i<m; i++)
        for(j = 0; j<n; j++)
            printf(" * ");
        printf("\n");        

}


int main(){
    int m, n;

    scanf("%d, %d", &m, &n);

    rectangulo(m, n);




}




// CHEQUEAR RESULTADO FINAL LUEGO, YA QUE NO IMPRIME LOS ***