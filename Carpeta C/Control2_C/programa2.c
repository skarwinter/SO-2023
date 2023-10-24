#include <math.h>
#include <stdio.h>

double main() {

  double a, b, c;

  char op_valid;

  printf("Ingrese el valor de A: ");
  scanf("%lf", &a);
  printf("Ingrese el valor de B: ");
  scanf("%lf", &b);
  printf("Ingrese el valor de C: ");
  scanf("%lf", &c);

  printf("Ingrese el operador a realizar (+, -, *, /): \n");
  scanf("%s", &op_valid);

  if (op_valid == '+') {
    double suma = a + b + c;
    printf("%.4lf",suma);
  } else if (op_valid == '-') {
    double resta = a - b - c;
    printf("%.4lf",resta);
  } else if (op_valid == '*') {
    double multiplicacion = a * b * c;
    printf("%.4lf",multiplicacion);
  } else if (op_valid == '/') {
    double division = a / b / c;
    printf("%.4lf",division);
  } else {
    printf("Ingrese un operador valido. Intente nuevamente");
    return 0;
  }
}