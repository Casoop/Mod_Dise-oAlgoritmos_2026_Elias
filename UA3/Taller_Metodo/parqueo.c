/* Parqueo.c -  Cobro diario de un parqueo

==========================================================================

* ENUNCIADO:

Un parqueo registra los vehículos del día (de 1 a 10). De cada uno se digita la placa (una palabra), el tipo de vehículo (1 Moto 500 por hora, 2 Auto 800 por hora, 3 Buseta 1200 por hora) y las horas que estuvo (de 1 a 24); un dato inválido se vuelve a pedir. El cobro es la tarifa por las horas, pero nunca supera la tarifa máxima diaria de 6000. Mostrar una tabla con placa, horas y cobro, el total del día, el vehículo que más pagó y cuántos pagaron la tarifa máxima.

* QUÉ SE LOGRA:

Se logra desarrollar un sistema que organiza y mantiene un control sobre los usuarios de un parqueo, dando pie a una mejor organización en dicha empresa.

* CÓMO SE LOGRA:

Mediante el uso de ciclos for para registrar hasta 10 clientes, do..while para verificaciones, switch para determinar el tipo de cobro y funciones para segmentar el codigo y mantener la función principal mas ordenada.

* RESULTADO ESPERADO:

Un sistema infalible que puede mantener el funcionamiento de una empresa, en este caso, un parqueo, de manera indefinida sin presentar errores y dando resultados concisos y certeros.

========================================================================== */

#include <stdio.h>  //Entradas y salidas
#include <string.h> //Manipulación de texto

// Definición de constantes
#define TMOTO 500       //Tarifa por hora de las motos
#define TAUTO 800       //Tarifa por hora de los autos
#define TBUSETA 1200    //Tarifa por hora de las busetas
#define TMAX 6000       //Tarira maxima que puede pagar un cliente
#define MAX_V 10        //Cantidad maxima de vehiculos
#define MAX_H 24        //Cantidad maxima de horas
#define MIN_G 1         //minimo general (se usa para los vehiculos y las horas)
#define OP_MIN 0        //Minimo aceptado para las opciones
#define OP_MAX 3        //Maximo aceptado para las opciones

// Prototipo de funciones
int validacionOpcion(int minimo, int maximo);
double validacionHoras(int minimo, int maximo);
double calculoTarifa(int entrada, double tiempo);

int main(void)
{
    // Definición de variables
    int opcion;             //Entero que guarda la opcion digitada por el usuario
    double horas[MAX_V];    //Arreglo que almacena hasta 10 cantidades de horas
    char placas[MAX_V][10]; //Arreglo que almacena hasta 10 placas de 10 caracteres
    double cobro[MAX_V];    //Arreglo que almacena hasta 10 cobros distintos
    double totalDia = 0;    //Variable que guarada el pago total durante el dia
    double mayorPago = 0;   //Variable que guarada el pago maximo realizado (verificación)
    int cantidadV = 0;      //guarda la cantidad de vehiculos por dia
    int cantidadTM = 0;     //Cantidad de vehiculos que pagaron la tarifa maxima
    int i;                  //indice general
    int f;                  //indice filas
    int mayor = 0;          //indice para guardar el mayor cobro

    // ENTRADA
    printf("===== Registro de vehiculos (Parqueo) =====\n");
    for (i = 0; i < MAX_V; i++) {
        //llamada de función: validacionOpcion
        opcion = validacionOpcion(OP_MIN, OP_MAX);  //Validara opciones del 0 al 3, y retornara una opcion valida

        if (opcion == 0) {break;}                   //En caso de que la opcion retornada sea 0, rompe el ciclo for         
            
        // =========================================

        printf("Digite la placa: ");
        scanf("%9s", placas[i]);

        // =============================================
        
        //llamada de función: validacionOpcion
        horas[i] = validacionHoras(MIN_G, MAX_H);   //Validara que las horas se encuentren dentro del rango 1 a 24, y retornara una hora valida
        

        // PROCESO
        //llamada de función: calculoTarifa
        cobro[i] = calculoTarifa(opcion, horas[i]); //Calculara la tarifa final por cliente, con un tope de 6000

        // Comprobador de mayor pago/cobro
        if (i == 0 || cobro[i] > mayorPago) {
            mayorPago = cobro[i];
            mayor = i;
        }

        // vehiculos con tarifa maxima==================
        if (cobro[i] == TMAX) {cantidadTM++;}

        // ACUMULADOR total de dia==================
        totalDia += cobro[i];
        cantidadV++;
    }

    if (cantidadV > 0) {
        // SALIDA tabla con resultados
        printf("\n%-12s%-7s%-7s\n", "Placa", "Horas ", "Cobro");

        for (f = 0; f < cantidadV; f++) {
            printf("%-12s%-7.2f%-7.2f\n", placas[f], horas[f], cobro[f]);
        }

        // SALIDA
        printf("\nTotal dia: %.2f\n", totalDia);
        printf("\nEl vehiculo con placa: %s fue el que mas pago, dando un total de: %.2f\n", placas[mayor], mayorPago);
        printf("Cantidad de vehiculos que pagaron la tarifa maxima: %d\n", cantidadTM);
    }

    return 0;
}


//Definición de función: validacionOpcion
int validacionOpcion(int minimo, int maximo){
    int entrada = 0;
    
    printf("-------------------------------------------\n");
    printf("1.Moto - 500 por hora\n");
    printf("2.Auto - 800 por hora\n");
    printf("3.buseta - 1200 por hora\n");
    printf("0.Salir\n");

    do {
        printf("Ingrese el tipo de vehiculo: ");
        scanf("%d", &entrada);

        if (entrada < minimo || entrada > maximo) {
            printf("ERROR: Dato invalido, por favor ingrese una opcion (0-3)\n");
        }
    } while (entrada < minimo || entrada > maximo);

    return entrada;
}


//Definición de función: validacionHoras
double validacionHoras(int minimo, int maximo){
    double entrada = 0;
    
    do {
        printf("Ingrese la cantidad de horas: ");
        scanf("%lf", &entrada);

        if (entrada < minimo || entrada > maximo) {
            printf("ERROR: dato fuera de rango (1-24)\n");
        }
    } while (entrada < minimo || entrada > maximo);

    return entrada;
}


//Definición de función: calculoTarifa;
double calculoTarifa(int entrada, double tiempo) {
    double salida;
    
    switch (entrada) {
        case 1:
            salida = TMOTO * tiempo;
            break;

        case 2:
            salida = TAUTO * tiempo;
            break;

        default:
            salida = TBUSETA * tiempo;
            break;
    }

    // Tope de tarifa(6000)
    if (salida > TMAX) {salida = TMAX;}

    return salida;
}