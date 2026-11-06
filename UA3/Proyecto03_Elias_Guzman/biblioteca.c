/*La biblioteca de un colegio necesita un sistema para controlar el préstamo de sus libros. Puede registrar hasta 5 libros. De cada libro se guarda: el código (100 a 999, no se repite), el título (una sola palabra, hasta 19 letras), los ejemplares disponibles y si el libro está activo o dado de baja. El programa inicia con 3 libros ya cargados (tabla de abajo). Debe mostrar un menú que se repite hasta elegir 0; toda opción o dato fuera de rango se vuelve a pedir.*/

/*Que se logra?
Un programa que permita el manejo del inventario de una biblioteca, dando la posibilidad de tanto añadir como desabilitar titulos, ademas de prestar y buscar los mismos.

Como se Logra?
utilizando funciones para separar y reutilizar el codigo, ciclos do while para validar la opciones ingresadas, en conjunto con if para mostrar mensajes de error en caso de ser necesario, switch para realizar acciones distintas dependiendo de la opcion ingresada por el usuario, ciclos for para recorrer arreglos en las busquedas y puntero para mover datos desde main a la funcion sin utilizar return.

Resultado esperado:

Opcion 2 -> se imprime una tabla con los libros iniciales y un mensaje que indica que hay 3 liboros activos
Opcion 1, Codigo 102 -> se indica que el codigo ya existe
Opcion 1, Codigo 104, Titulo Platero, Cantidad 25, Cantidad 2 -> al ingresar 25 pedira nuevamente la cantidad, al ingresar 2 devolvera un mensaje de confirmacion e indicara cuantos espacios para titulos hay disponibles
Opcion 3, Codigo 102 (x3) -> Indicara que tras el prestamo queda 1 ejemplar disponible, Indicara que tras el prestamo quedan 0 ejemplares disponibles, Indicara que ya no quedan ejemplares disponibles
Opcion 4, Codigo 101 -> Indicara que el quijote fue dado de baja
Opcion 5, Codigo 101 -> Indicara que no hay ningun libro activo con el codigo 101
Opcion 5, Codigo 103 -> Imprimira que el titulo cocori con 4 ejemplares disponibles esta asociado al codigo 103
Opcion 9 - > Pedira de nuevo la opcion
Opcion 2 -> imprimira una tabla inficando que al libro 102 le quedan 0 ejemplares, al libro 103 le quedan 4 ejemplares y al libro 104 le quedan 2 ejemplares. dando como resultado 3 titulos activos.*/


/*Libros cargados al iniciar:
Código      Título      Disponibles
101         Quijote     3 
102         Principito  2
103         Cocori      4*/

//Carga de librerias
#include <stdio.h>  //entradas y salidas
#include <string.h> //manipulacion de texto

//Definición de constantes
#define MAX_LIBROS 5        //Cantidad maxima espacios para libros
#define MAX_TITULO 20       //19 caracteres + el fin de linea \0
#define COD_MIN 100         //Codigo minimo
#define COD_MAX 999         //codigo maximo
#define EJEMPLARES_MAX 20   //cantidad maxima de ejemplares disponibles

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
        printf("\n<===== Biblioteca Escolar =====>\n");
        printf("1. Incluir libro\n");
        printf("2. Consultar libros\n");
        printf("3. Prestar un ejemplar\n");
        printf("4. Dar de baja un libro\n");
        printf("5. Buscar libro\n");
        printf("0. Salir\n\n");

        //Entrada de datos
        opcion = leerEntero("opcion", 0, 5); //Se envia el tipo dato que se pide, el minimo y el maximo acceptado

        if (opcion >= 3) {
            codigo = leerEntero ("codigo", COD_MIN, COD_MAX); //Se envia el tipo dato que se pide, el minimo y el maximo acceptado
            pos = buscarCodigo(cod, activos, n, codigo);

            //con vase al dato retornado se comprueba si existe
            if (pos == -1) {
                printf("No existe un libro activo con el codigo %d\n", codigo);
                continue;
            }
        }

        switch (opcion) {
            case 1:
                if (n == MAX_LIBROS){
                    printf("No se cuenta con espacio disponible para mas libros\n");
                    break;
                }
                
                //se verifica el entero codigo
                codigo = leerEntero("codigo", COD_MIN, COD_MAX);

                //En caso de que la funcion buscarCodigo tenga una salida distinta a -1 (no hay un codigo con ese numero), se imprimira un mensaje de errir para indicar que ese numero ya fue asignado
                if(buscarCodigo(cod, activos, n, codigo) != -1) {
                    printf("El codigo %d ya existe\n", codigo);
                    break;
                }

                //Entrada
                printf("Titulo (Sin espacios): ");
                scanf("%19s", titulo);
                //ERROR: a la hora de registrar la cantidad de ejemplares, como tope puse la constante MAX_LIBROS, por lo que solo se podia añadir un maximo de 5 ejemplares, al cambiarla por EJEMPLARES_MAX Se Solventa el error permitiendo guardar hasta 20 ejemplares tal como esta en las indicaciones
                cantidad = leerEntero("cantidad", 1, EJEMPLARES_MAX); //maximo 20 ejemplares

                incluir(cod, tit, disponibles, activos, &n, codigo, titulo, cantidad);

                //confirmacion
                printf("El libro ha sido incluido (%d de %d)\n", n, MAX_LIBROS); //MEJORA: se cambia el mensaje para que tenga mas coherencia con el caso de prueba
                break;
            case 2:
                consultar (cod, tit, disponibles, activos, n);
                break;
            case 3:
                //Se realiza el intento incial del prestamo
                if (prestarEjemplar(&disponibles[pos])) {
                    printf("Ejemplar prestado. Al libro %s le quedan %d ejemplar/es disponibles\n", tit[pos], disponibles[pos]); //MEJORA: se cambia el mensaje añadiendo disponibles, para que la salida quede mas completa
                } else {
                    printf("Lo sentimos, al libro %s no le quedan ejemplares disponibles, favor intente despues\n", tit[pos]); //MEJORA: se realiza un mensaje mas completo
                }
                break;
            case 4:
                darDeBaja(&activos[pos]);
                printf("El libro %s fue dado de baja\n", tit[pos]);
                break;
            case 5:
                //buscar un libro
                printf("El libro con el codigo %d: %s cuenta con %d ejemplares disponibles\n", cod[pos], tit[pos], disponibles[pos]); //MEJORA: se cambia el mensaje de salida por una version mas completa
                break;
            default:
                printf("Hasta la proxima\n");
        }
        
    } while (opcion != 0);
    
    return 0;
}

