//bisiesto.c - Determina si el año es o no bisiesto

#include <stdio.h>

int main(void) {
    //Definición de variables
    int anio;
    int esBisiesto; //Variables logicas

    //Incialización de variables
    esBisiesto = 0;

    //ENTRADA
    printf("Anio: ");
    scanf("%d", &anio);

    //PROCESO
    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
    {
        esBisiesto = 1;
    }
    
    //SALIDA
    printf("%d %s es bisiesto", anio, (esBisiesto == 1) ? "si" : "no"); //Con este recibi asistencia, debo repasar esta parte

    return 0;
}