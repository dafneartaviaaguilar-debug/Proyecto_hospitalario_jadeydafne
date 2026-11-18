#include "CalculadoraPlanilla.h"

// Calcular el impuesto segun los tramos del archivo de salario
double CalculadoraPlanilla::calcularImpuestoRenta(double salarioBase)
{
	if (salarioBase < 922000)
	{
		return 0;
	}
	else if (salarioBase <= 1352000)
	{
		return salarioBase * 0.10;
	}
	else if (salarioBase <= 2373000)
	{
		return salarioBase * 0.15;
	}
	else
	{
		return salarioBase * 0.20;
	}
}

// Calcular CCSS
double CalculadoraPlanilla::calcularCCSS(double salarioBase)
{
	return salarioBase * 0.1083;
}

// Calcular IVM
double CalculadoraPlanilla::calcularIVM(double salarioBase)
{
	return salarioBase * 0.0433;
}

// La asociacion queda en cero porque no se dio un porcentaje fijo
double CalculadoraPlanilla::calcularAsociacion(double salarioBase)
{
	// El archivo de salario no da un porcentaje fijo de asociacion
	return salarioBase * 0 / 100;
}

// Calcular ROP
double CalculadoraPlanilla::calcularROP(double salarioBase)
{
	return salarioBase * 0.01;
}

// Calcular FCL
double CalculadoraPlanilla::calcularFCL(double salarioBase)
{
	return salarioBase * 0.015;
}

// Sumar todas las deducciones del salario base
double CalculadoraPlanilla::calcularTotalDeducciones(double salarioBase)
{
	double total = 0;
	total = calcularImpuestoRenta(salarioBase);
	total = total + calcularCCSS(salarioBase);
	total = total + calcularIVM(salarioBase);
	total = total + calcularAsociacion(salarioBase);
	total = total + calcularROP(salarioBase);
	total = total + calcularFCL(salarioBase);
	return total;
}
