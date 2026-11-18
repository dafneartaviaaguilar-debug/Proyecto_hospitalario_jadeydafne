#include "Puesto.h" //agregar archivo.h

//const con parametros
Puesto::Puesto(string nombre)
{
	this->nombre = nombre;//guardar el nombre que nos dieron
}

//DECLARAR LOS SETS
void Puesto::setNombre(string nombre)
{
	this->nombre = nombre;
}

//DECLARAR LOS GETS
string Puesto::getNombre()
{
	return nombre;
}
