#include <stdio.h>
#include <string.h>

struct Producto {
    int codigo;
    char descripcion[100];
    float precio;
};

int main() {
    struct Producto producto1, producto2;

    printf("Ingrese el código del producto 1: ");
    scanf("%d", &producto1.codigo);
    printf("Ingrese la descripción del producto 1: ");
    scanf(" %[^\n]s", producto1.descripcion);  // ssamos  %[^\n]s para leer una línea completa
    printf("Ingrese el precio del producto 1: ");
    scanf("%f", &producto1.precio);

    // Cargar datos para el producto2
    printf("Ingrese el código del producto 2: ");
    scanf("%d", &producto2.codigo);
    printf("Ingrese la descripción del producto 2: ");
    scanf(" %[^\n]s", producto2.descripcion);
    printf("Ingrese el precio del producto 2: ");
    scanf("%f", &producto2.precio);

    // Comparar los precios y encontrar el producto con mayor precio
    if (producto1.precio > producto2.precio) {
        printf("El producto con mayor precio es: %s\n", producto1.descripcion);
    } else if (producto2.precio > producto1.precio) {
        printf("El producto con mayor precio es: %s\n", producto2.descripcion);
    } else {
        printf("Ambos productos tienen el mismo precio.\n");
    }

    return 0;
}
