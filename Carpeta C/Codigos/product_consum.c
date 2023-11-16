#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define N 5  // Capacidad máxima del almacén
#define M 3  // Número de productores
#define K 2  // Número de consumidores

sem_t almacen_mutex, espacio_disponible, productos_disponibles;

int almacen[N];
int indice_produccion = 0;
int indice_consumo = 0;

void *productor(void *arg) {
    int id = *((int *)arg);

    for (int i = 0; i < 5; ++i) {
        // Generar un producto
        int producto = rand() % 100;

        // Esperar por espacio disponible en el almacén
        sem_wait(&espacio_disponible);
        sem_wait(&almacen_mutex);

        // Colocar el producto en el almacén
        almacen[indice_produccion] = producto;
        printf("Productor %d genero el producto %d en la posicion %d\n", id, producto, indice_produccion);
        indice_produccion = (indice_produccion + 1) % N;

        // Liberar el mutex y notificar que hay un producto disponible
        sem_post(&almacen_mutex);
        sem_post(&productos_disponibles);
    }

    pthread_exit(NULL);
}

void *consumidor(void *arg) {
    int id = *((int *)arg);

    for (int i = 0; i < 5; ++i) {
        // Esperar por productos disponibles en el almacén
        sem_wait(&productos_disponibles);
        sem_wait(&almacen_mutex);

        // Tomar un producto del almacén
        int producto = almacen[indice_consumo];
        printf("Consumidor %d tomo el producto %d de la posicion %d\n", id, producto, indice_consumo);
        indice_consumo = (indice_consumo + 1) % N;

        // Liberar el mutex y notificar que hay espacio disponible
        sem_post(&almacen_mutex);
        sem_post(&espacio_disponible);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t productores[M], consumidores[K];
    int ids_productores[M], ids_consumidores[K];

    // Inicializar semáforos
    sem_init(&almacen_mutex, 0, 1);
    sem_init(&espacio_disponible, 0, N);
    sem_init(&productos_disponibles, 0, 0);

    // Crear hilos de productores
    for (int i = 0; i < M; ++i) {
        ids_productores[i] = i + 1;
        pthread_create(&productores[i], NULL, productor, (void *)&ids_productores[i]);
    }

    // Crear hilos de consumidores
    for (int i = 0; i < K; ++i) {
        ids_consumidores[i] = i + 1;
        pthread_create(&consumidores[i], NULL, consumidor, (void *)&ids_consumidores[i]);
    }

    // Esperar a que los hilos de productores terminen
    for (int i = 0; i < M; ++i) {
        pthread_join(productores[i], NULL);
    }

    // Esperar a que los hilos de consumidores terminen
    for (int i = 0; i < K; ++i) {
        pthread_join(consumidores[i], NULL);
    }

    // Destruir semáforos
    sem_destroy(&almacen_mutex);
    sem_destroy(&espacio_disponible);
    sem_destroy(&productos_disponibles);

    return 0;
}
