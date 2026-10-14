//areas.c - Calculo de varias áreas en una misma ejecución, eligiendo la figura en un menú.
#include <stdio.h>

//Definición de constante simbolica
#define PI 3.14159265358979

int main(void) {
    //Definición de variables
    int opcion;
    double lado, base, altura, radio;

    do //El menú se muestra al menos una vez y lo hace hasta que se introduzca 0
    {
        //ENTRADA
        printf("\n1. Cuadrado   2. Rectangulo   3. Circulo  0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        //PROCESO
        switch (opcion) {
            case 1:
            //Area de un cuadrado
            printf("Lado: ");
            scanf("%lf", &lado);
            printf("Area: %.2f", (lado*lado));
            break;

            case 2:
            //Area de un rectángulo
            printf("Base: ");
            scanf("%lf", &base);
            printf("Altura: ");
            scanf("%lf", &altura);
            printf("Area: %.2f", (base*altura));
            break;

            case 3:
            //Area de un círculo
            printf("Radio: ");
            scanf("%lf", &radio);
            printf("Area: %.2f", (PI * (radio*radio)));
            break;

            case 0:
            //Mensaje de despedida
            printf("Hasta luego");
            break;

            default:
            //Numero distinto a 0 1 2 3
            printf("Opcion invalida");
            break;
        }
    } while (opcion != 0);
    
    return 0;
}