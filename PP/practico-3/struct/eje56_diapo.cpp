#include <stdio.h>
#include <stdbool.h>


const int MAX = 20;

struct Alumnos {
    char nombre[10];
    char apellido[10];
    char cedula[10];
    int edad;
    int faltas;
    bool hayFoto;
};


void CargarString(char limite[]){

    int i = 0;
    char nombres;

    scanf("%c", &nombres);
    while (i < MAX - 1 && nombres != '\n'){
        limite[i] = nombres;
        scanf("%c", &nombres);
        i++;
    }
    limite[i] = '\0';
}

void CargarAlumno(Alumnos &alumnos){

    int foto;

    printf("Nombre: ");
    CargarString(alumnos.nombre);
    printf("Apellido: ");
    CargarString(alumnos.apellido);
    printf("Cedula: ");
    CargarString(alumnos.cedula);
    printf("Ingrese edad: ");
    scanf("%d", &alumnos.edad);
    printf("Ingrese faltas: ");
    scanf("%d", &alumnos.faltas);
    printf("Ingrese 1 si el alumno tiene foto, si no ingrese 0: ");
    scanf("%d", &foto);
    if (foto == 1)
        alumnos.hayFoto = true;
    else
        alumnos.hayFoto = false;
}

void cargarArreAlumnos(Alumnos arreAlumnos[], int &tamanio){

    int i = 0;
    char opcion;

    do {
        printf("Ingrese los datos del alumno: %d", i+1);
        CargarAlumno(arreAlumnos[i]);
        printf("Desea ingresar mas alumnos? S: si, N: no: ");
        scanf(" %c", &opcion);
        getchar();
    } while ((opcion == 'S' || opcion == 's') && i<MAX);

    tamanio = i;
}

bool existeAlumnoAArreglo(Alumnos arregloAlumnos[], char cedula[]){

}

void pasarLista(Alumnos arreAlumnos[], int tope){


    char cedula[10];
    printf("Pasaje de lista");

    do {

        printf("Ingrese una cedula: ");
        CargarString(cedula);

    } while(tope);

}

int main(){

    Alumnos arreAlumnos[MAX];
    int tope;

    cargarArreAlumnos(arreAlumnos, tope);

    pasarLista(arreAlumnos, tope);
}
