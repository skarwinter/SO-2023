#include <stdio.h>

int main(){
    int n = 0;
    int suma = 0;
    int contador = 0; 

    while(contador<100){
        suma += 2*n+1;
        n++; 
        contador++;
    }
    printf("La suma de los primeros 100 numeros impares es: %d\n", suma);

    return 0;
}