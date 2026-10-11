//intercambio.c - 
#include<stdio.h>

int main(void) {
    //Definición de variables
    int a, b, aux;
    
    //Inicialziación de variables
    a = 5;
    b = 9;

    //SALIDA: (Antes)
    printf("%-10s", "Antes:");
    printf("a = %d  b = %d\n", a, b);

    //PROCESO: (intercambio)
    aux = a;
    a = b;
    b = aux;

    //SALIDA: (Despues)
    printf("%-10s", "Despues:");
    printf("a = %d  b = %d\n", a, b);

    return 0;
}