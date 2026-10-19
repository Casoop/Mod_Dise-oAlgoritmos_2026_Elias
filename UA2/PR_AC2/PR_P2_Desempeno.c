/*Una empresa evalúa a sus colaboradores en tres criterios: puntualidad, calidad y trabajo en equipo. Escriba un programa en C que:
1. Reciba el nombre del colaborador y el puntaje de cada criterio (0 a 10); un puntaje fuera de rango se vuelve a pedir. El mensaje debe mostrar el nombre del criterio.
2. Calcule el promedio y el nivel: EXCELENTE (9 o más), BUENO (7 o más, pero menos de 9) o NECESITA MEJORAR (menos de 7).
3. Indique el criterio con el puntaje más bajo y su puntaje.

Que se Logra: demostrar conocimiento sobre el uso de  arreglos de cadenas, como buscar el menor y mostrar un texto acorde al promedio
Como se Logra: Por medio del uso de arreglos, strcpy, fgets*/

/*Resultado esperado:
=== Evaluacion de desempeno ===
Nombre del colaborador: Laura Solis
Puntaje de puntualidad (0 a 10): 9
Puntaje de calidad (0 a 10): 11
 Puntaje invalido, debe estar entre 0 y 10
Puntaje de calidad (0 a 10): 8.5
Puntaje de trabajo en equipo (0 a 10): 10
Colaborador: Laura Solis
Promedio: 9.17
Nivel: EXCELENTE
Puntaje mas bajo: calidad (8.5)
*/

#include <stdio.h>  //Entradas y salidas
#include <string.h> //Nombres con espacios
#include <stdlib.h> //utilidad general

#define N 3

int main (void) {
    //Definición de variables
    char nombre[40]; //Permite guardar el nombre
    double puntaje[N]; //Arreglo para guardar puntajes
    char criterio[N] [18] = {"puntualidad", "calidad", "trabajo en equipo"}; //Muestra el criterio, con N se puede encontrar
    int i, masBajo; //i es el indicador convencional, masBajo sirve como indicador al criterio de mejor puntaje
    double menorPuntaje = 10, promedio; //Menor puntaje guardara el puntaje menor, se inicializa en 10 y si uno es menor a 10 se actualiza, promedio resultado de los 3 puntajes
    char nivel[20]; //Permitira guardar el nivel del desempeño

    //Se igualan los indicadores a 0
    i = masBajo = 0;

    //ENTRADAS
    printf("=== Evaluacion de desempeno ===\n");
    printf("Nombre del colaborador: ");
    fgets(nombre, sizeof(nombre), stdin);

    nombre [strcspn(nombre, "\n")] =  '\0';

    for (i = 0; i < N; i++){
        do
        {
            printf("Puntaje de %s (0 a 10): ", criterio[i]);
            scanf("%lf", &puntaje[i]);

            if (puntaje[i] < 0 || puntaje[i] > 10){
                printf("\tPuntaje invalido, debe estar entre 0 y 10\n");
            }   
        } while (puntaje[i] < 0 || puntaje[i] > 10);
        
        //PROCESO
        //Validacion de puntaje mas bajo
        if (puntaje[i] < menorPuntaje){ //El valor inicial es 10, el maximo, asi en caso de que entre un número menor la variable "menorPuntaje" se actualiza 
            menorPuntaje = puntaje[i]; //Actualización de mejor puntaje
            masBajo = i; //Se actualiza el indicador de donde esta el puntaje mas bajo
        }
    }
    
    //Calculo del promedio
    promedio = (puntaje[0]+puntaje[1]+puntaje[2])/3;

    //Determincion del nivel: con strcpy si el promedio llega al rango entonces se copia el texto a la variable nivel
    if (promedio >= 9){
        strcpy (nivel, "EXCELENTE"); 
    } else if (promedio >= 7 && promedio < 9) {
        strcpy (nivel, "BUENO");
    } else if (promedio < 7) {
        strcpy (nivel, "NECESITA MEJORAR");
    }
    
    //SALIDA
    printf("\nColaborador: %s\n", nombre);  //Laura Solis
    printf("Promedio: %.2f\n", promedio);   //9.17
    printf("Nivel: %s\n", nivel);           //EXELENTE
    printf("Puntaje mas bajo: %s (%.1f)", criterio[masBajo], puntaje[masBajo]); //calidad (8.5)

    return 0;
}