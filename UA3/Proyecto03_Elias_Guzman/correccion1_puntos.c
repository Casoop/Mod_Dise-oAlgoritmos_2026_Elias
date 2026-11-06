#include <stdio.h>

//ERROR: (logico) no hay forma de devolver los datos al usuario
//POR QUE: al ser una variable void sin punteros ni una int con return los calculos no se regresan para el ultimo print
//CORRECCION: se añade el puntero *pPuntos para modificar la memoria de la varible puntos, y poder enviar datos desde la funcion sin utilizar return
void sumarPuntos(int puntos, int compra, int *pPuntos) {
    *pPuntos = puntos + compra / 1000;
}

int main(void) {
    int puntos = 0, compra, i;
    int *pPuntos = &puntos;
    for (i = 1; i <= 3; i++) {
        printf("Compra %d: ", i);
        //Error: gcc indica que: format '%d' expects argument of type 'int *', but argument 2 has type 'int' [-Wformat=]
        //POR QUE: esto se debe a la falta de un & antes de la variable lo que provoca que el sistema no sepa en que posicion debe guardar el dato introducido
        //CORRECCION: Agregar el & antes de compra;
        scanf("%d", &compra);
        sumarPuntos(puntos, compra, &puntos);
    }
    printf("Puntos acumulados: %d\n", *pPuntos);
    return 0;
}
