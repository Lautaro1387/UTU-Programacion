#include <stdio.h>
#include <string.h>

const int MAX = 80;



void CargarString(char cadena[])
{
    int i = 0;
    char letra;

    //printf("Ingrese el texto.");
    scanf("%c", &letra);

    while(letra!='\n' && i<MAX-1)
    {
        cadena[i] = letra;
        i++;
        scanf("%c", &letra);
    }

    cadena[i] = '\0';

}

void ImprimirString(char cadena[])
{
    int i=0;
    while(cadena[i]!='\0')
    {
        printf("%c", cadena[i]);
        i++;
    }

}

/***************************************************************************************/

struct Fecha{
    int dia;
    int mes;
    int anio;
    };


void CargarFecha(Fecha &f){
    printf("Ingrese dia, mes y año: \n");
    scanf("%d%d%d", &f.dia, &f.mes, &f.anio);
}


void DesplegarFecha(Fecha f){
    printf("%d/%d/%d", f.dia, f.mes, f.anio);
}

int DarDia(Fecha f){
    return f.dia;
}

int DarMes(Fecha f){
    return f.mes;
}

int DarAño(Fecha f){
    return f.anio;
}

bool FechaValida(Fecha f)
{
    bool valida = false;

    switch(f.mes)
    {
        case 1: case 3: case 5: case 7: case 8:
        case 10: case 12:
            if(f.dia >= 1 && f.dia <= 31)
                valida = true;
            break;
        case 4: case 6: case 9: case 11:
            if(f.dia >= 1 && f.dia <= 30)
                valida = true;
            break;
        case 2:
            if(f.anio%4==0)
            {
                if(f.dia >= 1 && f.dia <= 29)
                    valida = true;
                else
                    if(f.dia >= 1 && f.dia <= 28)
                        valida = true;
            }

            break;
    }

    return valida;
}

/*********************************************************************************************/


struct Producto{
    char nombre[MAX];
    long numero;
    float precio;
    bool en_stock;
    Fecha fecha_adquisicion;
};

//carga
void CargarProducto(Producto &p)
{
    int val;
    printf("Ingrese la informacion del producto: \n");
    printf("Nombre del producto: ");
    CargarString(p.nombre);
    printf("Numero del producto: ");
    scanf("%ld", &p.numero);
    printf("Precio del producto: ");
    scanf("%f", &p.precio);
    printf("Ingrese si hay stock del producto (0 - NO, 1 - SI): ");
    scanf("%d", &val);
    if(val==0)
        p.en_stock = false;
    else
        p.en_stock = true;
    printf("Cargue la fecha de adquisicion: ");
    CargarFecha(p.fecha_adquisicion);

}

//desplegar
void DesplegarProducto(Producto prod){

    printf("El nombre de producto es ");
    ImprimirString(prod.nombre);
    printf("\n");
    printf("EL numero del producto es ");
    printf("%ld", prod.numero);
    printf("\n");
    printf("El precio del producto es ");
    printf("%.2f", prod.precio);
    printf("\n");
    if(prod.en_stock==true)
        printf("Hay stock.");
    else
        printf("No hay stock.");
    printf("\n");
    printf("Fecha de adquisición es ");
    DesplegarFecha(prod.fecha_adquisicion);
    printf("\n");

}

//selectoras
void DarNombreProducto(Producto prod, char nombreResultado[])
{
    //proc de la biblioteca string.h que copia
    //el segundo string en el primero
    strcpy(nombreResultado,prod.nombre);
}

long DarNumeroProducto(Producto prod)
{
    return prod.numero;
}

float DarPrecioProducto(Producto prod)
{
    return prod.precio;
}

bool DarStockProducto(Producto prod)
{
    return prod.en_stock;
}

Fecha DarFechaProducto(Producto prod)
{
    return prod.fecha_adquisicion;
}



int main()
{
    Producto p;
    CargarProducto(p);
    DesplegarProducto(p);

    char nombreP[MAX];

    DarNombreProducto(p,nombreP);

    ImprimirString(nombreP);
}
