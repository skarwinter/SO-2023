int main(void){

    float nota1, nota2, nota3, promedio;

    printf("Ingrese la primera nota: ");
    scanf("%f", &nota1);

    printf("Ingrese la segunda nota: ");
    scanf("%f", &nota2);

    printf("Ingrese la tercera nota: ");
    scanf("%f", &nota3);

    promedio = (nota1*0.4 + nota2*0.3 + nota3*0.3);
    printf("El promedio es: %.3f\n", promedio);   

    return 0;
}