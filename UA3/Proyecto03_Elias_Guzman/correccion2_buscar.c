#include <stdio.h>
#include <string.h>
#define N 4

int buscar(const char nombres[][15], int n, const char buscado[]) {
    int i;
    //ERROR: Se sigue el ciclo for despues de recorrer el arreglo
    //POR QUE: debido a la presencia de un <= lo que hacia que se verificara hasta i = 4, en lugar de i = 3, (ya que for en este caso iria de 0 a 3)
    //CORRECCION: se cambia el i <= n por un i < n
    for (i = 0; i < n; i++)
        //ERROR: Sin importar que siempre se mostraba: No existe 
        //POR QUE: Se realizaban comparaciones con el elemento incorrecto ==
        //CORRECCION: Se cambia el igual por strcmp, de la libreria string, especifica para comparar texto
        if (strcmp(nombres[i], buscado) == 0)
            return i;
    return -1;
}

int main(void) {
    char nombres[N][15] = {"Arroz", "Frijoles", "Cafe", "Azucar"};
    double precios[N] = {1200, 1500, 3200, 900};
    char buscado[15];
    int pos;
    printf("Producto: ");
    scanf("%14s", buscado);
    pos = buscar(nombres, N, buscado);
    if (pos == -1)
        printf("No existe\n");
    else
        printf("%s cuesta %.2f\n", nombres[pos], precios[pos]);
    return 0;
}
