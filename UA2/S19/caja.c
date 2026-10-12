//caja.c  - Caja registradora con menu
#include <stdio.h>

int main(void){
    //declaración de variables
    int opcion;             //Opción elegida en el menú
    int productos = 0;      //CONTADOR de productos de la venta
    double precio;          //Precio para cada producto
    double total = 0;       //ACUMULADOR de la venta

    //DO ... WHILE: El menú se muestra al menos una vez
    do
    {
        //Mostrar el menú y se lee la opción ->  1
        printf("\n1. Agregar 2. Ver total 3. Cobrar 0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion); 

        //SWITCH: (segun): salta al case o caso que coincida con la opción elegida
        switch (opcion){
            case 1:
            //Validación repite mientras el precio no sea positivo
            do
            {
                printf("Precio del producto: ");
                scanf("%lf", &precio); //-> 1500 (-200)

                if (precio <= 0){
                    printf("Precio invalido\n");
                }
                
            } while (precio <= 0);
            productos ++;        //Cuenta productos
            total += precio;     //Suma el precio
            break;               //Sale del switch
            case 2:
            //Muestra el avance -> Productos: 2 Total 4000.00
            printf("Productos: %d Total: %.2f\n", productos, total); 
            break;
            case 3:
            //Cobra y reinicia contador y acumulador
            printf("Cobrado: %.2f. Nueva venta\n", total);
            productos = 0;
            total = 0;
            break;
            case 0:
            printf("Caja Cerrada\n");
            break;
            default:
            //Ningun case coincide -> 9
            printf("Opcion invalida\n");
        }
    } while (opcion != 0);//Repita el menú mientras no se elija el 0
    return 0;
}