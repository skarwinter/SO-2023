#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t sem_peatones, sem_viniculos;
int num_peatones, num_viniculos;

void *peatones(void *arg) {
  int id = *((int *)arg);

  sem_wait(&sem_peatones);
  printf("----SEMAFORO P VERDE----\n");
  printf("El peaton %d cruzo el semaforo\n", id);
  printf("---SEMAFORO P ROJO----\n");
  sleep(1);
  sem_post(&sem_peatones);

  pthread_exit(NULL);
}

void *vehiculos(void *arg) {
  int id = *((int *)arg);

  sem_wait(&sem_viniculos);
  printf("----SEMAFORO V VERDE----\n");
  printf("El vehiculo %d cruzo el semaforo\n", id);
  printf("---SEMAFORO V ROJO----\n");
  sleep(2);
  sem_post(&sem_viniculos);

  pthread_exit(NULL);
}

int main() {
  printf("Seleccione un numero de peatones (máx. 10): \n");
  scanf("%d", &num_peatones);

  printf("Seleccione un numero de vehículos (máx. 10): \n");
  scanf("%d", &num_viniculos);

  if (num_peatones > 10 || num_viniculos > 10) {
    printf("Ingrese una cantidad menor o igual a 10, intente de nuevo\n");
    return 0;
  }

  pthread_t h_peatones[num_peatones], h_viniculos[num_viniculos];
  int ids_peatones[num_peatones], ids_viniculos[num_viniculos];

  sem_init(&sem_peatones, 0, 1);
  sem_init(&sem_viniculos, 0, num_viniculos);

  for (int i = 0; i < num_peatones; ++i) {
    ids_peatones[i] = i + 1;
    pthread_create(&h_peatones[i], NULL, peatones, (void *)&ids_peatones[i]);
  }

  for (int i = 0; i < num_viniculos; ++i) {
    ids_viniculos[i] = i + 1;
    pthread_create(&h_viniculos[i], NULL, vehiculos, (void *)&ids_viniculos[i]);
  }

  for (int i = 0; i < num_peatones; ++i) {
    pthread_join(h_peatones[i], NULL);
  }

  for (int i = 0; i < num_viniculos; ++i) {
    pthread_join(h_viniculos[i], NULL);
  }

  sem_destroy(&sem_peatones);
  sem_destroy(&sem_viniculos);

  return 0;
}
