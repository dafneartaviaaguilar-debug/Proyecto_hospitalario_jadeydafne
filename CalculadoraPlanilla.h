#ifndef CALCULADORAPLANILLA_H
#define CALCULADORAPLANILLA_H

// Interfaz para calcular el impuesto sobre la renta
class IImpuestoRenta
{
public:
	virtual double calcularImpuestoRenta(double salarioBase) = 0;
};

// Interfaz para calcular las deducciones sociales
class IDeduccionesSociales
{
public:
	virtual double calcularCCSS(double salarioBase) = 0;
	virtual double calcularIVM(double salarioBase) = 0;
	virtual double calcularAsociacion(double salarioBase) = 0;
	virtual double calcularROP(double salarioBase) = 0;
	virtual double calcularFCL(double salarioBase) = 0;
	virtual double calcularTotalDeducciones(double salarioBase) = 0;
};

// La clase realiza los calculos de la planilla hospitalaria
class CalculadoraPlanilla : public IImpuestoRenta, public IDeduccionesSociales
{
public:
	// Calcular cada deduccion
	double calcularImpuestoRenta(double salarioBase);
	double calcularCCSS(double salarioBase);
	double calcularIVM(double salarioBase);
	double calcularAsociacion(double salarioBase);
	double calcularROP(double salarioBase);
	double calcularFCL(double salarioBase);
	double calcularTotalDeducciones(double salarioBase);
};

#endif
