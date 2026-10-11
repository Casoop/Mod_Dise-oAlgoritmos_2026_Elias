//credito.c - AprobacionCredito Regla: capacidad de pago Y sin deudas Y (antigüedad >= 1 O fiador)
#include <stdio.h>

int main(void) {
    //Defición de variables
    double salario, cuota;
    int antiguedad;
    char respDeudas, respFiador;
    int capacidadPago, tieneDeudas, tieneFiador, aprobado; //Variables logicas

    //Incialización de variables
    capacidadPago = 0;
    tieneDeudas = 0;
    tieneFiador = 0;
    aprobado = 0;

    //ENTRADA
    printf("Salario mensual: ");
    scanf("%lf", &salario);
    printf("Cuota mensual del credito: ");
    scanf("%lf", &cuota);
    printf("Tiene deudas atrasadas? (S/N) ");
    scanf(" %c", &respDeudas);//El espacio evita la presencia de errores
    printf("Anios de antiguedad laboral: ");
    scanf("%d", &antiguedad);
    printf("Tiene fiador? (S/N) ");
    scanf(" %c", &respFiador);

    //PROCESO

    //Clasificación logica
    if (salario >= cuota * 3)
    {
        capacidadPago = 1;
    }
    
    if (respDeudas=='S' || respDeudas=='s')
    {
        tieneDeudas = 1;
    }
    
    if (respFiador=='S' || respFiador=='s')
    {
        tieneFiador = 1;
    }

    //¿Se aprueba el credito?
    if (capacidadPago == 1 && tieneDeudas == 0 && (antiguedad >= 1 || tieneFiador == 1))
    {
        aprobado = 1;
    }
    
    //SALIDA
    if (aprobado == 1)
    {
        printf("Credito aprobado");
    } else {
        printf("Credito rechazado");
    }
    
    return 0;
}