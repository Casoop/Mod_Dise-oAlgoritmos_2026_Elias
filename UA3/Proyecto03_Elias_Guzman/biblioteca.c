/*La biblioteca de un colegio necesita un sistema para controlar el préstamo de sus libros. Puede registrar hasta 5 libros. De cada libro se guarda: el código (100 a 999, no se repite), el título (una sola palabra, hasta 19 letras), los ejemplares disponibles y si el libro está activo o dado de baja. El programa inicia con 3 libros ya cargados (tabla de abajo). Debe mostrar un menú que se repite hasta elegir 0; toda opción o dato fuera de rango se vuelve a pedir.*/

/*Libros cargados al iniciar:
Código      Título      Disponibles
101         Quijote     3 
102         Principito  2
103         Cocori      4*/

//Carga de librerias
#include <stdio.h>  //entradas y salidas
#include <string.h> //manipulacion de texto

//Definición de constantes
#define MAX_LIBROS 5    //Cantidad maxima espacios para libros
#define MAX_TITULO 20   //19 caracteres + el fin de linea \0
#define COD_MIN 100     //Codigo minimo
#define COD_MAX 999     //codigo maximo
#define EJEMPLARES_MAX 20 //cantidad maxima de ejemplares disponibles

//Prototipado de funciones
int leerEntero(const char mensaje[], int minimo, int maximo);   //Permitira validar un nombre ingresado, ademas de cambiar de acuerdo al mensaje ingresado.
int buscarCodigo(const int cod[], const int activo[], int n, int codigo);
void incluir(int cod[], char tit[][MAX_TITULO], int disponibles[], int activo[], int *n, int codigo, const char titulo[], int cantidad);
void consultar(const int cod[], const char tit[][MAX_TITULO], const int disponibles[], const int activo[], int n);
int prestarEjemplar(int *disponibles);
void darDeBaja(int *activo);


//funcion principal: main
int main (void) {
    //Inicialización de variables
    int cod[MAX_LIBROS] = {101, 102, 103};  //arreglo que permitira guardar hasta 5 codigos
    char tit [MAX_LIBROS][MAX_TITULO] = {"Quijote","Principito","Cocori"};  //arreglo que permitita guardar hasta 5 titulos de 19 caracteres + el salto de linea
    int disponibles[MAX_LIBROS] = {3, 2, 4};    //arreglo que permitira guardar las cantidades de 5 libros distintos
    int activos[MAX_LIBROS] = {1, 1, 1};        //arreglo que guardara los estados de 5 libros 1 para activos y 0 para inactivos
    int n = 3;
    int opcion, codigo, pos, cantidad;
    char titulo[MAX_TITULO];                    //variable que guardara el titulo de 1 libro de maximo 19 caracteres + el salto de linea \0

    //Bucle para el menú se mantendra hasta ingresar 0
    do {
        //Encabezado / menú
        printf("<===== Biblioteca Escolar =====>\n");
        printf("1. Incluir libro\n");
        printf("2. Consultar libros\n");
        printf("3. Prestar un ejemplar\n");
        printf("4. Dar de baja un libro\n");
        printf("5. Buscar libro\n");
        printf("0. Salir\n");

        //Entrada de datos
        opcion = leerEntero("opcion", 0, 5); //Se envia el tipo dato que se pide, el minimo y el maximo acceptado

        if (opcion >= 3) {
            codigo = leerEntero ("codigo", COD_MIN, COD_MAX); //Se envia el tipo dato que se pide, el minimo y el maximo acceptado
            pos = buscarCodigo(cod, activos, n, codigo);

            //con vase al dato retornado se comprueba si existe
            if (pos == -1) {
                printf("No existe un libro activo con el codigo %d", codigo);
                continue;
            }
        }

        switch (opcion) {
            case 1:
                if (n == MAX_LIBROS){
                    printf("No se cuenta con espacio disponible para mas libros\n");
                    break;
                }
                
                //lee codigo como entero
                codigo = leerEntero("Codigo", COD_MIN, COD_MAX);

                //Revisa si el codigo existe
                if(buscarCodigo(cod, activos, n, codigo) != -1) {
                    printf("El codigo %d ya existe\n", codigo);
                    break;
                }

                //Entrada
                printf("Titulo (Sin espacios): ");
                scanf("%19s", titulo);
                cantidad = leerEntero("cantidad", 1, MAX_LIBROS); //maximo 20

                incluir(cod, tit, disponibles, activos, &n, codigo, titulo, cantidad);

                //confirmacion
                printf("Libro %d de % d incluido\n", n, MAX_LIBROS);
                break;
            case 2:
                consultar (cod, tit, disponibles, activos, n);
                break;
            case 3:
                //Se realiza el intento incial del prestamo
                if (prestarEjemplar(&disponibles[pos])) {
                    printf("Ejemplar prestado. Al libro %s le quedan %d ejemplares\n", tit[pos], disponibles[pos]);
                } else {
                    printf("Al libro %s no le quedan ejemplares\n", tit[pos]);
                }
                break;
            case 4:
                darDeBaja(&activos[pos]);
                printf("El libro %s fue dado de baja\n", tit[pos]);
                break;
            case 5:
                //buscar un libro
                printf("%d %s: %d disponibles\n", codigo, titulo, cantidad);
                break;
            default:
                printf("Hasta la proxima\n");
        }
        
    } while (opcion != 0);
    
    return 0;
}

