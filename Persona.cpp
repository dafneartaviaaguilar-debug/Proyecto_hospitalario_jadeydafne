#include "Persona.h"//agregar archivo.h

Persona::Persona(string cedula, string nombre)//const con parametros, osea las variables 
{
	this->cedula = cedula;
//toma la cedula que te dieron y guardala en la variable cedula 
	this->nombre = nombre;
}
//setters
void Persona::setCedula(string cedula)
{
	this->cedula = cedula;
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}
//getters 
string Persona::getCedula()
{
	return cedula;
}

string Persona::getNombre()
{
	return nombre;
}
