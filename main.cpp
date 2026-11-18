#include <iostream>
#include <string>
#include <sstream>
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"
#include "Lista.h"
#include "Nodo.h"                   //INCLIUR TODAS LAS CLASESSSS!
#include "Departamento.h"
#include "ListaDepartamentos.h"
#include "NodoDepartamento.h"
#include "Puesto.h"
#include "ListaComprobantes.h"
#include "NodoComprobante.h"
#include "ComprobantePago.h"
#include "CalculadoraPlanilla.h"
#include "Archivo.h"

using namespace std;

int main()
{
	// Crear los objetos principales del programa
	Lista empleados;
	ListaDepartamentos departamentos;
	ListaComprobantes comprobantes;
	Archivo archivo;
	CalculadoraPlanilla* calculadora = new CalculadoraPlanilla();
	const double PAGO_POR_HORA_EXTRA = 5000;
	const double PAGO_POR_GUARDIA_NOCTURNA = 15000;
	
	// Cargar los empleados guardados
	string contenidoEmpleados = archivo.leer("empleados.txt");
	istringstream entradaEmpleados(contenidoEmpleados);
	
	int cantidadEmpleados = 0;
	
	if (entradaEmpleados >> cantidadEmpleados)
	{
		entradaEmpleados.ignore();
		
		for (int i = 0; i < cantidadEmpleados; i++)
		{
			string cedula, nombre, tipo, nombreDepartamento;
			
			double salarioBase = 0;
			double horasExtra = 0;
			double pagoHoraExtra = 0;
			double bonificacionNocturna = 0;
			double deducciones = 0;
			
			// Leer los datos del empleado
			getline(entradaEmpleados, cedula, '-');
			getline(entradaEmpleados, nombre, '-');
			getline(entradaEmpleados, tipo, '-');
			getline(entradaEmpleados, nombreDepartamento, '-');
			
			// Leer los datos numericos
			entradaEmpleados >> salarioBase;
			entradaEmpleados.ignore();
			
			entradaEmpleados >> horasExtra;
			entradaEmpleados.ignore();
			
			entradaEmpleados >> pagoHoraExtra;
			entradaEmpleados.ignore();
			
			entradaEmpleados >> bonificacionNocturna;
			entradaEmpleados.ignore();
			
			entradaEmpleados >> deducciones;
			entradaEmpleados.ignore();
			
			// Crear el empleado
			Empleado* nuevoEmpleado = NULL;
			
			if (tipo == "Medico")
			{
				deducciones = calculadora->calcularTotalDeducciones(salarioBase);
				nuevoEmpleado = new Medico(cedula, nombre, salarioBase, horasExtra, pagoHoraExtra, bonificacionNocturna, deducciones);
			}
			else if (tipo == "Enfermero")
			{
				deducciones = calculadora->calcularTotalDeducciones(salarioBase);
				nuevoEmpleado = new Enfermero(cedula, nombre, salarioBase, horasExtra, pagoHoraExtra, bonificacionNocturna, deducciones);
			}
			else if (tipo == "Administrativo")
			{
				deducciones = calculadora->calcularTotalDeducciones(salarioBase);
				nuevoEmpleado = new Administrativo(cedula, nombre, salarioBase, horasExtra, pagoHoraExtra, bonificacionNocturna, deducciones);
			}
			
			if (nuevoEmpleado != NULL)
			{
				nuevoEmpleado->setNombreDepartamento(nombreDepartamento);
				empleados.insertarEmpleado(nuevoEmpleado);
			}
		}
	}
	
	// Cargar los departamentos y sus puestos
	string contenidoDepartamentos = archivo.leer("departamentos.txt");
	istringstream entradaDepartamentos(contenidoDepartamentos);
	
	int cantidadDepartamentos = 0;
	
	if (entradaDepartamentos >> cantidadDepartamentos)
	{
		entradaDepartamentos.ignore();
		
		for (int i = 0; i < cantidadDepartamentos; i++)
		{
			string nombreDepartamento;
			int cantidadPuestos = 0;
			
			// Leer el nombre y la cantidad de puestos
			getline(entradaDepartamentos, nombreDepartamento, '-');
			
			entradaDepartamentos >> cantidadPuestos;
			entradaDepartamentos.ignore();
			
			Departamento* nuevoDepartamento = new Departamento(nombreDepartamento);
			
			// Cargar los puestos del departamento
			for (int j = 0; j < cantidadPuestos; j++)
			{
				string nombrePuesto;
				
				getline(entradaDepartamentos, nombrePuesto, '-');
				
				Puesto* nuevoPuesto = new Puesto(nombrePuesto);
				nuevoDepartamento->agregarPuesto(nuevoPuesto);
			}
			
			departamentos.insertarDepartamento(nuevoDepartamento);
		}
	}
	
	// Cargar los comprobantes guardados
	string contenidoPlanilla = archivo.leer("planilla.txt");
	istringstream entradaPlanilla(contenidoPlanilla);
	
	int cantidadComprobantes = 0;
	
	if (entradaPlanilla >> cantidadComprobantes)
	{
		entradaPlanilla.ignore();
		
		for (int i = 0; i < cantidadComprobantes; i++)
		{
			string cedula;
			
			getline(entradaPlanilla, cedula, '-');
			
			Nodo* actualEmpleado = empleados.getCabeza();
			
			// Buscar el empleado del comprobante
			while (actualEmpleado != NULL)
			{
				Empleado* empleado = actualEmpleado->getDato();
				
				if (empleado->getCedula() == cedula)
				{
					NodoDepartamento* actualDepartamento = departamentos.getCabeza();
					
					// Buscar el departamento del empleado
					while (actualDepartamento != NULL)
					{
						Departamento* departamento = actualDepartamento->getDato();
						
						if (departamento->getNombre() == empleado->getNombreDepartamento())
						{
							ComprobantePago* nuevoComprobante = new ComprobantePago(empleado, departamento, calculadora, calculadora);
							comprobantes.insertarComprobante(nuevoComprobante);
						}
						
						actualDepartamento = actualDepartamento->getSiguiente();
					}
				}
				
				actualEmpleado = actualEmpleado->getSiguiente();
			}
		}
	}
	
	cout << "Informacion cargada correctamente." << endl;
	
	// Declarar la opcion del menu
	int opcion = 0;
	
	// Mostrar el menu principal
	while (opcion != 9)
	{
		cout << "===== PLANILLA HOSPITALARIA =====" << endl;
		cout << "1. Registrar empleado" << endl;
		cout << "2. Registrar departamento" << endl;
		cout << "3. Registrar puesto" << endl;
		cout << "4. Mostrar empleados" << endl;
		cout << "5. Mostrar departamentos" << endl;
		cout << "6. Mostrar comprobantes" << endl;
		cout << "7. Generar comprobante" << endl;
		cout << "8. Guardar informacion" << endl;
		cout << "9. Salir" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, 10);
			cout << "Ingrese una opcion numerica." << endl;
			continue;
		}
		
		cout << endl;
		
		// Registrar empleado
		if (opcion == 1)
		{
			int tipo;
			string cedula, nombre, nombreDepartamento;
			
			double salarioBase, horasExtra, pagoHoraExtra;
			double bonificacionNocturna, deducciones;
			int cantidadGuardiasNocturnas;
			
			cout << "1. Medico" << endl;
			cout << "2. Enfermero" << endl;
			cout << "3. Administrativo" << endl;
			cout << "Seleccione el tipo: ";
			cin >> tipo;
			
			cout << "Ingrese la cedula: ";
			cin >> cedula;
			
			cout << "Ingrese el nombre: ";
			cin.ignore();
			getline(cin, nombre);
			
			cout << "Ingrese el salario base: ";
			cin >> salarioBase;
			
			cout << "Ingrese las horas extra: ";
			cin >> horasExtra;
			
			// El pago por hora extra ya esta definido en una constante
			pagoHoraExtra = PAGO_POR_HORA_EXTRA;
			
			cout << "Ingrese la cantidad de guardias nocturnas: ";
			cin >> cantidadGuardiasNocturnas;
			bonificacionNocturna = cantidadGuardiasNocturnas * PAGO_POR_GUARDIA_NOCTURNA;
			
			// Las deducciones se calculan automaticamente
			deducciones = calculadora->calcularTotalDeducciones(salarioBase);
			
			cout << "Ingrese el departamento: ";
			cin.ignore();
			getline(cin, nombreDepartamento);
			
			// Buscar el departamento
			NodoDepartamento* actualDepartamento = departamentos.getCabeza();
			bool encontrado = false;
			
			while (actualDepartamento != NULL)
			{
				if (actualDepartamento->getDato()->getNombre() == nombreDepartamento)
				{
					encontrado = true;
				}
				
				actualDepartamento = actualDepartamento->getSiguiente();
			}
			
			// Crear el empleado si existe el departamento
			if (encontrado == true)
			{
				Empleado* nuevoEmpleado = NULL;
				
				if (tipo == 1)
				{
					nuevoEmpleado = new Medico(cedula, nombre, salarioBase, horasExtra, pagoHoraExtra, bonificacionNocturna, deducciones);
				}
				else if (tipo == 2)
				{
					nuevoEmpleado = new Enfermero(cedula, nombre, salarioBase, horasExtra, pagoHoraExtra, bonificacionNocturna, deducciones);
				}
				else if (tipo == 3)
				{
					nuevoEmpleado = new Administrativo(cedula, nombre, salarioBase, horasExtra, pagoHoraExtra, bonificacionNocturna, deducciones);
				}
				
				if (nuevoEmpleado != NULL)
				{
					nuevoEmpleado->setNombreDepartamento(nombreDepartamento);
					empleados.insertarEmpleado(nuevoEmpleado);
					
					cout << "Empleado registrado correctamente." << endl;
				}
				else
				{
					cout << "Tipo de empleado no valido." << endl;
				}
			}
			else
			{
				cout << "El departamento no existe. Registrelo primero." << endl;
			}
		}
		
		// Registrar departamento
		else if (opcion == 2)
		{
			string nombreDepartamento;
			
			cout << "Ingrese el nombre del departamento: ";
			cin.ignore(1000, 10);
			getline(cin, nombreDepartamento);
			
			Departamento* nuevoDepartamento = new Departamento(nombreDepartamento);
			
			departamentos.insertarDepartamento(nuevoDepartamento);
			
			cout << "Departamento registrado correctamente." << endl;
		}
		
		// Registrar puesto
		else if (opcion == 3)
		{
			string nombreDepartamento;
			string nombrePuesto;
			
			cout << "Ingrese el nombre del departamento: ";
			cin.ignore();
			getline(cin, nombreDepartamento);
			
			cout << "Ingrese el nombre del puesto: ";
			getline(cin, nombrePuesto);
			
			NodoDepartamento* actual = departamentos.getCabeza();
			bool encontrado = false;
			
			while (actual != NULL)
			{
				if (actual->getDato()->getNombre() == nombreDepartamento)
				{
					Puesto* nuevoPuesto = new Puesto(nombrePuesto);
					actual->getDato()->agregarPuesto(nuevoPuesto);
					
					cout << "Puesto registrado correctamente." << endl;
					encontrado = true;
				}
				
				actual = actual->getSiguiente();
			}
			
			if (encontrado == false)
			{
				cout << "Departamento no encontrado." << endl;
			}
		}
		
		// Mostrar empleados
		else if (opcion == 4)
		{
			empleados.mostrarEmpleados();
		}
		
		// Mostrar departamentos
		else if (opcion == 5)
		{
			departamentos.mostrarDepartamentos();
		}
		
		// Mostrar comprobantes
		else if (opcion == 6)
		{
			comprobantes.mostrarComprobantes();
		}
		
		// Generar comprobante
		else if (opcion == 7)
		{
			string cedula;
			bool encontrado = false;
			
			cout << "Ingrese la cedula del empleado: ";
			cin >> cedula;
			
			Nodo* actualEmpleado = empleados.getCabeza();
			
			// Buscar el empleado
			while (actualEmpleado != NULL)
			{
				Empleado* empleado = actualEmpleado->getDato();
				
				if (empleado->getCedula() == cedula)
				{
					NodoDepartamento* actualDepartamento = departamentos.getCabeza();
					
					// Buscar el departamento del empleado
					while (actualDepartamento != NULL)
					{
						Departamento* departamento = actualDepartamento->getDato();
						
						if (departamento->getNombre() == empleado->getNombreDepartamento())
						{
						ComprobantePago* nuevoComprobante = new ComprobantePago(empleado, departamento, calculadora, calculadora);
							
							comprobantes.insertarComprobante(nuevoComprobante);
							
							nuevoComprobante->mostrarComprobante();
							
							encontrado = true;
						}
						
						actualDepartamento = actualDepartamento->getSiguiente();
					}
				}
				
				actualEmpleado = actualEmpleado->getSiguiente();
			}
			
			if (encontrado == false)
			{
				cout << "No se encontro el empleado o su departamento." << endl;
			}
		}
		
		// Guardar informacion
		else if (opcion == 8)
		{
			string datosEmpleados = "";
			string datosDepartamentos = "";
			string datosPlanilla = "";
			
			int cantidadEmpleados = 0;
			int cantidadDepartamentos = 0;
			int cantidadComprobantes = 0;
			
			// Contar empleados
			Nodo* actualEmpleado = empleados.getCabeza();
			
			while (actualEmpleado != NULL)
			{
				cantidadEmpleados++;
				actualEmpleado = actualEmpleado->getSiguiente();
			}
			
			// Guardar la cantidad de empleados
			datosEmpleados = to_string(cantidadEmpleados) + "-";
			
			// Guardar los datos de los empleados
			actualEmpleado = empleados.getCabeza();
			
			while (actualEmpleado != NULL)
			{
				Empleado* empleado = actualEmpleado->getDato();
				
				datosEmpleados += empleado->getCedula() + "-";
				datosEmpleados += empleado->getNombre() + "-";
				datosEmpleados += empleado->obtenerTipo() + "-";
				datosEmpleados += empleado->getNombreDepartamento() + "-";
				datosEmpleados += to_string(empleado->getSalarioBase()) + "-";
				datosEmpleados += to_string(empleado->getHorasExtra()) + "-";
				datosEmpleados += to_string(empleado->getPagoHoraExtra()) + "-";
				datosEmpleados += to_string(empleado->getBonificacionNocturna()) + "-";
				datosEmpleados += to_string(empleado->getDeducciones()) + "-";
				
				actualEmpleado = actualEmpleado->getSiguiente();
			}
			
			// Contar departamentos
			NodoDepartamento* actualDepartamento = departamentos.getCabeza();
			
			while (actualDepartamento != NULL)
			{
				cantidadDepartamentos++;
				actualDepartamento = actualDepartamento->getSiguiente();
			}
			
			// Guardar la cantidad de departamentos
			datosDepartamentos = to_string(cantidadDepartamentos) + "-";
			
			// Guardar los departamentos y sus puestos
			actualDepartamento = departamentos.getCabeza();
			
			while (actualDepartamento != NULL)
			{
				Departamento* departamento = actualDepartamento->getDato();
				
				datosDepartamentos += departamento->getNombre() + "-";
				
				int cantidadPuestos = 0;
				NodoPuesto* actualPuesto = departamento->getCabezaPuestos();
				
				while (actualPuesto != NULL)
				{
					cantidadPuestos++;
					actualPuesto = actualPuesto->getSiguiente();
				}
				
				datosDepartamentos += to_string(cantidadPuestos) + "-";
				
				actualPuesto = departamento->getCabezaPuestos();
				
				while (actualPuesto != NULL)
				{
					datosDepartamentos += actualPuesto->getDato()->getNombre() + "-";
					actualPuesto = actualPuesto->getSiguiente();
				}
				
				actualDepartamento = actualDepartamento->getSiguiente();
			}
			
			// Contar comprobantes
			NodoComprobante* actualComprobante = comprobantes.getCabeza();
			
			while (actualComprobante != NULL)
			{
				cantidadComprobantes++;
				actualComprobante = actualComprobante->getSiguiente();
			}
			
			// Guardar la cantidad de comprobantes
			datosPlanilla = to_string(cantidadComprobantes) + "-";
			
			// Guardar las cedulas de los comprobantes
			actualComprobante = comprobantes.getCabeza();
			
			while (actualComprobante != NULL)
			{
				datosPlanilla += actualComprobante->getDato()->getEmpleado()->getCedula() + "-";
				
				actualComprobante = actualComprobante->getSiguiente();
			}
			
			// Guardar los tres archivos
			bool empleadosGuardados = archivo.guardar("empleados.txt", datosEmpleados);
			bool departamentosGuardados = archivo.guardar("departamentos.txt", datosDepartamentos);
			bool planillaGuardada = archivo.guardar("planilla.txt", datosPlanilla);
			
			if (empleadosGuardados && departamentosGuardados && planillaGuardada)
			{
				cout << "Informacion guardada correctamente." << endl;
			}
			else
			{
				cout << "Ocurrio un error al guardar la informacion." << endl;
			}
		}
		
		// Salir del programa
		else if (opcion == 9)
		{
			cout << "Haz terminado muy bien!!!" << endl;
		}
		
		else
		{
			cout << "Opcion no valida." << endl;
		}
		
		cout << endl;
	}
	
	return 0;
}
