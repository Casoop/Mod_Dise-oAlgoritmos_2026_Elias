//Area.c - saca el area de un rectangulo

#include <stdio.h>

int main(void){
    //Declarar variables double
    double base, altura, area;

    //Entrada de datos, lee la base = 5
    printf("Digite la base del rectagulo (cm): ");
    scanf("%lf", &base);

    //mensaje y lee la altura que va a ser = 3
    printf("Digite la altura del rectagulo (cm): ");
    scanf("%lf", &altura);

    //Proceso: multiplica y guarda el resultado = 15

    area = base * altura;

    //Salida: muestra el area con 2 decimales
    printf("El area del rectangulo es %.2f cm2\n", area);
    return 0;
}