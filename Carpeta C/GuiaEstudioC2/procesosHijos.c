#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    clock_t tiempo_inicio, tiempo_fin;
    double tiempo_total = 0.0;
    int num_procesos = 50;

    for (int i = 0; i < num_procesos; i++) {
        tiempo_inicio = clock();

        pid_t proceso_id = fork();

        if (proceso_id == -1) {
            perror("Error al crear el proceso hijo");
            exit(1);
        } else if (proceso_id == 0) {
            //codigo ejecutado por el proceso hijo
            exit(0);
        } else {
            //codigo ejecutado por el proceso padre
            wait(NULL); //espera a que el proceso hijo termine
            tiempo_fin = clock();

            double tiempo_hijo = (double)(tiempo_fin - tiempo_inicio) / CLOCKS_PER_SEC;

            printf("Proceso hijo %d creado en %.6f segundos.\n", i + 1, tiempo_hijo);
            tiempo_total += tiempo_hijo;
        }
    }

    double prom_tiempo = tiempo_total / num_procesos; //promedio tiempo
    printf("Tiempo medio de creacion de procesos: %.6f segundos.\n", prom_tiempo);

    return 0;
}