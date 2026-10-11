//descuento.c - Descuento Por Monto: 10 % de descuento en compras de 50000 o más
#include <stdio.h>

//Definición de constantes simbólicas
#define MINIMO 50000.0

int main(void){
    //Definición de constantes
    const double TASA = 0.10;

    //Definición de variables
    double compra, descuento, total;

    //ENTRADA
    printf("Monto de la compra: ");
    scanf("%lf", &compra);

    //PROCESO
    if (compra >= MINIMO)
    {
        //Se aplica el descuento
        descuento = compra * TASA;
    } else {
        //No se aplica el descuento
        descuento = 0;
    }

    //Calculo del total
    total = compra - descuento;

    //SALIDA
    printf("Descuento: %.2f\n", descuento);
    printf("Total a pagar: %.2f\n", total);
    return 0;
}