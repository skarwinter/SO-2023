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
        //generar producto
        int producto = rand() % 1000 % 9999;

        //esperar semaforo
        sem_wait(&espacio_disponible);
        sem_wait(&almacen_mutex);

        //colocar producto
        almacen[indice_produccion] = producto;
        printf("Productor %d genero el producto %d en la posicion %d\n", id, producto, indice_produccion);
        indice_produccion = (indice_produccion + 1) % N;

        //liberar semaforo
        sem_post(&almacen_mutex);
        sem_post(&productos_disponibles);
    }

    pthread_exit(NULL);
}

void *consumidor(void *arg) {
    int id = *((int *)arg);

    for (int i = 0; i < 5; ++i) {
        //esperar producto
        sem_wait(&productos_disponibles);
        sem_wait(&almacen_mutex);

        //tomar producto
        int producto = almacen[indice_consumo];
        printf("Consumidor %d tomo el producto %d de la posicion %d\n", id, producto, indice_consumo);
        indice_consumo = (indice_consumo + 1) % N;

        //liberar mutex
        sem_post(&almacen_mutex);
        sem_post(&espacio_disponible);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t productores[M], consumidores[K];
    int ids_productores[M], ids_consumidores[K];

    //inicializar semaforos
    sem_init(&almacen_mutex, 0, 1);
    sem_init(&espacio_disponible, 0, N);
    sem_init(&productos_disponibles, 0, 0);

    //crear hilos prod
    for (int i = 0; i < M; ++i) {
        ids_productores[i] = i + 1;
        pthread_create(&productores[i], NULL, productor, (void *)&ids_productores[i]);
    }

    //crera hilos consum
    for (int i = 0; i < K; ++i) {
        ids_consumidores[i] = i + 1;
        pthread_create(&consumidores[i], NULL, consumidor, (void *)&ids_consumidores[i]);
    }

    //esperar hiulos prod
    for (int i = 0; i < M; ++i) {
        pthread_join(productores[i], NULL);
    }

    //esperar hilos consum
    for (int i = 0; i < K; ++i) {
        pthread_join(consumidores[i], NULL);
    }

    //destruir semaforos(no molvidr)
    sem_destroy(&almacen_mutex);
    sem_destroy(&espacio_disponible);
    sem_destroy(&productos_disponibles);

    return 0;
}
