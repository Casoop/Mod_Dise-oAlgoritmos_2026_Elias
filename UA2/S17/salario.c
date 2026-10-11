//salario.c - Salario neto en base a horas y pago
#include<stdio.h>

int main(void){

    //Definición de constantes
    const double PORCENTAJE_DEDUCCION = 0.10;

    //Definición de variables
    double horas, tarifaHora, bruto, deduccion, neto;
    
    //ENTRADAS
    printf("Horas Trabajadas: ");
    scanf("%lf", &horas);
    printf("Pago por hora: ");
    scanf("%lf", &tarifaHora);

    //PROCESO
    bruto = horas * tarifaHora;
    deduccion = bruto * PORCENTAJE_DEDUCCION;
    neto = bruto - deduccion;

    //SALIDA
    printf("Salario bruto: %.2f\n", bruto);//%.2f limita los decimales a 2
    printf("Deduccion: %.2f\n", deduccion);
    printf("neto: %.2f\n", neto);

    return 0;
}