//Definición de funciones

//funcion: leerEntero
leerEntero(const char mensaje[], int minimo, int maximo){
    //definicion de variable
    int entrada;
    
    do { //bucle que se activara en caso de ingresar un dato erroneo
        //entrada
        printf ("Ingrese el/la %s (%d a %d): ", mensaje, minimo, maximo);
        scanf ("%d", &entrada);

        //mensaje de error que se activara en caso de ingresar un dato erroneo
        if (entrada < minimo || entrada > maximo) {
            printf("ERROR: %d se encuentra fuera del rango %d - %d\n", entrada, minimo, maximo);
        }
        
    } while (entrada < minimo || entrada > maximo);
    return entrada;
}

//funcion: buscarCodigo
int buscarCodigo(const int cod[], const int activo[], int n, int codigo){
    int i;      //indice para el ciclo for
    int salida; //variable encargada de devolver los datos

    for (i = 0; i < n; i++) {
        if (cod[i] == codigo && activo[i] == 1) {   //si el codigo ingresado es igual al codigo revisado y si el codigo revisado esta disponible
            salida = i; //la salida sera el indice del codigo
            break;
        } else {
            salida = -1; //en caso contrario se devolvera un -1 indicando que no fue encontrado
        }
    }

    return salida;  //retorno de datos
}

//funcion: incluir
void incluir(int cod[], char tit[][MAX_TITULO], int disponibles[], int activo[], int *n, int codigo, const char titulo[], int cantidad){
    //se incluye el codigo del libro junto con su posicion en el arreglo, por medio de un puntero
    cod[*n] = cod;
    //se incluye el nombre del libro junto con su posicion en el arreglo, por medio de un puntero
    strcpy(tit[*n], titulo);
    //se incluye la cantidad de libros disponibles junto con su posicion en el arreglo, por medio de un puntero
    disponibles[*n] = cantidad;
    //el libro se le da el estado de activo, esto en su posicion especifica del puntero
    activo[*n] = 1;
    //Se avanza una posicion dentro del indicador n
    (*n)++;
}

//funcion: 
void consultar(const int cod[], const char tit[][MAX_TITULO], const int disponibles[], const int activo[], int n){
    int i;              //indice para el ciclo for
    int activos = 0;    //Se incializa en 0 para evitar la presencia de errores

    //Encabezado de la tabla
    printf("%-8s %-14s %24s", "Codigo", "Titulo", "Ejemplares Disponibles");

    for (i = 0; i < n; i++) {   //Permite recorrer el arreglo de los libros registrados
        if (activo [i] == 1) {  //esta verificación provoca que solo se impriman los libros disponibles
            printf("%-8d %-14s %24d", cod[i], tit[i], disponibles[i]);
            activos ++;         //ya que el libro si se encontraba activo se le da un + a la variable
        }
    }

    //con ayuda de la variable activos se imprime el total de libros/titulos que se encontraban disponibles
    printf("Cantidad de titulos disponibles: %d", disponibles);
}

//funcion: prestarEjemplar
int prestarEjemplar(int *disponibles){
    int salida;
    //se comprueba si se tienen ejemplares en existencias
    if (*disponibles == 0) {
        salida = 0;
    } else {
        salida = 1;
        (*disponibles);
    }
    return salida;
}

//funcion: darDeBaja
void darDeBaja(int *activo){
    //Se cambia el estado del libro por el de inactivo(0)
    *activo = 0;
}