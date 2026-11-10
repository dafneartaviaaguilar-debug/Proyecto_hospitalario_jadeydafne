#ifndef EMPLEADO_H //evita que se recorra varias veces 
#define EMPLEADO_H

#include "Persona.h"//hereda de persona porque todo empleado sera persona y tendra nombre y cedula 

class Empleado : public Persona
{
public:
	//const con parametros dos variables heredadas 
	Empleado(string cedula, string nombre, double salarioBase,double horasExtra, double pagoHoraExtra,double bonificacionNocturna, double deducciones);
	//destructor en virtual para evitar memory leask
	virtual ~Empleado();
	
	//declarar las variables para los metodos de:
	double calcularSalarioBruto();
	double calcularSalarioNeto();
	
	//le dice a las clases hijas que deben hacerlo a su propia manera 
	virtual string obtenerTipo() = 0;
	
	//declaracion de los setters para acceder a la variable
	void setSalarioBase(double salarioBase);
	void setHorasExtra(double horasExtra);
	void setPagoHoraExtra(double pagoHoraExtra);
	void setBonificacionNocturna(double bonificacionNocturna);
	void setDeducciones(double deducciones);
	
	//declarar los getters para devolver info
	double getSalarioBase();
	double getHorasExtra();
	double getPagoHoraExtra();
	double getBonificacionNocturna();
	double getDeducciones();
	
private://nadie puede acceder
	double salarioBase;//variables iniciales 
	double horasExtra;
	double pagoHoraExtra;
	double bonificacionNocturna;
	double deducciones;
};
