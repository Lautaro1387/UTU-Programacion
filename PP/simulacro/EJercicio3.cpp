#include <stdio.h>

const int N=8;

int main(){

    int i, cont=0;
    float suma = 0.0;
    int arreglo[N];

    i=0;

    printf("Ingrese el numero 1: ");
    scanf("%d", &arreglo[i]);
    while(arreglo[i]<0)
    {
        printf("El numero ingresado debe ser positivo.\nIngrese el numero 1: ");
        scanf("%d", &arreglo[i]);
    }
    suma = suma + arreglo[i];
    for(i=1; i<N; i++)
    {
        printf("Ingrese el numero %d: ", i+1);
        scanf("%d", &arreglo[i]);
        while(arreglo[i-1]<arreglo[i] || (arreglo[i-1]-arreglo[i])%2!=0 || arreglo[i]<0)
        {
            if(arreglo[i-1]<arreglo[i])
                printf("El numero ingresado debe ser menor al numero anterior.\n");
            else
                if((arreglo[i-1]-arreglo[i])%2!=0)
                    printf("El numero ingresado no tiene diferencia par con el numero anterior.\n");
                else
                    printf("El numero ingresado debe ser positivo.\n");
            printf("Ingrese el numero %d: ", i+1);
            scanf("%d", &arreglo[i]);
        }
        suma = suma + arreglo[i];
    }

    //secuencia
    printf("Secuencia ingresada: ");
    for(i=0; i<N; i++)
    {
        printf(" %d ", arreglo[i]);
        if(arreglo[i]%5==0)
            cont++;
    }

    //cantidad de multiplos de 5
    printf("La cantidad de multiplos de 5 es: %d", cont);

    //promedio
    printf("El promedio es: %.2f", suma/N);
}
