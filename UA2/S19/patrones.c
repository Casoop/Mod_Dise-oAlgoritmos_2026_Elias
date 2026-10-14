//patrones.c - Patrones con for anidados
#include <stdio.h>

int main(void) {
    //Definición de variables
    int fila, col, cantidad, maximo = 1;
    char asterisco = '*';

    //ENTRADA
    printf("Cantidad de filas: ");
    scanf("%d", &cantidad);

    //PROCESO asteriscos
    for (fila = 1; fila <= cantidad; fila++) {             //Externo

        for (col = 1; col <= maximo; col++) {     //Interno
            printf("%c", asterisco);
        }
        
        maximo++;
        //Logica: la cantidad de columnas esta limitada por la variable maximo al final de cada ciclo se le suma 1 por lo que puede ocupar un espacio mas en cada for de las filas

        printf ("\n");                              //Fin de la fila
    }
    
    //Reset de variables
    fila = 0;
    col = 0;
    maximo = 1;

    //PROCESO números
    for (fila = 1; fila <= cantidad; fila++) {             //Externo

        for (col = 1; col <= maximo; col++) {     //Interno
            printf("%d", col); //Para hacer la secuencia numerica aprovechamos que al final de cada ciclo "for" se le suma 1 a la variable "col"
        }
        
        maximo++;
        //Logica: la cantidad de columnas esta limitada por la variable maximo al final de cada ciclo se le suma 1 por lo que puede ocupar un espacio mas en cada for de las filas

        printf ("\n");                              //Fin de la fila
    }
    return 0;
}