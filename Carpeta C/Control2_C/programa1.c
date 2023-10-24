#include <stdio.h>

int main() {
  int numValidos[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int num_select;

  while (1) {
    printf("Ingrese un numero de 0 al 10: \n");
    scanf("%d", &num_select);

    if (num_select < 0) {
        printf("El numero ingresado es valido\n");
      break;
    } else if (num_select == numValidos[num_select]) {
        printf("Ingrese un numero valido\n");
    } else {
        printf("Ingrese un numero valido\n");
    }
  }
}