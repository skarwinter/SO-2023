#include <stdio.h>
#include <string.h>

int main() {
  char vocals[] = {'a', 'e', 'i', 'o', 'u'};
  char consonantes[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
                        'n', 'p', 'q', 'r', 's', 't', 'v', 'x', 'y', 'z'};

  char cadena[99];
  int i, j, k;
  int suma_v = 0;
  int suma_c = 0;

  printf("Ingrese una cadena de texto: ");
  gets(cadena);

  for (i = 0; i < cadena[i]; i++) {
    for (j = 0; j < vocals[j]; j++) {
      if (cadena[i] == vocals[j]) {
        suma_v = suma_v + 1;
      }
    }

    for (k = 0; k < consonantes[k]; k++) {
      if (cadena[i] == consonantes[k]) {
        suma_c = suma_c + 1;
      }
    }
  }

  printf("Vocales en la cadena: %d\n", suma_v);
  printf("Consonantes en la cadena: %d\n", suma_c);
}