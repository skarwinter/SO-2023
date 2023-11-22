#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define I 5
#define D 3

sem_t sem_izq, sem_der;

void *vehiculo_izq(void *arg) {
  int id = *((int *)arg);

  int espera = rand() % 2 % 5;

  sem_wait(&sem_der);
  printf("---Vehiculo %d cruzando al lado der---\n", id);
  sleep(espera);
  printf("---Vehiculo %d paso al otro lado, demoro %d segundos---\n", id,
         espera);
  sleep(2);
  sem_post(&sem_izq);

  pthread_exit(NULL);
}

void *vehiculo_der(void *arg) {
  int id = *((int *)arg);

  int espera = rand() % 2 % 5;

  sem_wait(&sem_izq);
  printf("Vehiculo %d cruzando al lado izq\n", id);
  sleep(espera);
  printf("---Vehiculo %d paso al otro lado, demoro %d segundos---\n", id,
         espera);
  sleep(2);
  sem_post(&sem_der);

  pthread_exit(NULL);
}

int main() {

  pthread_t vehiculos_izq[I], vehiculos_der[D];
  int ids_vehiculos_izq[I], ids_vehiculos_der[D];

  sem_init(&sem_izq, 0, 1);
  sem_init(&sem_der, 0, 0);

  for (int i = 0; i < I; i++) {
    ids_vehiculos_izq[i] = i + 1;
    pthread_create(&vehiculos_izq[i], NULL, vehiculo_izq,
                   (void *)&ids_vehiculos_izq[i]);
  }

  for (int i = 0; i < D; i++) {
    ids_vehiculos_der[i] = i + 1;
    pthread_create(&vehiculos_der[i], NULL, vehiculo_der,
                   (void *)&ids_vehiculos_der[i]);
  }

  for (int i = 0; i < I; i++) {
    pthread_join(vehiculos_izq[i], NULL);
  }

  for (int i = 0; i < D; i++) {
    pthread_join(vehiculos_der[i], NULL);
  }

  sem_destroy(&sem_izq);
  sem_destroy(&sem_der);

  return 0;
}