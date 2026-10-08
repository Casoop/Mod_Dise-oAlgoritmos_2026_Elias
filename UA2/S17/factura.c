//Factura con IVA
#include <stdio.h>

int main(void){
    //Constante para el IVA
    const double TASA_IVA = 0.13;

    //Variables enteras para cantidad y reales para montos
    int cantidad;
    double precio, subtotal, iva, total;

    //ENTRADA: pedir y almacenar cantidad. Lee un entero = 3
    printf("Cantidad: ");
    scanf("%d", &cantidad);

    //leer un double precio = 5000
    printf("Precio unitario: ");
    scanf("%lf", &precio);

    //PROCESO: int * double da double -> subtotal = 15000
    subtotal = cantidad * precio;
    //sacamos IVA con la constante -> iva = 1950
    iva = subtotal * TASA_IVA;
    //Total -> 16950
    total = subtotal + iva;

    //SALIDAS: Usar 2 decimales, 10 espacios
    printf("Subtotal: %10.2f\n", subtotal);
    printf("IVA (13%%): %10.2f\n", iva);
    printf("Total:      %10.2f\n", total);
    return 0;
}