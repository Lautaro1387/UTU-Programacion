// #include <iostream>     // Para usar cout (pantalla) y cin (teclado)
#include <pthread.h>    // Crear y manejar hilos
#include <semaphore.h>  // Usar los semaforos
#include <unistd.h>     // Para usar la función sleep() (esperas de segundos)
#include <stdio.h>      // Para usar printf

using namespace std;

// --- 1. SECCIÓN CRÍTICA (El Inventario compartido) ---
int pizzas_disponibles = 0;   // Al abrir, hay 0 pizzas
int postres_disponibles = 0;  // Al abrir, hay 0 postres

// --- 2. CONSTANTES DE CAPACIDAD ---
const int MAX_PIZZAS = 4;     // Capacidad máxima de la mesada
const int MAX_POSTRES = 3;    // Capacidad máxima de la heladera

// --- 3. VARIABLE DE CONTROL ---
bool ejecutar = true;         // Controla que los hilos sigan corriendo
Usa el código con precaución.

// --- 4. SEMÁFOROS PARA LAS PIZZAS ---
sem_t sem_lugar_pizzas;   // Cuenta cuántos espacios vacíos quedan en la mesada
sem_t sem_pizzas_listas;  // Cuenta cuántas pizzas reales hay listas para comer

// --- 5. SEMÁFOROS PARA LOS POSTRES ---
sem_t sem_lugar_postres;  // Cuenta los espacios vacíos en la heladera
sem_t sem_postres_listos; // Cuenta los postres reales listos en la heladera

// --- 6. EL CANDADO PRINCIPAL (MUTEX) ---
sem_t mutex_inventario;   // Semáforo binario para que solo un hilo a la vez altere los números

// --- HILO 1: PRODUCTOR DE PIZZAS (Horno) ---
void* producir_pizzas(void* arg) {
    while (ejecutar) {
        sleep(3); // El horno tarda 3 segundos en cocinar una pizza
        if (!ejecutar) break; // Si el menú dice salir, apagamos el horno

        // --- PROTOCOLO DE SINCRONIZACIÓN ---
        sem_wait(&sem_lugar_postres);   // 1. Gasta un espacio vacío de la mesada. Si está llena, aquí se frena.
        sem_wait(&mutex_inventario);   // 2. Cierra el candado del inventario (Exclusión Mutua).

        // --- SECCIÓN CRÍTICA ---
        pizzas_disponibles++; // Suma la pizza cocinada a la mesada
        // cout << "\n[HORNO] ¡Pizza pronta colocada en la mesada! (Total: " << pizzas_disponibles << ")" << endl;
        printf("Pizza pronta colocada en la mesa! Total: %d \n", postres_disponibles);

        // --- SALIDA DE LA SECCIÓN CRÍTICA ---
        sem_post(&mutex_inventario);   // 3. Abre el candado del inventario para que otros puedan usarlo.
        sem_post(&sem_postres_listos);  // 4. Avisa que hay una pizza más lista para el cliente.
    }
    return NULL;
}


// --- HILO 2: PRODUCTOR DE POSTRES (Horno) ---
void* producir_postres(void* arg) {
    while (ejecutar) {
        sleep(4); // El horno tarda 4 segundos en cocinar un postre
        if (!ejecutar) break; // Si el menú dice salir, apagamos el horno

        // --- PROTOCOLO DE SINCRONIZACIÓN ---
        sem_wait(&sem_lugar_postres);   // 1. Gasta un espacio vacío de la mesada. Si está llena, aquí se frena.
        sem_wait(&mutex_inventario);   // 2. Cierra el candado del inventario (Exclusión Mutua).

        // --- SECCIÓN CRÍTICA ---
        pizzas_disponibles++; // Suma la pizza cocinada a la mesada
        // cout << "\n[HORNO] ¡Pizza pronta colocada en la mesada! (Total: " << pizzas_disponibles << ")" << endl;
        printf("Pizza pronta colocada en la mesa! Total: %d \n", pizzas_disponibles);

        // --- SALIDA DE LA SECCIÓN CRÍTICA ---
        sem_post(&mutex_inventario);   // 3. Abre el candado del inventario para que otros puedan usarlo.
        sem_post(&sem_pizzas_listas);  // 4. Avisa que hay una pizza más lista para el cliente.
    }
    return NULL;
}

