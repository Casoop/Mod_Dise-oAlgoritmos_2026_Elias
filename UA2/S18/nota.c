//nota.c - Validacion de nota sin repetir 

#include <stdio.h>

int main(void) {
    //Definición de variables
    double nota;

    //ENTRADA
    printf("Nota (0 a 100): ");
    scanf("%lf", &nota);

    //PROCESO
    if (nota < 0 || nota > 100)
    {
        printf ("Nota invalida: debe estar entre 0 y 100");
    } else if (nota >= 70)
    {
        printf("Aprobado");
    } else {
        printf("Reprobado");
    }
    
    return 0;
}