#include <stdio.h>

int main(){

    float lado1, lado2, lado3;

    printf("Ingrese el primer lado: ");
    scanf("%f", &lado1);
    printf("Ingrese el segundo lado: ");
    scanf("%f", &lado2);
    printf("Ingrese el tercer lado: ");
    scanf("%f", &lado3);

   if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
        if (lado1 == lado2 && lado2 == lado3) {
            printf("Es un triángulo equilátero.\n");
        } else {
            printf("Es un triángulo isósceles.\n");
        }
    } else {
        printf("Es un triángulo escaleno.\n");
    }
}