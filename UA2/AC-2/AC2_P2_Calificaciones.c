//Problema 2 · Validación de calificaciones estudiantiles

/*Un centro educativo necesita automatizar el cálculo de notas finales. Escriba un programa en C que:
1. Reciba el nombre completo del estudiante.
2. Reciba tres calificaciones de 0 a 100 y las guarde en un arreglo. Cada calificación fuera de rango se rechaza con un mensaje y se vuelve a pedir.
3. Calcule el promedio de las tres calificaciones y busque la calificación más alta recorriendo el arreglo.
4. Determine la condición: APROBADO si el promedio es 70 o más; EN RIESGO si es 60 o más, pero menor que 70; NO APROBADO si es menor que 60. Guarde la condición en una cadena.
5. Muestre el nombre, las tres calificaciones, el promedio (dos decimales), la calificación más alta y la condición.*/

/*Requisitos en C
Use un arreglo float notas[3] recorrido con for, un do … while para validar cada nota, constantes para los límites y strcpy para guardar la condición.*/

/*¿Que se logra?
Demostrar el domino sobre el uso de arreglos, recorridos for, ciclos do...while, contantes y strcpy

¿Como se logra?
Usando arreglos para las notas, recorridos for para guardar notas, sumarlas e imprimirlas, contantes para el limite de los arreglos, Cantidad para estar aprovado y cantidad para estar en riesgo, finalmente usando strcpy en conjunto con un if para asignar la condicion del estudiante a la variable condición*/

//AC2_P2_Calificaciones.c - Validación de calificaciones estudiantiles
#include<stdio.h>   //Entradas y salidas
#include<string.h>  //Manipular cadenas de texto y memoria

//Definición de constantes
#define APROVADO 70
#define EN_RIESGO 60
#define N 3         //Constante para el arreglo

int main (void) {
    //Definición de variables
    char nombreCompleto[50];    //Variable con espacio para 49 caracteres + el enter
    double nota[N];             //Arreglo que permitira guaradar 3 notas
    char condicion[12];         //Variable que guardara la condición del estudiante
    double promedio;            //Variable que permitira guardar el promedio de las 3 notas
    double masAlta;             //Variable que guarda la nota mas alta
    int i;

    //Inicialización de variables
    masAlta = 0;                //Se inicializa en 0 para que cuando se introduzca un valor mayor se actualice

    //ENTRADA
    printf("=== Calificaciones del estudiante ===\n");

    do {
        printf("Nombre del estudiante: ");
        fgets(nombreCompleto, sizeof(nombreCompleto), stdin);   //Usar  fgets permite incluir espacios
        nombreCompleto[strcspn(nombreCompleto, "\n")] = '\0';   //Elimina el enter

        if (strlen(nombreCompleto) < 1) {
            printf("ERROR: El nombre del estudiante no puede estar vacio\n");
        }
        
    } while (strlen(nombreCompleto) < 1);       //En caso de que se introduzca menos de un caracter se entra en un bucle
    
    for (i = 0; i < N; i++) {                   //Este ciclo for permitira guardar una nota distinta en cada ciclo
        do {
            printf("Calificacion %d (0 a 100): ", i + 1);
            scanf("%lf", &nota[i]);             //Datos esperados:  75, 82, 68 

            if (nota[i] < 0 || nota[i] > 100) { //En caso de que Se introduzca un numero fuera del rango se muestra el mensaje de error
                printf("ERROR: La calificacion del estuviante no puede ser menor a 0 o mayor a 100\n");
            }
        } while (nota[i] < 0 || nota[i] > 100); //Permanecera en un bucle mientras se ponga un valor fuera del rango 0 - 100

        if (nota[i] > masAlta) { //Si la nota que se añade en este ciclo es mayor a la anterior guardada en masAlta, la variable se actualiza
            masAlta = nota[i];
        }
    }
    
    //PROCESO
    //Calculo del promedio
    for (i = 0; i < N; i++){    //Este ciclo for permitira que en cada iteración se sume una nota al promedio
        promedio += nota[i];
    }
    
    promedio = promedio/3;      //Se termina de realizar la formula del promedio dividiendo las 3 cantidades sumadas entre 3

    //Determinador de condición
    if (promedio >= APROVADO) {
        strcpy (condicion, "APROBADO");     //En caso de ser mayor o igual a 70 copia APROBADO a la variable condicion
    } else if (promedio < APROVADO && promedio >= EN_RIESGO) {
        strcpy (condicion, "EN RIESGO");    //En caso de ser mayor a 60 y menor a 70 copia EN RIESGO a la variable condicion
    } else if (promedio < EN_RIESGO) {
        strcpy (condicion, "NO APROBADO");  //En caso de se menor a 60 copia NO APROBADO a la variable condicion
    }
    
    //SALIDA
    printf("\n------- Resultado -------\n");//Son 25 caracteres, se intentara acomodar la salida para no pasarse de 25
    printf("%-11s%14s\n","Estudiante:",nombreCompleto);             //Dato esperado: Juan Perez

    for (i = 0; i < N; i++) {               //Este ciclo for permitira imprimir una nota distinta en cada iteración
        printf("%-13s%-1d%1c%10.1f\n","Calificacion ", i+1, ':', nota[i]);   //Dato esperado: 75.0, 82.0, 68.0
    }

    printf("%-9s%16.2f\n","Promedio:", promedio);                           //Dato esperado: 75.00
    printf("%-14s%11.1f\n","Nota mas alta:", masAlta);                      //Dato esperado: 82.0
    printf("%-10s%15s\n","Condicion:",condicion);                           //Dato esperado: APROVADO

    return 0;
}