//temperaturas.c - Temperaturas de la semana
/*El Instituto Meteorológico registra la temperatura máxima de cada día. Escriba un programa en C que:
1. Pida la temperatura máxima de cada día de la semana, de lunes a domingo (grados C, de 0 a 45). El mensaje debe mostrar el nombre del día (Lun, Mar, …). Un dato fuera de rango muestra un mensaje y se vuelve a pedir.
2. Guarde las temperaturas en un arreglo de 7 posiciones.
3. Calcule el promedio de la semana y encuentre el día más caluroso.
4. Muestre la temperatura de cada día, el promedio (dos decimales), el día más caluroso y la lista de días que superaron el promedio con su cantidad.

Requisitos en C
Guarde los nombres de los días en un arreglo de cadenas char dias[7][4] y las temperaturas en la misma posición. Busque el mayor guardando su posición. Para los días sobre el promedio necesita recorrer el arreglo otra vez (al leer todavía no conoce el promedio).
Al inicio del archivo escriba en comentarios el enunciado, qué se logra, cómo se logra y el resultado esperado, y comente el uso de cada variable y constante. Mensajes de printf sin tildes ni ñ.*/

#include <stdio.h>  //Entradas y salidas
#include <string.h> //Manipulación de texto

//Definición de contantes
#define DIAS 7      //Cantidad maxima de de dias
#define MAXIMO 45   //Valor maximo del rango de temperaturas
#define MINIMO 0    //Valor minimo del rango de temperaturas

int main(void) {
    //Definición de variables
    //Arreglo de cadenas que permite guardar 7 nombres, de 4 caracteres + el fin de linea '/0' 
    char dias[DIAS][5] = {"Lun", "Mar", "Mie", "Jue", "Vie", "Sab", "Dom"};
    double temps[DIAS];
    int i;
    int masCaluroso;
    int cantidadDias = 0;       //Guarda la cantidad de dias que superaron el promedio
    char sobreProm[DIAS][5] = {"", "", "", "", "", "", ""};    //Guarda hasta 7 valores que llegaron a superar el promedio
    double prom = 0;

    //ENTRADA
    printf("=== Temperaturas de la semana ===\n");
    for (i = 0; i < DIAS; i++){ //ciclo for para guardar las temperaturas x dia
        do {
            printf("Temperatura del %s (0 a 45): ", dias[i]);
            scanf("%lf", &temps[i]);

            if (temps[i] < MINIMO || temps[i] > MAXIMO){//Muestra un mensaje de error si se introduce un valor menor a 0 o mayor a 45
                printf("ERROR: La temperatura introducida se encuentra fuera del rango (0-45)\n");
            }
        } while (temps[i] < MINIMO || temps[i] > MAXIMO);//Entra a un ciclo si se introduce un valor menor a 0 o mayor a 45  
    }
    
    //PROCESO
    //Determinador del mayor
    masCaluroso = 0;                            //Mas caluroso se iguala a la primera casilla
    for (i = 1; i < DIAS; i++){
        if (temps[i] > temps [masCaluroso]){    //Si la temperatura entrante es mayor a la temperatura de masCaluroso
            masCaluroso = i;                    //masCaluroso se actualiza
        }
    }
    
    //Caculadora de promedio
    for (i = 0; i < DIAS; i++){
        prom += temps[i];       //En cada ciclo suma la temperatura del dia a la variable prom
    }
    prom = prom/DIAS;
    
    //Dias sobre el promedio
    for (i = 0; i < DIAS; i++){
        if (temps [i] > prom) { //En caso de que la temperatura de un dia sea mayor al promedio
            cantidadDias ++;    //Suma la cantidad de dias sobre el promedio
            strcpy(sobreProm[i], dias[i]);
        }
    }

    //SALIDA
    printf("\n------- Reporte de la semana -------\n");
    for (i = 0; i < DIAS; i++){
        printf("%s:   %.1f C\n", dias[i], temps[i]);
    }
    printf ("Promedio: %.2f C\n", prom);
    printf ("Mas caluroso: %s (%.1f C)\n", dias[masCaluroso], temps[masCaluroso]);
    printf ("Sobre el promedio: ");
    for (i = 0; i < DIAS; i++){
        printf("%s ", sobreProm[i]);
    }
    printf ("(%d dias)", cantidadDias);
    
    return 0;
}