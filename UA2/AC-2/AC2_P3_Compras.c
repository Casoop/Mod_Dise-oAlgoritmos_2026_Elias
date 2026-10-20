//Problema 3 · Gestión de compras en una tienda

/*Una tienda de electrónica necesita procesar las compras de sus clientes. Escriba un programa en C que:
1. Reciba el nombre del cliente.
2. Permita registrar varios productos (máximo 10): nombre (puede tener espacios), precio unitario y cantidad. Después de cada producto pregunta si desea agregar otro (S/N); solo acepta S o N (mayúscula o minúscula).
3. Valide que el precio y la cantidad sean positivos.
4. Muestre el subtotal de cada producto (precio × cantidad) al ingresarlo y acumule el total.
5. Aplique el descuento según el total: menos de 100, sin descuento; de 100 a menos de 500, 5 %; de 500 a 1000, 10 %; más de 1000, 15 %.
6. Calcule el total con descuento y el impuesto (13 % sobre el total con descuento).
7. Muestre una factura con el cliente, el detalle de cada producto (nombre, precio, cantidad y subtotal), la cantidad de productos, el subtotal, el descuento, el total con descuento, el impuesto y el total a pagar.*/

/*Requisitos en C
Guarde los productos en arreglos paralelos (nombres, precios y cantidades) para poder mostrar el detalle al final con un for. Use fgets para los nombres. Recuerde descartar el Enter pendiente (getchar) antes de leer un nombre con fgets después de un scanf.*/

/*¿Que se logra?
...

¿Como se logra?
...*/

//AC2_P3_Compras.c - Gestión de compras en una tienda
#include<stdio.h>   //Entradas y salidas
#include<string.h>  //Manipular cadenas de texto y memoria

//Definición de constantes
#define N 10        //Constante para el arreglo

int main (void) {
    //Definición de variables
    char nombreCompleto[50];    //Variable con espacio para 49 caracteres + el enter
    char producto[N][40];       //Arreglo que permitira guardar hasta N nombres de productos (10) con espacio para 39 caracteres + el enter
    double precioU[N];          //Arreglo que permitira guaradar N precios unitarios (10)
    int cantidad[N];            //Arreglo que permitira guaradar N cantidades (10)
    double subtotalP[N];        //Arreglo que permitira guaradar N subtotales de 1 producto (10)
    char respuesta;             //Caracter que guardara la respuesta del usuario 'S', 's', 'N' o 'n'
    double subtotalF;           //Variable que contendra el subtotal de todos los productos (subtotal final)
    double descuento;           //Variable que contendra el descuento
    double impuesto;            //Variable que contendra el impuesto
    double total;               //Variable que contendra el total a pagar
    int i;

    //ENTRADA
    printf("=== Compra en la tienda ===");

    do {
        printf("Nombre del estudiante: ");
        fgets(nombreCompleto, sizeof(nombreCompleto), stdin);   //Usar  fgets permite incluir espacios
        nombreCompleto[strcspn(nombreCompleto, "\n")] = '\0';   //Elimina el enter

        if (strlen(nombreCompleto) < 1) {
            printf("ERROR: El nombre del cliente no puede estar vacio\n");
        }
        
    } while (strlen(nombreCompleto) < 1);       //En caso de que se introduzca menos de un caracter se entra en un bucle

    for (i = 0; i < N; i++) {
        printf("Producto %d\n", i + 1);
        printf("\tNombre: ");
        fgets(producto[i], sizeof(producto[N]), stdin);   //Usar  fgets permite incluir espacios
        producto[i][strcspn(producto[i], "\n")] = '\0';   //Elimina el enter

        do {
            printf("\tPrecio unitario: ");
            scanf("%lf", &precioU[i]);

            if (precioU[i] < 0) {
                printf("ERROR: El precio no puede ser menor una cantidad negativa\n");
            }
            
        } while (precioU[i] < 0);
        
    }
    
}