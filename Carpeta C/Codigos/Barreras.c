#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int tmax = 5, tmin = 1, numh = 0;

pthread_barrier_t comer, bailar, cantar;

void *participante(void *arg) {
  int idpar = *((int *)arg);

  // comer
  printf("Partcipante %i esta comiendo\n", idpar);
  usleep((1000000 * (rand() % (tmax - tmin + 1) + tmin)));
  printf("Partcipante %i ya comio\n", idpar);

  pthread_barrier_wait(&comer);

  // bailar
  printf("Partcipante %i esta bailando\n", idpar);
  usleep((1000000 * (rand() % (tmax - tmin + 1) + tmin)));
  printf("Partcipante %i ya bailo\n", idpar);
  pthread_barrier_wait(&bailar);

  // cantar
  printf("Partcipante %i esta cantando\n", idpar);
  usleep((1000000 * (rand() % (tmax - tmin + 1) + tmin)));
  printf("Partcipante %i ya canto\n", idpar);
  pthread_barrier_wait(&cantar);

  return NULL;
}

int main() {
  printf("Escriba el numero de asistentes: ");
  scanf("%i", &numh);

  pthread_t participantes[numh];
  int idpar[numh];

  pthread_barrier_init(&comer, NULL,numh);
  pthread_barrier_init(&bailar, NULL, numh);
  pthread_barrier_init(&cantar, NULL, numh);

  for (int i = 0; i < numh; i++) {
    idpar[i] = i+1;
    pthread_create(&participantes[i], NULL, participante, (void *)&idpar[i]);
  }
  
  for (int i = 0; i < numh; i++) {
    pthread_join(participantes[i],NULL);
  }

  
  pthread_barrier_destroy(&comer);
  pthread_barrier_destroy(&bailar);
  pthread_barrier_destroy(&cantar);

  return 0;
}