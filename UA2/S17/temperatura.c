//temperatura.c - Algoritmo ConversionTemperatura
// Convierte grados Celsius a Fahrenheit 
#include <stdio.h>

int main(void){
    //Definición de variables
    double celcius, fahrenheit;

    //Entrada
    printf("Temperatura en grados Celsius: ");
    scanf("%lf", &celcius);//& dirige a una posicion de memoria

    //Proceso
    fahrenheit = celcius * 9 / 5 + 32;

    //Salida
    printf("%.2f grados celcius equivalen a %.2f grados fahrenheit", celcius, fahrenheit);//Se limitan los decimales a solo 2
    return 0;
}
