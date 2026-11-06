#include <stdio.h>

//ERROR: (logico) no hay forma de devolver los datos al usuario
//POR QUE: al ser una variable void sin punteros ni una int con return los calculos no se regresan para el ultimo print
//Solución se cambiara la funcion sumarPuntos de void a int, se le añadira un return y se devolveran los datos a main.
int sumarPuntos(int puntos, int compra) {
    puntos = puntos + compra / 1000;
    return puntos;
}

int main(void) {
    int puntos = 0, compra, i;
    for (i = 1; i <= 3; i++) {
        printf("Compra %d: ", i);
        //Error: gcc indica que: format '%d' expects argument of type 'int *', but argument 2 has type 'int' [-Wformat=]
        //POR QUE: esto se debe a la falta de un & antes de la variable lo que provoca que el sistema no sepa en que posicion debe guardar el dato introducido
        //CORRECCION: Agregar el & antes de compra;
        scanf("%d", &compra);
        puntos = sumarPuntos(puntos, compra);
    }
    printf("Puntos acumulados: %d\n", puntos);
    return 0;
}
