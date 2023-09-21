#include <stdio.h>

int main(){
    float nota1,nota2,nota3,nota4;
    float promedio;

    printf("Ingrese la primera nota: ");
    scanf("%f", &nota1);

    printf("Ingrese la segunda nota: ");
    scanf("%f", &nota2);

    printf("Ingrese la tercera nota: ");
    scanf("%f", &nota3);

    printf("Ingrese la cuarta nota: ");
    scanf("%f", &nota4);

    promedio = (nota1 + nota2 + nota3 + nota4)/4;
    printf("El promedio es: %.3f\n", promedio);  
}