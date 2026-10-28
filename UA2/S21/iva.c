#include <stdio.h>
#define TASA_IVA 0.13

double calcularIVA(double monto); // prototipo

int main(void) {
double precio = 15000;
double iva = calcularIVA(precio); // llamada con una variable
printf("IVA de %.2f: %.2f\n", precio, iva);
printf("IVA de 2500: %.2f\n", calcularIVA(2500)); // con un numero
return 0;
}

double calcularIVA(double monto) { // definicion
return monto * TASA_IVA;
}
