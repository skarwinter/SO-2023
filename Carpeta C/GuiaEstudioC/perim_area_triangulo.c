#include <stdio.h>
#include <math.h>

int main(){

    float lado1, lado2, lado3;
    float s, perimetro, area;

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

    s = (lado1+lado2+lado3)/2;
    perimetro = 2*s;
    area = sqrt(s*(s-lado1)*(s-lado2)*(s-lado3));

    printf("Su perimetro es: %.3f\n", perimetro);
    printf("Su semiperimetro es: %.3f\n", s);
    printf("Su area es: %.3f\n", area);
}