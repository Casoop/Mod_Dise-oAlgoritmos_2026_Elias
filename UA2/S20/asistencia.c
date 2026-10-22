/*Qué se logra: Mostrar la asistencia semanal de 4 estudiantes con P y A, el porcentaje de cada persona y cuántas asistieron cada día.
Elementos que se practican: Matriz de 1 y 0, arreglo de cadenas para los nombres, recorrido por filas y por columnas, ?: y casting para el porcentaje.
Resultado esperado: Ana 100%, Luis 60%, Sofia 80%, Daniel 80%; presentes por día: 3 3 4 3 3.*/

//asistencia.c - Matriz de asistencia
#include<stdio.h>   //Entradas y salidas
#include<string.h>  //Manipular cadenas de texto y memoria

//Definición de constantes
#define ESTS 4          //filas estudiantes
#define DIAS 5          //Columnas días

int main (void) {
    //Definición de variables
    //Arreglo de cadenas: una fila por nombre (hasta 7 letras + '\0')
    char nombres[ESTS][8] = {"Ana","Luis","Sofia","Daniel"};
    //Asistencia en 1 y 0
    int asistencia [ESTS][DIAS] = {{1,1,1,1,1},{1,0,1,1,0},{1,1,1,0,1},{0,1,1,1,1}};

    char condicion; //Variable que guardara P o A
    int total;      //Variable que mostrara la suma de la asistencia por dia
    int f;
    int c;

    

}