#include "NodoComprobante.h"

NodoComprobante::NodoComprobante(ComprobantePago* dato)
{
	this->dato = dato;
	siguiente = NULL;
}

void NodoComprobante::setDato(ComprobantePago* dato)
{
	this->dato = dato;
}

void NodoComprobante::setSiguiente(NodoComprobante* siguiente)
{
	this->siguiente = siguiente;
}

ComprobantePago* NodoComprobante::getDato()
{
	return dato;
}

NodoComprobante* NodoComprobante::getSiguiente()
{
	return siguiente;
}
