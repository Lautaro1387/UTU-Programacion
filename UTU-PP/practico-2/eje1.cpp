#include <stdio.h>

const int TAM = 5;

int main() {

int numero[TAM];
int i;
int promedio;

// a) Cargar un arreglo del tipo definido con valores leídos desde teclado.

for (i = 0; i < TAM; i++){
    printf("Ingrese un valor ");
    scanf("%d", &numero[i]);
}

// b) Desplegar por pantalla el contenido del arreglo
for (i = 0; i < TAM; i++){
    printf(" %d", numero[i]);
}
printf("\n");

// c) Calcular el promedio de los valores almacenados en el arreglo.
for (i = 0; i < TAM; i++){



}

}

// d) Leer un valor entero desde teclado y determinar si pertenece o no al arreglo.
// e) Encontrar el menor valor y el mayor valor almacenados en el arreglo, junto con las
// posiciones correspondientes.
// f) Leer un valor desde teclado y contar cuántos múltiplos de dicho valor hay en el arreglo.
// g) Leer un valor entero desde teclado y mostrar por pantalla los valores del arreglo que estén
// almacenados en celdas cuyo índice (posición) sea múltiplo del valor leído.
// h) Invertir el arreglo sobre sí mismo (sin usar otro arreglo auxiliar) y desplegarlo por pantalla
// luego de invertido.
// i) Buscar los dos enteros menores del primer arreglo y desplegarlos por pantalla.
// j) Cargar otro arreglo del tipo definido, ordenándolo a medida que se leen los números.
// Desplegar por pantalla el contenido del arreglo.
// k) Determinar si los dos arreglos son iguales (es decir, si tienen almacenados los
// mismos valores y en las mismas posiciones) y luego emitir un mensaje indicando el resultado.
