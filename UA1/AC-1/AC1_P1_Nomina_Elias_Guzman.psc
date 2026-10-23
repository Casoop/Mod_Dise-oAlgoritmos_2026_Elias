Proceso AC1_P1_Nomina_Elias_Guzman
	//Definición de variables
	Definir nombre Como Caracter;
	Definir salarioB, ccss, ass, renta, salarioN Como Real;
	
	//Inicialización de variables
	renta <- 0;
	
	//Entrada de datos
	Escribir "{{{Sistema de cálculo de nómina}}}";
	Escribir "";
	Escribir "Para calcular el salario neto de su empleado, por favor ingrese:";
	Escribir "Nombre del empleado:";
	Leer nombre;
	
	Repetir //Sistema de verificación para evitar numeros negativos
		Escribir "Salario bruto:";
		Leer salarioB;
		
		si salarioB < 0 Entonces
			Escribir "Dato invalido: favor ingresar un numero positivo";
		FinSi
	Hasta Que salarioB >= 0
	
	//Proceso
	ccss <- salarioB*0.095;
	ass <- salarioB*0.025;
	
	si salarioB > 800 Entonces
		renta <- salarioB*0.10;
	FinSi
	
	salarioN <- salarioB-ccss-ass-renta;
	
	//Salida
	Escribir "";
	Escribir "--- Nómina ---";
	Escribir "Empleado: ", nombre;
	Escribir "Salario bruto: ", salarioB;
	Escribir "Descuento CCSS (9.5%): ", ccss;
	Escribir "Descuento ASS (2.5%): ", ass;
	Escribir "Descuento impuesto (10%): ", renta;
	Escribir "Salario neto: ", salarioN;
	
FinProceso
