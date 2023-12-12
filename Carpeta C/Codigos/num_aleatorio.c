#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define N 10

char tuneles[] = "ABCDE";
pthread_mutex_t mutex;
volatile int esAmbulancia = 0;

void Ambulancias(int signo) {
  if (signo == SIGUSR1) {
    esAmbulancia = 1;
  }
}

void *tunelOcupado(void *arg) {
  int id = *(int *)arg;
  int id_tunel1, id_tunel2;

  pthread_mutex_lock(&mutex);

  if (esAmbulancia) {
    printf("El vehiculo %d tiene prioridad, es una ambulancia\nPasando por el "
           "tunel %c\n",
           id, tuneles[id_tunel1]);
    esAmbulancia = 0;
  }

  // Simulación de lógica para asignar túneles
  int aleatorio = rand() % 5;
  if (aleatorio == 0) {
    id_tunel1 = 0;
    id_tunel2 = 2;
  } else if (aleatorio == 1) {
    id_tunel1 = 1;
    id_tunel2 = 2;
  } else if (aleatorio == 2) {
    id_tunel1 = 2;
    id_tunel2 = rand() % 2;
  } else if (aleatorio == 3) {
    id_tunel1 = 3;
    id_tunel2 = 4;
  } else {
    id_tunel1 = 4;
    id_tunel2 = 3;
  }

  pthread_mutex_unlock(&mutex);

  printf("El vehiculo %d ha entrado al tunel %c\n", id, tuneles[id_tunel1]);
  sleep(rand() % 3 + 1); // Simulación de tiempo en el túnel
  printf("El vehiculo %d ha salido del tunel %c\n", id, tuneles[id_tunel2]);

  return NULL;
}

int main() {
  pthread_t vehiculos[N];
  int ids_vehiculos[N];
  pthread_mutex_init(&mutex, NULL);

  // Configuración del manejador de señales
  signal(SIGUSR1, Ambulancias);

  // Inicializar la semilla del generador de números aleatorios
  srand(time(NULL));

  for (int i = 0; i < N; i++) {
    ids_vehiculos[i] = i + 1;
    pthread_create(&vehiculos[i], NULL, tunelOcupado,
                   (void *)&ids_vehiculos[i]);
  }

  // Esperar a que todos los hilos terminen
  for (int i = 0; i < N; i++) {
    pthread_join(vehiculos[i], NULL);
  }

  pthread_mutex_destroy(&mutex);

  return 0;
}
