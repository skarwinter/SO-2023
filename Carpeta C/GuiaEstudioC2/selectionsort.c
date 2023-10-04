#include <stdio.h>

int selectionSort() {
    int arreglo[5];
    int i;

    printf("Ingrese 5 números enteros separados por espacios:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arreglo[i]);
    }

    for (i = 0; i < 4; i++) {
        int min_ind = i;
        for (int j = i + 1; j < 5; j++) {
            if (arreglo[j] < arreglo[min_ind]) {
                min_ind = j;
            }
        }
        int temp = arreglo[i];
        arreglo[i] = arreglo[min_ind];
        arreglo[min_ind] = temp;
    }

    printf("Arreglo ordenado:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    return 0;
}

int main() {
    selectionSort();
    return 0;
}