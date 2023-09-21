#include <stdio.h>

int main(){
    float nota1, nota2, nota3;
    float promedio;

    printf("Ingrese la primera nota: ");
    scanf("%f", &nota1);

    printf("Ingrese la segunda nota: ");
    scanf("%f", &nota2);

    printf("Ingrese la tercera nota: ");
    scanf("%f", &nota3);

    promedio = (nota1*0.4 + nota2*0.3 + nota3*0.3);
    printf("El promedio es: %.3f\n", promedio);   
    if (promedio<4.95){
        if (promedio<3.95){
        printf("El alumno ha reprobado la asignatura");
        } else {
            printf("El alumno debe ir a examen");
        }
    } else {
        printf("El alumno ha aprobado la asignatura");
    }

    return 0;
}