//texto.c - Analizar una frase

/*Qué se logra: leer una frase, mostrarla en mayúsculas y contar vocales, consonantes y dígitos.
Elementos que se practican: getchar y putchar (sesión 20), isalpha, isdigit, toupper y tolower de
ctype.h, y una función propia int esVocal(int c) que devuelve 1 o 0.*/

#include<stdio.h>   //Entradas y salidas
#include<ctype.h>   //Clasificación de caracteres

//Prototipos de funciones
int esVocal(int c); //1 o 0

int main (void) {
    //Definicion de variables
    int texto;             //Almacenara el texto a analizar
    int vocales = 0;        //Contador para cantidad de vocales
    int consonantes = 0;    //Contador para cantidad de consonantes
    int digitos = 0;        //Contador para cantidad de digitos

    //ENTRADA
    printf("Frase: ");
    texto = getchar ();     //lee un caracter

    //PROCESO
    while (texto != '\n' && texto != EOF) {
        if (isdigit (texto)) { digitos++; }
        if (esVocal (texto)) { vocales ++; }
        else { consonantes ++;}

        putchar (toupper(texto));
    }
    printf ("\nVocales: %d Consonantes: %d Digitos: %d", vocales, consonantes, digitos);
    return 0;
}

//Definición de función: esVocal
int esVocal(int c) {
    c = tolower (c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}