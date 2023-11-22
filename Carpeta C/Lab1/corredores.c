#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
pthread_barrier_t checkpoint;

void *corredor(void *arg) {
  int id = *((int *)arg);

  printf("---Corredor %d esta listo para correr---\n", id);
  sleep(2);
  pthread_mutex_lock(&mutex);
  printf("---Corredor %d llego al checkpoint---\n", id);
  pthread_mutex_unlock(&mutex);

  pthread_barrier_wait(&checkpoint);

  pthread_mutex_lock(&mutex);
  printf("---Corredor %d completo la carrera---\n", id);
  pthread_mutex_unlock(&mutex);

  pthread_barrier_wait(&checkpoint);

  pthread_exit(NULL);
}

int main() {
  pthread_t corredores[3];
  int id_corredor[3];

  pthread_barrier_init(&checkpoint, 0, 3);
  pthread_mutex_init(&mutex, NULL);

  for (int i = 0; i < 3; i++) {
    id_corredor[i] = i + 1;
    pthread_create(&corredores[i], NULL, corredor, (void *)&id_corredor[i]);
  }

  printf("Comienza la carrera\n");

  for (int i = 0; i < 3; i++) {
    pthread_join(corredores[i], NULL);
  }

  printf("La carrera ha terminado!");

  return 0;
}