#include "ListaComprobantes.h"
#include <iostream>
using namespace std;

ListaComprobantes::ListaComprobantes()
{
	cabeza = NULL;
}

ListaComprobantes::~ListaComprobantes()
{
	NodoComprobante* temporal;
	
	while (cabeza != NULL)
	{
		temporal = cabeza;
		cabeza = cabeza->getSiguiente();
		delete temporal->getDato();
		delete temporal;
	}
}

void ListaComprobantes::insertarComprobante(ComprobantePago* dato)
{
	NodoComprobante* nuevo = new NodoComprobante(dato);
	
	if (cabeza == NULL)
	{
		cabeza = nuevo;
	}
	else
	{
		NodoComprobante* actual = cabeza;
		
		while (actual->getSiguiente() != NULL)
		{
			actual = actual->getSiguiente();
		}
		
		actual->setSiguiente(nuevo);
	}
}

void ListaComprobantes::mostrarComprobantes()
{
	NodoComprobante* actual = cabeza;
	
	while (actual != NULL)
	{
		actual->getDato()->mostrarComprobante();
		actual = actual->getSiguiente();
	}
}

bool ListaComprobantes::estaVacia()
{
	return cabeza == NULL;
}

//obtener el primer nodo de la lista
NodoComprobante* ListaComprobantes::getCabeza()
{
	return cabeza;//devolver el primer nodo
}
