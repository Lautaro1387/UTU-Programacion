#include <stdio.h>
/*

Escribir un programa en C++ en el cual se defina una matriz de enteros, de F filas y C columnas (siendo F y C constantes simbólicas) y 
luego realice las siguientes acciones: 
a) Cargar una matriz del tipo definido con valores leídos desde teclado ✅
b) Mostrar por pantalla el contenido de la matriz. Cada fila debe listarse en una nueva línea ✅ 
c) Calcular el promedio de los valores almacenados en la matriz (sumar todo y dividirlo por la cantidad de elementos) ​❌​
d) Determinar el menor valor almacenado en la matriz y desplegarlo por pantalla. 
e) Dado un entero (leído desde teclado), determinar si pertenece o no a la matriz. 
f) Dado otro entero (leído desde teclado), contar su cantidad de ocurrencias en la matriz. 

*/

const int FIL = 3;
const int COL = 3;

int main (){

    int i, j;
    int matrices[FIL][COL];

    for (i = 0 ; i < FIL; i++) 
        for (j = 0; j < COL; j++){
            printf("Ingrese valor de la fila %d y la columna %d: ", i, j);
            scanf("%d", &matrices[i][j]);
        }

    
    for (i = 0 ; i < FIL; i++) {

        for (j = 0; j < COL; j++)
            printf("[%d]", matrices[i][j]);
        printf("\n");
    }

}