int main() {
    // --- PARTE A: INICIALIZACIÓN DE SEMÁFOROS ---
    // El segundo parámetro (0) significa que los semáforos se comparten entre hilos del mismo proceso
    sem_init(&sem_lugar_pizzas, 0, MAX_PIZZAS);   // Arranca con 4 espacios vacíos
    sem_init(&sem_pizzas_listas, 0, 0);           // Arranca con 0 pizzas listas
    sem_init(&sem_lugar_postres, 0, MAX_POSTRES); // Arranca con 3 espacios vacíos
    sem_init(&sem_postres_listos, 0, 0);          // Arranca con 0 postres listos
    sem_init(&mutex_inventario, 0, 1);            // El candado arranca abierto (= 1)

    // --- PARTE B: CREACIÓN DE LOS HILOS TRABAJADORES ---
    pthread_t hilo_pizzas, hilo_postres;
    pthread_create(&hilo_pizzas, NULL, producir_pizzas, NULL);   // Prende el horno
    pthread_create(&hilo_postres, NULL, producir_postres, NULL); // El cocinero empieza a trabajar

    int opcion;
    // (Aquí adentro va a ir el bucle del menú que haremos en el siguiente mensaje)

    // --- PARTE C: BUCLE DEL MENÚ INTERACTIVO (Consumidor) ---
    while (ejecutar) {
    cout << "\n--- MENU PIZZERIA ---" << endl;
    cout << "1. Pedir pizzas." << endl;
    cout << "2. Pedir postres." << endl;
    cout << "3. Consultar inventario." << endl;
    cout << "4. Salir." << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    if (opcion == 1) {
    int cantidad;
    cout << "Cantidad de pizzas que desea: ";
    cin >> cantidad;
    if (cantidad <= 0 || cantidad > MAX_PIZZAS) {
    cout << "[ERROR] Cantidad invalida. Debe ser positiva y no superar " << MAX_PIZZAS << endl;
    continue;
    }
    sem_wait(&mutex_inventario); // Bloqueo seguro para chequear stock
    if (pizzas_disponibles >= cantidad) {
    pizzas_disponibles -= cantidad;
    cout << "[PEDIDO] ¡Entregadas " << cantidad << " pizzas con exito!" << endl;
    // Liberamos espacio físico en la mesada para que el horno siga produciendo
    for (int i = 0; i < cantidad; i++) {
    sem_wait(&sem_pizzas_listas);
    sem_post(&sem_lugar_pizzas);
    }
    } else {
    cout << "[MENSAJE] No hay suficientes unidades disponibles en este momento." << endl;
    }
    sem_post(&mutex_inventario);
    }
    else if (opcion == 2) {
    int cantidad;
    cout << "Cantidad de postres que desea: ";
    cin >> cantidad;
    if (cantidad <= 0 || cantidad > MAX_POSTRES) {
    cout << "[ERROR] Cantidad invalida. Debe ser positiva y no superar " << MAX_POSTRES << endl;
    continue;
    }
    sem_wait(&mutex_inventario);
    if (postres_disponibles >= cantidad) {
    postres_disponibles -= cantidad;
    cout << "[PEDIDO] ¡Entregados " << cantidad << " postres con exito!" << endl;
    // Liberamos espacio en la heladera
    for (int i = 0; i < cantidad; i++) {
    sem_wait(&sem_postres_listos);
    sem_post(&sem_lugar_postres);
    }
    } else {
    cout << "[MENSAJE] No hay suficientes unidades disponibles en este momento." << endl;
    }
    sem_post(&mutex_inventario);
    }
    else if (opcion == 3) {
    sem_wait(&mutex_inventario);
    cout << "\n--- INVENTARIO ACTUAL ---" << endl;
    cout << "Pizzas en la mesada: " << pizzas_disponibles << " / " << MAX_PIZZAS << endl;
    cout << "Postres en la heladera: " << postres_disponibles << " / " << MAX_POSTRES << endl;
    sem_post(&mutex_inventario);
    }
    else if (opcion == 4) {
    cout << "Finalizando hilos y liberando recursos..." << endl;
    ejecutar = false; // Detiene los bucles while de los hilos
    }
    else {
    cout << "[ERROR] Opcion incorrecta." << endl;
    }
    }
    // --- PARTE D: LIMPIEZA FINAL DE RECURSOS ---
    // Destrabamos hilos productores en caso de que hayan quedado bloqueados esperando espacio
    sem_post(&sem_lugar_pizzas);
    sem_post(&sem_lugar_postres);
    // Esperamos a que los hilos terminen su última iteración limpiamente
    pthread_join(hilo_pizzas, NULL);
    pthread_join(hilo_postres);
    // Destruimos los semáforos del sistema operativo
    sem_destroy(&sem_lugar_pizzas);
    sem_destroy(&sem_pizzas_listas);
    sem_destroy(&sem_lugar_postres);
    sem_destroy(&sem_postres_listos);
    sem_destroy(&mutex_inventario);
    cout << "Recursos liberados. Programa terminado con exito." << endl;
    return 0;
}