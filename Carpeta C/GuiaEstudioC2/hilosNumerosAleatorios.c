#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define num_hilos 10

int numeros_aleatorios[num_hilos];

//funcion que genera el numero random
void* generar_randint(void* arg) {
    int *num_generado = (int*)malloc(sizeof(int));//malloc: permite asignar memoria al hilo para no perderlo
    int hilo_idx = *((int*)arg); //indice de los hilos
    srand(time(NULL) + hilo_idx); //inicializa el generador de números aleatorios en los índices de los hilos
    *num_generado = rand() % 20 + 1;
    pthread_exit(num_generado);
}

int main() {
    pthread_t hilos[num_hilos];

    for (int i = 0; i < num_hilos; i++) {
        pthread_create(&hilos[i], NULL, generar_randint, (void*)&i);
    }

    //suma de los hilos
    int suma = 0;
    printf("Numeros generados por cada hilo:\n");
    for (int i = 0; i < num_hilos; i++) {
        int *num_generado;
        pthread_join(hilos[i], (void**)&num_generado); //se saca el valor del hilo i (el numero generado) y se guarda en num_generado
        suma += *num_generado;
        numeros_aleatorios[i] = *num_generado; //se guardan los numero generados por los hilos en la lista
        free(num_generado); 
    }

    for (int i = 0; i < num_hilos; i++) {
        printf("%d ", numeros_aleatorios[i]); //se imprimen los numeros generados
    }
    printf("\n");
    printf("Suma de los numeros generados: %d\n", suma);
    return 0;
}