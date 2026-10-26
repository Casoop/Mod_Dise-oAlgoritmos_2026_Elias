//notas_grupo.c - Notas del grupo
/*Un docente quiere organizar las notas de un grupo pequeño. Escriba un programa en C que:
1. Pida el nombre (una palabra) de 4 estudiantes y sus notas en 3 evaluaciones (de 0 a 100). Una nota inválida muestra un mensaje y se vuelve a pedir.
2. Guarde las notas en una matriz de 4 filas (estudiantes) por 3 columnas (evaluaciones).
3. Muestre una tabla con el nombre, las tres notas y el promedio de cada estudiante (dos decimales).
4. Muestre el promedio de cada evaluación (columna) y el estudiante con mejor promedio.
5. Al final, pida un nombre y búsquelo: si está, muestre su promedio y su condición (APROBADO con 70 o más; si no, NO APROBADO); si no está, muéstrelo con un mensaje.*/

/*Requisitos en C
Use int notas[4][3], char nombres[4][15] y float prom[4]. Recorra con for anidados: por filas para el promedio de cada estudiante y por columnas para el de cada evaluación (el acumulador se reinicia en cada fila o columna). Use (float) al dividir, strcmp para buscar y strcpy para guardar la condición.
Al inicio del archivo escriba en comentarios el enunciado, qué se logra, cómo se logra y el resultado esperado, y comente el uso de cada variable y constante. Mensajes de printf sin tildes ni ñ.*/

#include <stdio.h>  //Entradas y salidas
#include <string.h> //Manipulación de texto

//Definición de constantes
#define EST 4      //Filas de la matriz (Cantidad maxima de estudiantes)
#define EVA 3      //Columnas de la matriz (Cantidad maxima de evaluaciónes)

int main(void){
    //Definición de variables
    char nombres[EST][15];  //ARREGLO DE CADENAS para 4 nombres con 15 caracteres + el fin de linea '/0'
    float notas[EST][EVA];  //ARREGLO DE CADENAS para 4 filas de 3 evaluaciones cada una
    float prom[EST];        //Arreglo que guardara hasta 4 promedios
    float mejorProm = 0;    //Variable que guardara la nota del mejor promedio
    char mejornombre[15];   //Variable que guardara el nombre del mejor promedio
    float evaProm[EST];     //Variable que guardara el promedio de la evaluación       
    char buscado[15];       //Variable que guardara el nombre que se buscara al final del ejercicio
    int encontrado;         //Variable que guardara el indice cuando se encuentre el resultado de la busqueda
    char condicion[12];     //Variable que guardara la condición del estudiante buscado
    int f;                  //Indice para filas en el for
    int c;                  //Indice para columnas en el for
    int i;                  //Indice extra se utilizara fuera de los ciclos for

    //ENTRADA
    printf("=== Notas del grupo ===\n");
    //FOR EXTERNO: guardara los datos de 4 estudiantes (filas)
    for (f = 0; f < EST; f++) {
        printf("Nombre del estudiante %d: ", f + 1);
        scanf("%14s", nombres[f]);          //En cada ciclo se guardara un nombre hasta llegar a 4

        //FOR INTERNO: guardara los datos de 3 notas (columnas)
        for (c = 0; c < EVA; c++){
            do {
                printf("\tNota %d de %s: ", c + 1, nombres[f]);
                scanf("%f", &notas[f][c]);  //Se guardaran hasta 12 notas, 4 filas de 3 notas

                if (notas[f][c] < 0 || notas[f][c] > 100){  //If encargado de mostrar el mensaje de error si se cumplen las condiciones
                    printf("ERROR: La nota introducida se encuentra fuera del rango (0-100)\n");
                }
                
            } while (notas[f][c] < 0 || notas[f][c] > 100); //do... while encargado de entrar en un bucle hasta ingresar un dato valido (0-100)

            //Calculo del promedio x estudiante parte I
            prom[f] += notas[f][c]; //Se suman las 3 evaluaciones del estudiante
        }

        //PROCESO

        //Calculo del promedio x estudiante parte II
        prom[f] = prom[f]/3;        //Se dividen las 3 notas entre 3

        //Calculo de mejor promedio
        if (prom[f] > mejorProm){               //Si el promedio del estudiante es mayor al promedio guardado en mejor promedio:
            strcpy(mejornombre, nombres[f]);    //Se copia el nombre del estudiante a la variable mejorNombre
            mejorProm = prom[f];                //Se copia el promedio del estudiante a la variable mejorProm
        }
    }

    //Calculo del promedio x tanda de evaluación
    for (c = 0; c < EVA; c++){
        evaProm [c] = 0;    //Se inicializa la variable

        for (f = 0; f < EST; f++){
            evaProm[c]+=notas[f][c];    //Se suman las notas de los estudiantes en esta tanda
        }

        evaProm [c] = evaProm [c]/4;    //Se dividen las 4 notas entre 4
        //funcionamiento: el for anterior permite sumar por columnas permitiendo sacar el promedio por evaluancion no por estudiante
    }
    

    //SALIDA A

    //===== TABLA =====
    printf("\n%-14s%-4s%-4s%-4s%10s\n", "Nombre", "N1", "N2", "N3", "Promedio");
    //FOR EXTERNO: Controla las filas de la tabla
    for (f = 0; f < EST; f++) {
        printf("%-14s", nombres[f]);        //Imprime el nombre del estudiante

        //FOR INTERNO: imprime los datos por columnas
        for (c = 0; c < EVA; c++){
            printf("%-4.0f", notas[f][c]);    //Imprime cada una de las 3 notas del estudiante
        }
        
        printf("%10.2f", prom[f]);          //Imprime el promedio del estudiante
        printf("\n");
    }
    //FIN TABLA
    
    for (i = 0; i < EVA; i++) {//FOR que mostrara los promedios por evaluación
        printf("Promedio de la evaluacion %d: %.2f\n", i+1, evaProm[i]);
    }
    printf("Mejor promedio: %s (%.2f)", mejornombre, mejorProm);
    
    //BUSQUEDA POR NOMBRE
    printf("\n\nBuscar estudiante: ");
    scanf("%15s", buscado);

    encontrado = -1;    //Se inicializa la variable de encontrado en -1 , en caso de que no se encuentre el nombre en ninguno de las casillas se queda en 0

    for (i = 0; i < EST; i++){  //FOR encargado de recorrer los nombres
        if (strcmp(buscado, nombres[i]) == 0){  //Compara el nombre buscado entre los guardados
            encontrado = i;                     //Si es que lo encuentra encontrado se actualiza
        }
    }

    //Determinador de condicion
    if (prom [encontrado] >= 70) {
        strcpy(condicion, "APROBADO");
    } else {
        strcpy(condicion, "NO APROBADO");
    }
    
    //SALIDA B
    if (encontrado >= 0){
        printf("%s: %.2f %s", nombres[encontrado], prom[encontrado], condicion);
    } else {
        printf("%s: no esta registrado", buscado);
    }
    
    return 0;
}