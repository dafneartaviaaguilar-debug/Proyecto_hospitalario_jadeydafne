#include "NodoPuesto.h" //agregar archivo.h

//const con parametros
NodoPuesto::NodoPuesto(Puesto* dato)
{
	this->dato = dato;//guardar el puesto que nos dieron
	this->siguiente = NULL;//iniciar el siguiente nodo vacio
}

//DECLARAR LOS SETS
void NodoPuesto::setDato(Puesto* dato)
{
	this->dato = dato;
}

void NodoPuesto::setSiguiente(NodoPuesto* siguiente)
{
	this->siguiente = siguiente;
}

//DECLARAR LOS GETS
Puesto* NodoPuesto::getDato()
{
	return dato;
}

NodoPuesto* NodoPuesto::getSiguiente()
{
	return siguiente;
}
