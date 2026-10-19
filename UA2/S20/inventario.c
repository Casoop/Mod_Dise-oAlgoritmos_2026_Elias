//intentario.c - inventario con arreglos paralelos

#include <stdio.h>//Entradas y salidas
#include <string.h>//comparar texto
#include <stdlib.h>//utilidad general

#define N 5

int main (void) {
    //Definición de variables
    int codigo [N] = {101, 205, 310, 412, 518}; //Codigos
    char descripcion [N] [14] = {"Arroz 2 kg", "Frijoles 1 kg", "Cafe 1 kg", "Azucar 2 kg", "Aceite 1 L"};//Descripciones de productos
    int existencias [N] = {20, 15, 12, 30, 8};//Existencias
    double precios [N] = {2400, 1800, 4500, 2100, 3200};//Precios
    int entrada, i, distinto = 0;
    double total = 0;

    
    do {
        //ENTRADA
        printf("Codigo (0 para terminar): ");
        scanf("%d", &entrada);

        //PROCESO
        for (i = 0; i < N; i++) {
            if (codigo [i] == entrada) {//Comparador, en caso de ser igual a la entrada termina el ciclo for
                break;
            } else if (codigo [i] != entrada) {//En caso de que la entrada sea distinta al codigo se suma 1 al contador "distinto"
                distinto++;
            }
        }

        //SALIDA A
        if (distinto == 5  && entrada != 0) { //Si el contador distinto llega a 5 y el codigo no es igual a 0 se imprime el mensaje de error
            printf("Codigo %d no encontrado\n", entrada);
        } else if (codigo [i] == entrada) {
        printf ("%14s: %d unidades a %.2f\n", descripcion[i], existencias[i], precios[i]);}

        distinto = 0;
    } while (entrada != 0); 

    for (i = 0; i < N; i++) {//Este for cuenta el precio total del inventario
        total += (existencias[i]*precios[i]);
    }

    printf("Valor del inventario: %.2f\n", total); 
    system("pause");
}
