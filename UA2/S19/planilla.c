//planilla.c - Pago semanal con horas extra de varias personas colaboradoras
#include<stdio.h>

//Definición de constantes simbólicas
#define LIMITE 48
#define RECARGO 1.5
#define CENTINELA -1 //i = valor centinela

int main(void) {
    //Definición de variables
    int cantidad, conExtra, personas; 
    double horas, tarifa, horasExtra, pago, totalPlanilla;

    //Inicialización de variables
    totalPlanilla = 0;
    conExtra = 0;
    personas = 0;//Esta variable se añade para contabilizar la cantidad de empleados, tal como en la img de referencia
    horas = 0;//Debido a los requisitos dados y para ahorrar variables horas servira para como valor centinela en el ciclo while
    
    while (horas >= 0) {
        //ENTRADA

        //Ciclo para validación
        do {
            printf("Horas de la semana (0 a 72) (-1 para terminar): ");
            scanf("%lf", &horas);

            if (horas < -1 || horas > 72)//Activa el mensaje de error en caso de salirse del rango
            {
                printf("Dato invalido, intente de nuevo\n");
            }

        } while (horas < -1 || horas > 72);//Debido a que Do-While es distinto a repetir-hasta entonces se modifico la condición
        

        
        if (horas != CENTINELA) { //El siguiente "if" se necesita para poder utilizar el -1 para terminar, sin tener que mostrar el resto de entradas
            printf("Tarifa por hora: ");
            scanf("%lf", &tarifa);

            //PROCESO
            if (horas > LIMITE) {
                horasExtra = horas - LIMITE;
                pago = LIMITE * tarifa + horasExtra * tarifa * 1.5;
                conExtra += 1;
            } else {
                pago = horas * tarifa;
            } 

            //SALIDA unitaria
            printf("Pago: %.2f\n", pago);
            personas++; //Se utiliza para llevar la cuenta de la cantidad de empleados
            totalPlanilla+=pago;
        }
    }

    //SALIDA final
    printf("Personas: %d\n", personas);
    printf("Con horas extra: %d\n", conExtra);
    printf("Total de la planilla: %.2f\n", totalPlanilla);
    return 0;
}