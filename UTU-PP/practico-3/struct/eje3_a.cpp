#include <stdio.h>
#include <stdbool.h>

/* 

c) Haga un programa main de prueba para las operaciones del módulo anterior.

*/


const int TAM = 50;

/*
1 - a) Defina un tipo estructurado en C++ para representar
 una Fecha con los campos dia, mes, anio.
*/
struct Fecha {
    int dia;
    int mes;
    int anio;
};

/*
b) Defina las operaciones de Carga, Desplegado y Selectoras. 
 Incluya también una operación que
 dada una fecha determine si la misma es válida. Considere que 
 los años bisiestos son aquellos que son múltiplos de 4.
*/

// Carga
void CargarFecha(Fecha &fecha){
    printf("Carga la fecha papito");
    scanf("%d", fecha.dia);
    scanf("%d", fecha.mes);
    scanf("%d", fecha.anio);
}

// Desplegado
void DesplegarFecha(Fecha &fecha){
    printf("El dia es: %d", fecha.dia);
    printf("El mes es: %d", fecha.mes);
    printf("El anio es: %d", fecha.anio);
}

// Selectoras



// Fecha es valida?
bool FechaEsValida(Fecha fecha){
    
}

/*
3 - a) Defina un tipo Arreglo de Productos (del ejercicio anterior)
 que permita albergar 50 productos.
*/

struct Producto {
    char nombre[TAM];
    long numero;
    int precio;
    bool en_stock;
    Fecha fecha_adquisicion;
    int productos;
};


// b) Defina las siguientes operaciones:
// Carga del arreglo.
void CargarArreglo(Producto productos[]){

    int i;

    for(i=0; i<TAM; i++)
        CargarArreglo(productos[i]);
}

// Desplegado del arreglo.
void DesplegarArreglo(Producto productos[]){

    int i;

    for(i=0; i<TAM; i++)
        DesplegarArreglo(productos[i]);
}


// Dado un número de producto saber si existe en el arreglo.
bool ProductoExiste(long numero, Producto productos[]){


}

// Dado un número de producto obtener el producto correspondiente.
Producto DarProductoPorNumero(int numero, Producto productos[]);

// Calcular el promedio de los precios de los productos del arreglo.
float PromedioDePreciosProductos(Producto productos[]);


// Dado un nombre, determinar cuántos productos con dicho nombre hay en el arreglo.
int CantidadProductosPorNombre(char nombre[], Producto productos[]);

// Devolver cuantos productos están en stock y cuántos no lo están.
// Es procedimiento porque hay 2 salidas distintas
void ProductosEnStockYNoEnStock(Producto productos[], int &stock, int &noStock);

/*
c) Haga un programa main de prueba para las operaciones del
 módulo anterior. Utilice un menú de opciones para permitir
 al usuario probar las distintas operaciones.
*/


int main (){

}