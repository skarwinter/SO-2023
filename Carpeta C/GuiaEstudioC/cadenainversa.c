#include <stdio.h>
#include <string.h>

void invertirCadena(char *cadena) {
    int i, j;
    char rev;
    int largo = strlen(cadena);
    for (i = 0, j = largo - 1; i < j; i++, j--) {
        rev = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = rev;
    }
}

int main() {
    char cadena[99];

    printf("Ingrese una cadena de texto: ");
    gets(cadena);
    invertirCadena(cadena);
    printf("Cadena invertida: %s\n", cadena);
    return 0;
}





