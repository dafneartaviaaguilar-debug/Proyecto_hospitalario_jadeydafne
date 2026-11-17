#include "Departamento.h" //agregar archivo.h

//const con parametros
Departamento::Departamento(string nombre)
{
	this->nombre = nombre;//guardar el nombre que nos dieron
}

//DECLARAR LOS SETS
void Departamento::setNombre(string nombre)
{
	this->nombre = nombre;
}

//DECLARAR LOS GETS
string Departamento::getNombre()
{
	return nombre;
}
