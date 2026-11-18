#include "Empleado.h"
//const con parametros-->:-->hereda de persona dos variables 
Empleado::Empleado(string cedula, string nombre, double salarioBase,double horasExtra, double pagoHoraExtra,double bonificacionNocturna, double deducciones): Persona(cedula, nombre)
{
	//toma lo que te dieron y guardalo en la variable inicial
	this->salarioBase = salarioBase;
	this->horasExtra = horasExtra;
	this->pagoHoraExtra = pagoHoraExtra;
	this->bonificacionNocturna = bonificacionNocturna;
	this->deducciones = deducciones;
	this->perteneceAsociacion = false;
}
//destructor
Empleado::~Empleado()
{
}
//DECLARAR LOS SETS 
void Empleado::setSalarioBase(double salarioBase)
{
	this->salarioBase = salarioBase;
}

void Empleado::setHorasExtra(double horasExtra)
{
	this->horasExtra = horasExtra;
}

void Empleado::setPagoHoraExtra(double pagoHoraExtra)
{
	this->pagoHoraExtra = pagoHoraExtra;
}

void Empleado::setBonificacionNocturna(double bonificacionNocturna)
{
	this->bonificacionNocturna = bonificacionNocturna;
}

void Empleado::setDeducciones(double deducciones)
{
	this->deducciones = deducciones;
}

void Empleado::setPerteneceAsociacion(bool perteneceAsociacion)
{
	this->perteneceAsociacion = perteneceAsociacion;
}

//DELARAR LOS GETS
double Empleado::getSalarioBase()
{
	return salarioBase;
}

double Empleado::getHorasExtra()
{
	return horasExtra;
}

double Empleado::getPagoHoraExtra()
{
	return pagoHoraExtra;
}

double Empleado::getBonificacionNocturna()
{
	return bonificacionNocturna;
}

double Empleado::getDeducciones()
{
	return deducciones;
}

bool Empleado::getPerteneceAsociacion()
{
	return perteneceAsociacion;
}

//Calculo de los salarios
double Empleado::calcularSalarioBruto()//EL SALARIO total 
{
	return salarioBase + (horasExtra * pagoHoraExtra)+ bonificacionNocturna;
}

double Empleado::calcularSalarioNeto()//el salario que te llega 
{
	return calcularSalarioBruto() - deducciones;
}

//guardar el nombre del departamento
void Empleado::setNombreDepartamento(string nombre)
{
	nombreDepartamento = nombre;
}

//devolver el nombre del departamento
string Empleado::getNombreDepartamento()
{
	return nombreDepartamento;
}
