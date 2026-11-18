#include "ComprobantePago.h"
#include <iostream>
using namespace std;

ComprobantePago::ComprobantePago(Empleado* empleado, Departamento* departamento)
{
	this->empleado = empleado;
	this->departamento = departamento;
	this->calculadoraImpuesto = NULL;
	this->calculadoraDeducciones = NULL;
}

// Constructor que recibe los calculadores mediante sus interfaces
ComprobantePago::ComprobantePago(Empleado* empleado, Departamento* departamento, IImpuestoRenta* calculadoraImpuesto, IDeduccionesSociales* calculadoraDeducciones)
{
	this->empleado = empleado;
	this->departamento = departamento;
	this->calculadoraImpuesto = calculadoraImpuesto;
	this->calculadoraDeducciones = calculadoraDeducciones;
}

void ComprobantePago::setEmpleado(Empleado* empleado)
{
	this->empleado = empleado;
}

void ComprobantePago::setDepartamento(Departamento* departamento)
{
	this->departamento = departamento;
}

// Guardar las interfaces que hacen los calculos
void ComprobantePago::setCalculadoras(IImpuestoRenta* calculadoraImpuesto, IDeduccionesSociales* calculadoraDeducciones)
{
	this->calculadoraImpuesto = calculadoraImpuesto;
	this->calculadoraDeducciones = calculadoraDeducciones;
}

Empleado* ComprobantePago::getEmpleado()
{
	return empleado;
}

Departamento* ComprobantePago::getDepartamento()
{
	return departamento;
}

void ComprobantePago::mostrarComprobante()
{
	if (empleado != NULL && departamento != NULL)
	{
		cout << "----- COMPROBANTE DE PAGO -----" << endl;
		cout << "Cedula: " << empleado->getCedula() << endl;
		cout << "Nombre: " << empleado->getNombre() << endl;
		cout << "Tipo de empleado: " << empleado->obtenerTipo() << endl;
		cout << "Departamento: " << departamento->getNombre() << endl;
		cout << "Salario bruto: " << empleado->calcularSalarioBruto() << endl;
		if (calculadoraImpuesto != NULL && calculadoraDeducciones != NULL)
		{
			double salarioBase = empleado->getSalarioBase();
			cout << "Impuesto renta: " << calculadoraImpuesto->calcularImpuestoRenta(salarioBase) << endl;
			cout << "CCSS: " << calculadoraDeducciones->calcularCCSS(salarioBase) << endl;
			cout << "IVM: " << calculadoraDeducciones->calcularIVM(salarioBase) << endl;
			cout << "Asociacion: " << calculadoraDeducciones->calcularAsociacion(salarioBase) << endl;
			cout << "ROP: " << calculadoraDeducciones->calcularROP(salarioBase) << endl;
			cout << "FCL: " << calculadoraDeducciones->calcularFCL(salarioBase) << endl;
			cout << "Deducciones: " << calculadoraDeducciones->calcularTotalDeducciones(salarioBase) << endl;
		}
		else
		{
			cout << "Deducciones: " << empleado->getDeducciones() << endl;
		}
		cout << "Salario neto: " << empleado->calcularSalarioNeto() << endl;
		cout << "-------------------------------" << endl;
	}
	else
	{
		cout << "No se puede mostrar el comprobante." << endl;
	}
}
