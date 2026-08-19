#include <stdio.h>

const int COL = 3;
const int FIL = 3;

int main(){

    int matriz[FIL][COL];
    int i, j;
    float promedio = 0.0;

    // carga - recorrida completa
    for (i = 0; i<FIL; i++)
    {
        for (j = 0; j<COL; j++){
            printf("Ingrese valor de fila %d y columna %d: ", i, j);
            scanf("%d", &matriz[i][j]);

            promedio = promedio + matriz[i][j]; // parte c
        }
    }
    // imprimir valores de la matriz - recorrida completa
    for (i = 0; i<FIL; i++)
    {
        for (j = 0; j<COL; j++){
            printf("[%d]", matriz[i][j]);       
        }
        printf("\n");
        
        // printf("El menor valor de la matriz es %d", matriz[i][j]);
    }
    printf("El promedio es %d \n", promedio/(FIL*COL)); // parte c
}