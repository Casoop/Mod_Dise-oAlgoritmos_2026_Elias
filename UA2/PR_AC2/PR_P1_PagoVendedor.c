/*Una distribuidora paga a sus vendedores una comisión sobre las ventas del mes. Escriba un programa en C que:
1. Reciba el nombre del vendedor y las ventas de cada una de las 4 semanas del mes en un arreglo. Ninguna venta puede ser negativa (se vuelve a pedir).
2. Calcule las ventas del mes, la comisión (5 % de las ventas) y un bono de 50 si las ventas del mes superan 2000.
3. Calcule la retención (2 % de la comisión más el bono) y el pago (comisión + bono − retención).
4. Muestre las ventas de cada semana, las ventas del mes y el detalle del pago con dos decimales.*/

#include <stdio.h>//Entradas y salidas
#include <string.h>
#include <stdlib.h>//utilidad general

int main (void) {
    //Definición de constantes
    const double PORCENJATE_COMISION = 0.05;    //Porcentaja del 5%
    const int BONO = 50;
    const double PORCENJATE_RETENCION = 0.02;   //Porcentaja del 2%
    const int LIMITE = 2000;

    //Definición de variables
    char nombre[40];    //Permite almacenar nombres de hasta 40 caracteres
    double ventas[4];   //Arreglo  que permite guardar 4 datos de ventas
    double comision, retencion, pago, delMes, cantidadBono = 0; 
    int i;

    //ENTRADA
    printf("=== Pago del vendedor ===\n");
    printf("Nombre del vendedor: ");
    fgets(nombre, sizeof(nombre), stdin);

    nombre [strcspn(nombre, "\n")] =  '\0';

    for (i = 0; i < 4; i++){//Empeza en 0 cada siclo se suma 1 a i, esto funciona para guardar datos en ventas y mostrar el dia
        do{
            printf("Ventas de la semana %d: ", i + 1); //i + 1, permite mostrar el dia de forma naturar, no olvidar que en 0 se empieza a contar en 0 mientras que una semana se comienza a contar en 1
            scanf("%lf", &ventas[i]);
        } while (ventas[i] < 0);//Entra en un bucle en caso de que el usuario ponga un número negativo
    }

    //SALIDA A
    printf("\n------- Pago de %s -------\n", nombre);
    for (i = 0; i < 4; i++){//Este for se utiliza para mostrar un resumen de las ventas por semana
        printf("Semana %d: ", i + 1);
        printf("%-8.2f\n", ventas[i]);

        delMes+=ventas[i];
    }

    //PROCESO
    comision = delMes*PORCENJATE_COMISION;
    if (delMes > LIMITE){//En caso de pasar del limite de 2000 se acredita un bono de 50
        cantidadBono = BONO;
    }
    retencion = PORCENJATE_RETENCION*(comision+cantidadBono); //Se calcula un 2% de retencion de las comisiones y el pago
    pago = comision + cantidadBono - retencion;

    //SALIDA
    printf("Ventas del mes: %-8.2f\n", delMes);     //2250.00
    printf("Comision (5%%): %-8.2f\n", comision);   //112.00
    printf("Bono: %-8.2f\n", cantidadBono);         //50.00
    printf("Retencion (2%%): %-8.2f\n", retencion); //3.25
    printf("Pago del mes: %-8.2f\n", pago);         //159.25
}