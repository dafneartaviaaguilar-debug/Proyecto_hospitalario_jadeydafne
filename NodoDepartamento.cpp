#include "NodoDepartamento.h" //agregar archivo.h

//const con parametros
NodoDepartamento::NodoDepartamento(Departamento* dato)
{
	this->dato = dato;//guardar el departamento que nos dieron
	this->siguiente = NULL;//iniciar el siguiente nodo vacio
}

//DECLARAR LOS SETS
void NodoDepartamento::setDato(Departamento* dato)
{
	this->dato = dato;
}

void NodoDepartamento::setSiguiente(NodoDepartamento* siguiente)
{
	this->siguiente = siguiente;
}

//DECLARAR LOS GETS
Departamento* NodoDepartamento::getDato()
{
	return dato;
}

NodoDepartamento* NodoDepartamento::getSiguiente()
{
	return siguiente;
}
