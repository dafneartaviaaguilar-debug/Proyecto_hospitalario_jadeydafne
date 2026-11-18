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

//agregar puestos al departamento
void Departamento::agregarPuesto(Puesto* dato)
{
	puestos.insertarPuesto(dato);//guardar el puesto en la lista
}

//mostrar los puestos del departamento
void Departamento::mostrarPuestos()
{
	puestos.mostrarPuestos();//mostrar la lista de puestos
}
//obtener el primer puesto del departamento
NodoPuesto* Departamento::getCabezaPuestos()
{
	return puestos.getCabeza();//devolver el primer nodo de la lista de puestos
}
