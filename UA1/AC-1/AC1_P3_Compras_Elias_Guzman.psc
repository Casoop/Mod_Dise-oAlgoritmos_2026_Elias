Proceso  AC1_P3_Compras_Elias_Guzman
	//Definición de variables
	Definir nCliente, nProducto, opcion Como Caracter;
	Definir precioU, precioA, subtotal, descuento, conDescuento, impuesto, total Como Real;
	Definir cantidadP, ProductosR como Entero;
	
	//Inicialización de variables
	subtotal <- 0;
	ProductosR <- 0;
	
	//Entrada de datos
	Escribir "{{{Procesador de compras}}}";
	Escribir "";
	Escribir "Por favor ingrese:";
	Escribir "Nombre del cliente:";
	Leer nCliente;
	
	Repetir
		Escribir "Nombre del producto:";
		Leer nProducto;
		
		Repetir //validador de numeros positivos
			Escribir "Precio unitario:";
			Leer precioU;
			Escribir "Cantidad:";
			Leer cantidadP;
			
			
			si precioU < 0 o cantidadP < 0 Entonces
				Escribir "Error: Se ha ingresado un numero negativo";
			FinSi //En caso de que una o mas condiciones se cumpla se muestra el mensaje
		Hasta Que precioU > 0 y cantidadP > 0
		
		//Esta operacion permite mostrar el precio de los articulos en este bucle
		precioA <- precioU*cantidadP;
		
		//Esta operación suma los precios de los articulos de este bucle al subtotal
		subtotal <- precioA+subtotal;
		
		//Este contador permite sumar la cantidad de productos ingresados en este bucle a los productos registrados totales
		ProductosR <- ProductosR + cantidadP;
		
		Escribir nProducto, ": ", precioU, " x ", cantidadP, " = ", precioA;
		
		Repetir //validador de opciones S o N
			Escribir "¿Desea agregar otro producto? (S/N)";
			Leer opcion;
			
			si opcion <> "S" y opcion <> "s" y opcion <> "N" y opcion <> "n" entonces
				Escribir "Error: Se ha ingresado una letra distinta a S o N";
			FinSi
		Hasta Que opcion = "N" o opcion = "n" o opcion = "S" o opcion = "s"
		
	Hasta Que opcion = "N" o opcion = "n"
	
	
	//Proceso
	//Verificación para descuento
	si subtotal < 100 entonces
		descuento <- 0;
		
	Sino
		si subtotal >= 100 y subtotal < 500 entonces
			descuento <- 0.05;
			
		Sino
			si subtotal >= 500 y subtotal <= 1000 entonces
				descuento <- 0.10;
				
			Sino
				descuento <- 0.15;
			FinSi
		FinSi
	FinSi
	
	//Calculo de monto del descuento
	descuento <- descuento*subtotal;
	descuento <- redon(descuento*100)/100;//Redondear a solo 2 decimales
	
	//Calculo de total con descuento
	conDescuento <- subtotal-descuento;
	conDescuento <- redon(conDescuento*100)/100;//Redondear a solo 2 decimales
	
	//calculo de impuesto
	impuesto <- conDescuento*0.13;
	impuesto <- redon(impuesto*100)/100;//Redondear a solo 2 decimales
	
	//calculo del total
	total <- conDescuento+impuesto;
	total <- redon(total*100)/100;//Redondear a solo 2 decimales
	
	//Salida de datos
	Escribir "";
	Escribir "--- Factura ---";
	Escribir "CLIENTE: ", nCliente;
	Escribir "Productos registrados: ", ProductosR;
	Escribir "Subtotal: ", subtotal;
	Escribir "Descuento (5%): -", descuento;
	Escribir "Total con descuento: ", conDescuento;
	Escribir "Impuesto (13%): ", impuesto;
	Escribir "TOTAL A PAGAR: ", total;
	
FinProceso
