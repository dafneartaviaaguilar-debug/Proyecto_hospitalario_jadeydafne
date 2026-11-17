#include "Nodo.h" //agregar archivo.h

//const con parametros
Nodo::Nodo(Empleado* dato)
{
	this->dato = dato;//guardar el empleado que nos dieron
	this->siguiente = NULL;//iniciar el siguiente nodo vacio
}

//DECLARAR LOS SETS
void Nodo::setDato(Empleado* dato)
{
	this->dato = dato;
}

void Nodo::setSiguiente(Nodo* siguiente)
{
	this->siguiente = siguiente;
}

//DECLARAR LOS GETS
Empleado* Nodo::getDato()
{
	return dato;
}

Nodo* Nodo::getSiguiente()
{
	return siguiente;
}
