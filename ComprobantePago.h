#ifndef COMPROBANTEPAGO_H
#define COMPROBANTEPAGO_H

#include "Empleado.h"
#include "Departamento.h"
#include "CalculadoraPlanilla.h"

class ComprobantePago
{
public:
	ComprobantePago(Empleado* empleado, Departamento* departamento);
	ComprobantePago(Empleado* empleado, Departamento* departamento, IImpuestoRenta* calculadoraImpuesto, IDeduccionesSociales* calculadoraDeducciones);
	void setEmpleado(Empleado* empleado);
	void setDepartamento(Departamento* departamento);
	void setCalculadoras(IImpuestoRenta* calculadoraImpuesto, IDeduccionesSociales* calculadoraDeducciones);
	Empleado* getEmpleado();
	Departamento* getDepartamento();
	void mostrarComprobante();
	
private:
	Empleado* empleado;
	Departamento* departamento;
	IImpuestoRenta* calculadoraImpuesto;
	IDeduccionesSociales* calculadoraDeducciones;
};

#endif
