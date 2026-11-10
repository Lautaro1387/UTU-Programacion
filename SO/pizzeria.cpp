#include <unistd.h>    // sleep()
#include <stdio.h>     // printf
#include <pthread.h>   // hilos
#include <semaphore.h> // semaforos

// 1 Inventario al abrir
int pizzas_disponibles = 0;
int postres_disponibles = 0;

// 2 - Capacidad
const int MAX_PIZZAS = 4;  // mesada
const int MAX_POSTRES = 3; // heladera

// 3 - Contra los hilos
bool ejecutar = true;


// 4 - Semaforo de las pizzas
sem_t sem_lugar_pizzas;  // Contador de espacios vacios en la mesada
sem_t sem_pizzas_listas; // Contador de pizzas listas

// 5 - Semaforo de los postres
sem_t sem_lugar_postres;  // Contador de espacios vacios en la heladera
sem_t sem_postres_listos; // Contador de postres listos

// 6 - mutex_main
sem_t mutex_inventario; // Semáforo binario para que solo un hilo a la vez altere los números

// HILO 1 - PRODUCTOR DE PIZZAS (Horno)
void *producir_pizzas(void *arg) {

    while (ejecutar) {
        sleep(3);

        // Sincronización
        sem_wait(&sem_lugar_pizzas); // Gasta un espacio vacío. Si está vacia, aquí se frena.
        sem_wait(&mutex_inventario); // Cierra el candado del inventario (Exclusión Mutua).

        // Entrada - Sección critica
        pizzas_disponibles++;
        printf("Pizza pronta colocada en la mesada! Total: %d \n", pizzas_disponibles);

        // Salida - Sección critica
        sem_post(&mutex_inventario);  // Abre el candado del inventario para que otros puedan usarlo.
        sem_post(&sem_pizzas_listas); // Avisa que hay una pizza más lista para el cliente; // Para salir de la producción

    }
    return NULL;
}

// HILO 2 - PRODUCTOR DE POSTRES (Horno)
void *producir_postres(void *arg) {

    while (ejecutar) {
        sleep(4);

        // Sincronización
        sem_wait(&sem_lugar_postres); // Gasta un espacio vacío de la mesada. Si está llena, aquí se frena.
        sem_wait(&mutex_inventario);  // =0 del inventario (Exclusión Mutua).

        // Entrada - Sección critica
        postres_disponibles++;
        printf("Postre pronto colocada en la mesada! Total: %d \n", postres_disponibles);

        // Salida - Sección critica
        sem_post(&mutex_inventario);   // =1 del inventario para que otros puedan usarlo.
        sem_post(&sem_postres_listos); // Avisa que hay una pizza más lista para el cliente.
    }
    return NULL;
}

int main() {
    // Inicialización
    // El (0) es que los semáforos se comparten entre hilos (mismo proceso)
    sem_init(&sem_lugar_pizzas, 0, MAX_PIZZAS);   // 4 espacios vacíos
    sem_init(&sem_pizzas_listas, 0, 0);           // 0
    sem_init(&sem_lugar_postres, 0, MAX_POSTRES); // 3 espacios vacíos
    sem_init(&sem_postres_listos, 0, 0);          // 0
    sem_init(&mutex_inventario, 0, 1);            // El candado arranca abierto (= 1)

    // Creación de los hilos
    pthread_t hilo_pizzas, hilo_postres;
    pthread_create(&hilo_pizzas, NULL, producir_pizzas, NULL); // Prende el horno
    pthread_create(&hilo_postres, NULL, producir_postres, NULL); // El cocinero empieza

    int opcion;

    // Menu interactivo del consumidor
    while (ejecutar) {
        printf("Menu Pizzeria\n");
        printf("1. Pedir pizzas\n");
        printf("2. Pedir postres.\n");
        printf("3. Consultar inventario.\n");
        printf("4. Salir.\n");
        printf("Seleccione una opcion: ");

        scanf("%d", &opcion);
        if (opcion == 1) {
            int cantidad;
            printf("Cantidad de pizzas que quiere: ");
            sem_wait(&mutex_inventario); // Bloqueo seguro para chequear stock
            scanf("%d", &cantidad);
            if (cantidad <= 0 || cantidad > MAX_PIZZAS)
                printf("Error - Cantidad invalida. Debe ser positiva y no superar %d\n", MAX_PIZZAS);
            if (pizzas_disponibles >= cantidad) {
                pizzas_disponibles -= cantidad;
                printf("Pizzas entregadas con exito: %d\n", cantidad);

                // Liberamos espacio de la mesada (asi el horno sigue produciendo)
                for (int i = 0; i < cantidad; i++) {
                    sem_wait(&sem_pizzas_listas);
                    sem_post(&sem_lugar_pizzas);
                }
            } else
                printf("No hay suficientes unidades disponibles en este momento.\n");
            sem_post(&mutex_inventario);
        }

        else if (opcion == 2) {
            int cantidad;
            printf("Cantidad de postres que desea: ");
            sem_wait(&mutex_inventario);
            scanf("%d", &cantidad);
            if (cantidad <= 0 || cantidad > MAX_POSTRES)
                printf("Error - Cantidad invalida. Debe ser positiva y no superar %d\n", MAX_POSTRES);

            if (postres_disponibles >= cantidad) {
                postres_disponibles -= cantidad;
                printf("Postres entregados con exito: %d\n", cantidad);

                // Liberamos espacio en la heladera
                for (int i = 0; i < cantidad; i++) {
                    sem_wait(&sem_postres_listos);
                    sem_post(&sem_lugar_postres);
                }
            }
            else
                printf("No hay suficientes unidades disponibles en este momento.\n");
            sem_post(&mutex_inventario);
        }
        else if (opcion == 3) {
            sem_wait(&mutex_inventario);
            printf("\n--- INVENTARIO ACTUAL ---\n");
            printf("Pizzas en la mesada: %d / %d\n", pizzas_disponibles, MAX_PIZZAS);
            printf("Postres en la heladera: %d / %d\n", postres_disponibles, MAX_POSTRES);
            sem_post(&mutex_inventario);
        }
        else if (opcion == 4) {
            printf("Finalizando hilos y liberando recursos...\n");
            ejecutar = false; // Detiene los whiles de los hilos y salimos del menu
        }
        else
            printf("Error - Opcion incorrecta.\n");
    }
    // Limpieza de recursos
    // Destrabamos hilos por si quedaron bloqueados esperando espacio
    sem_post(&sem_lugar_pizzas);
    sem_post(&sem_lugar_postres);

    // Esperamos a que los hilos terminen su última iteracion
    pthread_join(hilo_pizzas, NULL);
    pthread_join(hilo_postres, NULL);

    // Destruimos los semáforos
    sem_destroy(&sem_lugar_pizzas);
    sem_destroy(&sem_pizzas_listas);
    sem_destroy(&sem_lugar_postres);
    sem_destroy(&sem_postres_listos);
    sem_destroy(&mutex_inventario);
    printf("Recursos liberados. Programa terminado con exito.\n");
    return 0;

}