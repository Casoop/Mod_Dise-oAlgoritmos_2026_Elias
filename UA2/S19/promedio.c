//promedio.c - Promedio de una cantidad variable de notas
#include <stdio.h>

int main(void) {
    //Definición de variables
    int cantidad, i;
    double nota, suma, promedio;

    //Inicialización de variables
    suma = 0;

    //ENTRADA
    do { //Ciclo para la validación del rango (1-10)
        printf("Cuantas notas va a digitar? (1 a 10): ");
        scanf("%d", &cantidad);
    } while (cantidad < 1 || cantidad > 10);
    
    for (i = 1; i <= cantidad; i++)
    {
        printf("Nota %d (0 a 100): ", i);
        scanf("%lf", &nota);

        if (nota < 0 || nota > 100) {//Se activa en caso de salir del rango
            i--;//Mantiene el número de nota hasta que se ingrese uno dentro del rango
            nota = 0;//Se reinicia a 0 para no sumar números fuera de rango
        }
        
        //PROCESO
        suma+=nota;
    }
    promedio = suma / cantidad;

    //SALIDA
    printf("Suma: %.2f\n", suma);
    printf("Promedio: %.2f\n", promedio);
    return 0;
}