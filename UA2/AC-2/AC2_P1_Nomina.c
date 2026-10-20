//Problema 1 · Sistema de cálculo de nómina

/*Una empresa de consultoría necesita calcular el salario neto de sus empleados. Escriba un programa en C que:
1. Reciba el nombre completo del empleado (puede tener espacios; no se acepta un nombre vacío).
2. Reciba el salario bruto, que debe ser mayor que 0; si no, muestra un mensaje y lo vuelve a pedir.
3. Calcule los descuentos sobre el salario bruto: CAJA (9.5 %), IESS (2.5 %) e impuesto sobre la renta (10 %, solo si el salario bruto supera 800).
4. Calcule el salario neto (bruto menos todos los descuentos).
5. Muestre un comprobante con el nombre, el salario bruto, cada descuento y el salario neto, con dos decimales y los montos alineados.*/

/*Requisitos en C
Use constantes (#define o const) para las tasas y para el límite de 800, fgets para el nombre, strlen para revisar que no esté vacío y un do … while para validar el salario.*/

/*¿Que se logra?
Demostrar el domino sobre el uso de constantes, fgets, strlen y los ciclos do...while

¿Como se logra?
Usando constantes para las cajas, fgets para obtener el nombre con espacios, strlen para calidar que al menos se introdujo un caracter (nombreCompleto NO esta vacio) y 2 ciclos do.. while para validar las entradas*/

//AC2_P1_Nomina.c - Sistema de cálculo de nómina
#include<stdio.h>   //Entradas y salidas
#include<string.h>  //Manipular cadenas de texto y memoria

//Definición de constantes
#define CAJA 0.095  //9.5% de caja
#define IESS 0.025  //2.5% de IESS
#define IVA 0.10    //10% del impuesto sobre la renta
#define LIMITE 800  //Limite de 800 para el salario bruto sin que tenga que pagar el iva

int main (void){
    //Definición de variables
    char nombreCompleto[50];    //Variable con espacio para 49 caracteres + el enter
    double salarioBruto;        //Variable que permite guardar decimales para el salario bruto
    double salarioNeto;         //Variable que permite guardar decimales para el salario neto
    double cantCaja;            //Cantidad de Caja
    double cantIESS;            //Cantidad de IESS
    double cantIVA = 0;         //Cantidad del impuesto sobre la renta, se inicializa en 0 en caso de que no se aplique el iva
    
    //ENTRADA
    printf("=== Calculo de nomina ===\n");

    do {
        printf("Empleado: ");
        fgets(nombreCompleto, sizeof(nombreCompleto), stdin);   //Usar  fgets permite incluir espacios
        nombreCompleto[strcspn(nombreCompleto, "\n")] = '\0';   //Elimina el enter

        if (strlen(nombreCompleto) < 1) {
            printf("ERROR: El nombre del empleado no puede estar vacio\n");
        }
        
    } while (strlen(nombreCompleto) < 1);                       //En caso de que se introduzca menos de un caracter se entra en un bucle
    
    do {
        printf("Salario bruto: ");
        scanf("%lf", &salarioBruto);    //Dato esperado: 1000

        if (salarioBruto <= 0) {    //En caso de que Se introduzca un numero fuera del rango se muestra el mensaje de error
            printf("ERROR: El salario del empleado no puede ser menor a 1\n");
        }
        
    } while (salarioBruto <= 0);    //Permanecera en un bucle mientras se ponga un valor que no sea 1 o superior
    
    //PROCESO
    cantCaja = salarioBruto * CAJA;
    cantIESS = salarioBruto * IESS;

    if (salarioBruto > LIMITE) {    //Solo se calculara el iva en caso del que el salario bruto sea mayor a 800
        cantIVA = salarioBruto * IVA;
    }

    salarioNeto = salarioBruto - cantCaja - cantIESS - cantIVA;

    //SALIDA
    printf("\n------- Comprobante de pago -------\n");//Son 35 caracteres, se intentara acomodar la salida para no pasarse de 35
    printf("%-9s%26s\n","Empleado:",nombreCompleto);            //Dato esperado: Maria Lopez
    printf("%-14s%21.2f\n","Salario bruto:",salarioBruto);      //Dato esperado: 1000.00
    printf("%-22s%13.2f\n","Descuento CAJA (9.5%):",cantCaja);  //Dato esperado: 95.00
    printf("%-22s%13.2f\n","Descuento IESS (2.5%):",cantIESS);  //Dato esperado: 25.00
    printf("%-21s%14.2f\n","Impuesto renta (10%):",cantIVA);    //Dato esperado: 100.00
    printf("%-13s%22.2f\n","Salario neto:",salarioNeto);        //Dato esperado: 780.00
    
    return 0;
}