//Definición de funciones

//funcion: leerEntero
//comprueba que el numero ingresado este dentro del rango establecido
int leerEntero(const char mensaje[], int minimo, int maximo){
    //definicion de variable local
    int entrada;
    
    do { //bucle que se activara en caso de ingresar un dato erroneo
        //entrada
        printf ("Ingrese el/la %s (%d a %d): ", mensaje, minimo, maximo);
        scanf ("%d", &entrada);

        //mensaje de error que se activara en caso de ingresar un dato erroneo
        if (entrada < minimo || entrada > maximo) {
            printf("ERROR: %d se encuentra fuera del rango %d a %d\n", entrada, minimo, maximo);
        }
        
    } while (entrada < minimo || entrada > maximo);
    return entrada;
}

//funcion: buscarCodigo
//Busca el codigo con un ciclo for y comprueba que esta activo devolviendo la posicion en el arreglo, en caso contrario devuelve un -1 indicando que no fue encontrado
int buscarCodigo(const int cod[], const int activo[], int n, int codigo){
    int i;      //indice para el ciclo for
    int salida; //variable encargada de devolver los datos

    for (i = 0; i < n; i++) {
        if (cod[i] == codigo && activo[i] == 1) { //se entra al if si el codigo ingresado es igual al codigo revisado y si el codigo revisado esta disponible
            salida = i; //la salida sera el indice del codigo
            break;
        } else {
            salida = -1; //en caso contrario se devolvera un -1 indicando que no fue encontrado
        }
    }

    return salida;  //retorno de datos
}

//funcion: incluir
//Se encarga de de guardar tanto el codigo, el titulo y la cantidad
void incluir(int cod[], char tit[][MAX_TITULO], int disponibles[], int activo[], int *n, int codigo, const char titulo[], int cantidad){
    //se incluye el codigo del libro junto con su posicion en el arreglo, por medio de un puntero
    cod[*n] = codigo; //ERROR: puse cod en lugar de codigo, por lo que no se guardaria en el arreglo el codigo ingresado por el usuario
    //se incluye el nombre del libro junto con su posicion en el arreglo, por medio de un puntero
    strcpy(tit[*n], titulo);
    //se incluye la cantidad de libros disponibles junto con su posicion en el arreglo, por medio de un puntero
    disponibles[*n] = cantidad;
    //el libro se le da el estado de activo, esto en su posicion especifica del puntero
    activo[*n] = 1;
    //Se avanza una posicion dentro del indicador n
    (*n)++;
}

//funcion: consultar
//se encarga de presentar una tabla con los libros disponibles, presentando su codigo, titulo y ejemplares disponibles
void consultar(const int cod[], const char tit[][MAX_TITULO], const int disponibles[], const int activo[], int n){
    int i;              //indice para el ciclo for
    int activos = 0;    //Se incializa en 0 para evitar la presencia de errores

    //Encabezado de la tabla
    printf("\n%-8s %-14s %-12s\n", "Codigo", "Titulo", "Disponibles"); //MEJORA: para que la tabla se visualise de mejor manera, se cambio "Ejemplares Disponibles" por unicamente "Disponibles"

    for (i = 0; i < n; i++) {   //Permite recorrer el arreglo de los libros registrados
        if (activo [i] == 1) {  //esta verificación provoca que solo se impriman los libros disponibles
            printf("%-8d %-14s %-12d\n", cod[i], tit[i], disponibles[i]); //MEJORA: se adapta el espacio asignado de disponibles, pasando de 22 espacios a 12
            activos ++;         //ya que el libro si se encontraba activo se le da un + a la variable
        }
    }

    //con ayuda de la variable activos se imprime el total de libros/titulos que se encontraban activos
    printf("Cantidad de titulos activos: %d\n", activos); //MEJORA: para que tenga mayor logica con la variable utilizada se cambia titulos disponibles por titulos activos.
}

//funcion: prestarEjemplar
//se comprueba cuantos ejemplares esta a disposicion, si hay mas de 1 entonces, la cantidad de disponibles se reduce en 1
int prestarEjemplar(int *disponibles){
    int salida;
    //se comprueba si se tienen ejemplares en existencias
    if (*disponibles == 0) {
        salida = 0;
    } else {
        salida = 1;
        (*disponibles)--;//ERROR: al unicamente colocar *disponibles no se presentaba cambio alguno, sin embargo al añadir el -- se disminuye el total de libros disponibles
    }
    
    return salida;
}

//funcion: darDeBaja
//al ser llamada el puntero activo pasa a ser 0, aka inactivo
void darDeBaja(int *activo){
    //Se cambia el estado del libro por el de inactivo(0)
    *activo = 0;
}