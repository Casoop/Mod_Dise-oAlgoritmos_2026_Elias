/*Una librería registra los libros de cada pedido. Escriba un programa en C que:
1. Lea el título de cada libro hasta que se digite FIN o fin (máximo 10 títulos). Para cada libro lea el precio y la cantidad, ambos positivos.
2. Cuente las unidades (suma de cantidades) y acumule el total de libros.
3. Aplique un descuento del 10 % si el pedido tiene 5 unidades o más.
4. Calcule el envío: 8 si el total de libros es menor que 50, 4 si es menor que 150 y gratis desde 150.
5. Calcule el impuesto (13 % del total con descuento) y el total a pagar (total − descuento + impuesto + envío).
6. Muestre el detalle de cada libro y el resumen del pedido.*/

#include <stdio.h>  //Entradas y salidas
#include <string.h> //Nombres con espacios
#include <stdlib.h> //utilidad general

#define N 10

int main(void){
    //Definición de variables
    char titulo[N][40];
    double precio[N];
    int i = 0;
    char entradaTxt[40];
    int cantidad [N];
    int filas = 0;


    //ENTRADAS
    printf("=== Pedido de la libreria ===\n");
    printf("Titulo del libro (FIN para terminar): ");
    fgets(entradaTxt, sizeof(entradaTxt), stdin);
    entradaTxt [strcspn(entradaTxt, "\n")] =  '\0';
    strcpy(titulo[i], entradaTxt);

    if (strcmp (titulo [i], "FIN") != 0 && strcmp (titulo [i], "fin") != 0) {
        printf("Precio: ");
        scanf("%lf", &precio[i]);
        printf("Cantidad: ");
        scanf("%d", &cantidad[i]);
        filas ++; //Servira como limite para el for externo, dependiendo de la cantidad de ciclos sera el numero de filas
        i++;
    }

    while (strcmp (titulo [i], "FIN") != 0 && strcmp (titulo [i], "fin") != 0 && i < N){
        printf("Titulo del libro (FIN para terminar): ");
        fgets(entradaTxt, sizeof(entradaTxt), stdin);
        entradaTxt [strcspn(entradaTxt, "\n")] =  '\0';
        strcpy(titulo[i], entradaTxt);

        if (strcmp (titulo [i], "FIN") == 0 || strcmp (titulo [i], "fin") == 0){
            break;
        }
            
        printf("Precio: ");
        scanf("%lf", &precio[i]);
        printf("Cantidad: ");
        scanf("%d", &cantidad[i]);

        filas ++; //Servira como limite para el for externo, dependiendo de la cantidad de ciclos sera el numero de filas
        i++;
    }

    printf ("%-20s%6s%5s%8s\n", "Titulo", "Precio", "Cant", "Subtotal");
    for (i = 0; i < filas; i++){
        printf("%-20s", titulo[i]);
        printf("%6.2f", precio[i]);
        printf("%5d", cantidad[i]);
        printf("%8.2f\n", precio[i] * cantidad[i]);
    }
    
    return 0;
}