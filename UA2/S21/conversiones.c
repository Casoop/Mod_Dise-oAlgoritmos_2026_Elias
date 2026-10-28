//conversiones.c ENUNCIADO: convertir en funciones cuatro algoritmos
//Conversion de temperatura / conversion de moneda (colones por dolar)

#include <stdio.h>
#define TIPO_CAMBIO 510.0 //colones por dolar

//PROTOTIPOS DE LAS FUNCIONES
double celciusAFahrenheit(double celcius);   //Devuelve los grados F
double colonesADolares(double colones);     //devuelve los dolares
int esBisiesto(int anio);                   //1 o 0
int esNotaValida(double nota);              //1 o 0

//Funcion principal
int main(void){
    //Prueba la temperatura 77.0
    printf("25 C = %.1f F (esperado 77.0)\n", celciusAFahrenheit(25) );

    //Prueba la moneda 10.00
    printf("5100 = %.2f dolares (esperado 10.00)\n", colonesADolares(5100) );

    //Prueba anio bisiesto -> 1 Verdadero
    printf("2024 bisiesto: %d (esperado 1)\n", esBisiesto(2024) );

    //Prueba anio bisiesto -> 0 falso
    printf("1900 bisiesto: %d (esperado 0)\n", esBisiesto(1900) );
    
    //Prueba la nota invalida -> 0
    printf("Nota 105 valida: %d (esperado 0)\n", esNotaValida(105) );

    //Prueba la nota valida -> 1 verdadero
    printf("Nota 85 valida: %d (esperado 1)\n", esNotaValida(85) );
    return 0;
}

//Conversion de Temperatura
double celciusAFahrenheit(double celcius){
    return celcius * 9.0 / 5.0 + 32;
}

//Conversion de moneda
double colonesADolares(double colones){
    return colones / TIPO_CAMBIO;
}

//Anio bisiesto
int esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

//Validar nota
int esNotaValida(double nota) {
    return (nota >= 0 && nota <= 100);
}