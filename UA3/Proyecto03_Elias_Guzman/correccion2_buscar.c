#include <stdio.h>
#include <string.h>
#define N 4

int buscar(const char nombres[][15], int n, const char buscado[]) {
    int i;
    for (i = 0; i <= n; i++)
        if (nombres[i] == buscado)
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
