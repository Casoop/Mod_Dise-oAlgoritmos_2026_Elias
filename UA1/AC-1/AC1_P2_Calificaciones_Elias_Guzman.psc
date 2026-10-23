Proceso AC1_P2_Calificaciones_Elias_Guzman
	//Definición de variables
	Definir nombre, condicion Como Caracter;
	Definir par1, par2, par3, promedio Como Real;
	
	//Entrada de datos
	Escribir "{{{Cálculo de notas finales}}}";
	Escribir "";
	Escribir "Para calcular la condición y el promedio del estudiante, por favor ingrese:";
	Escribir "Nombre del estudiante:";
	Leer nombre;
	
	Repetir //Sistema de verificación para evitar notas fuera del rango (0-100)
		Escribir "Calificación 1 (0 a 100):";
		Leer par1;
		
		Escribir "Calificación 2 (0 a 100):";
		Leer par2;
		
		Escribir "Calificación 3 (0 a 100):";
		Leer par3;
		
		si par1 < 0 o par1 > 100 o par2 < 0 o par2 > 100 o par3 < 0 o par3 > 100 Entonces
			Escribir "Dato invalido: Una o más notas se encuentran fuera del rango: 0 a 100";
		FinSi //En caso de que una o mas condiciones se cumpla se muestra el mensaje
	Hasta Que par1 >= 0 y par1 <= 100 y par2 >= 0 y par2 <= 100 y par3 >= 0 y par3 <= 100
	
	//Proceso
	//Calculo del promedio
	promedio <- (par1+par2+par3)/3;
	
	//Asignacion de condicion
	si promedio >= 70 Entonces
		condicion <- "APROBADO";
		
	Sino
		si promedio >= 60 Entonces
			condicion <- "EN RIESGO";
			
		Sino
			condicion <- "NO APROBADO";
		FinSi
	FinSi
	
	//Salida de datos
	Escribir "";
	Escribir "--- Nota final ---";
	Escribir "Estudiante: ", nombre;
	Escribir "Calificación 1: ", par1;
	Escribir "Calificación 2: ", par2;
	Escribir "Calificación 3: ", par3;
	Escribir "Promedio: ", promedio;
	Escribir "Condición: ", condicion;
	
FinProceso
