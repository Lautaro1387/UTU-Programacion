#include <stdio.h>
#include <stdbool.h>
/* 
a) Defina un tipo estructurado en C++ para representar
una Fecha con los campos dia, mes, anio.

b) Defina las operaciones de Carga, Desplegado y Selectoras. Incluya también una operación que
dada una fecha determine si la misma es válida. Considere que los años bisiestos son aquellos
que son múltiplos de 4.

c) Haga un programa main de prueba para las operaciones del módulo anterior.

*/

// parte a) solo struct de Fecha
struct Fecha
{
    int dia;
    int mes;
    int anio;
};

//parte b) 
// carga
void CargarFecha(Fecha &fecha){
    
    scanf("%d", &fecha.dia);
    scanf("%d", &fecha.mes);
    scanf("%d", &fecha.anio);
}

// desplegado
void DesplegadoFecha(Fecha &fecha)
{

    printf("Ingrese dia: %d \n", fecha.dia);
    printf("Ingrese mes: %d \n", fecha.mes);
    printf("Ingrese anio: %d \n", fecha.anio);
}

// selectoras
// void ObtenerFecha() ?


// fecha valida
bool FechaValida(Fecha f){

    bool valida = false;

    switch(f.mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (f.dia >= 1 && f.dia <= 31)
                valida = true;
            break;
        case 4: case 6: case 9: case 11:
            if (f.dia >= 1 && f.dia <= 30)
                valida = true;
            break;
        case 2: 
            if (f.anio%4==0)
                if (f.dia >= 1 && f.dia <= 29)
                    valida = true;
                else
                    if (f.dia >= 1 && f.dia <= 28)
                    valida = true;
            break;
    }

    return valida;

}


int main(){

    Fecha f; // datos cargados desde el scanf anterior
    if(FechaValida(f))
        printf("La fecha es correcta");
    else   
        printf("La fecha no es correcta");
    
    // CargarFecha(f);
}
