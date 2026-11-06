#include <stdio.h>

void sumarPuntos(int puntos, int compra) {
    puntos = puntos + compra / 1000;
}

int main(void) {
    int puntos = 0, compra, i;
    for (i = 1; i <= 3; i++) {
        printf("Compra %d: ", i);
        scanf("%d", compra);
        sumarPuntos(puntos, compra);
    }
    printf("Puntos acumulados: %d\n", puntos);
    return 0;
}
