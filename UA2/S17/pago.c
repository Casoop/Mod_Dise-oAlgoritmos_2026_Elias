//pago.c - Calcula el pago semanal de una persona colaboradora
#include<stdio.h>

#define BONO 5000.0

int main(void){

    //Definición de variables
    double horas, pagoHora, salario;

    //ENTRADA
    printf("Horas trabajadas en la semana: ");
    scanf("%lf", &horas); //NOTA: TIENES que poner el & o sino no se guarda (nota 2: esto a menos de que sea una variable de texto)
    printf("Pago por hora: ");
    scanf("%lf", &pagoHora);

    //PROCESO
    salario = horas * pagoHora + BONO; //Se multiplican las horas por pagoHora, y despues de eso se suma el bono

    //SALIDA
    printf("-----------------------------\n");
    printf("%-18s", "Horas: ");//Con el uso de "-" el texto se alinea a la izquierda y con 18 espacios, si no se usan el resto queda como espacios en blanco
    printf("%10.2f\n", horas);//Sin el uso de "-" el texto se alinea a la deracha y con 10 espacios, si no se usan el resto queda como espacios en blanco
    printf("%-18s", "Pago por hora: ");
    printf("%10.2f\n", pagoHora);
    printf("%-18s", "Bono: ");
    printf("%10.2f\n", BONO);
    printf("%-18s", "Pago semanal: ");
    printf("%10.2f\n", salario);
    printf("-----------------------------\n");

    return 0;
}