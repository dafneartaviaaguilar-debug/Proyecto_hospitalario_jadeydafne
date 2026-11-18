#include "ListaPuestos.h"
#include <iostream> //libreria para mostrar informacion
using namespace std;

//constructor para iniciar la lista vacia
ListaPuestos::ListaPuestos()
{
	cabeza = NULL;//iniciar la cabeza vacia
}

//destructor para liberar la memoria
ListaPuestos::~ListaPuestos()
{
	NodoPuesto* temporal;//crear un puntero temporal
	
	while(cabeza != NULL)
	{
		temporal = cabeza;//guardar el primer nodo
		cabeza = cabeza->getSiguiente();//avanzar al siguiente nodo
		delete temporal->getDato();//liberar la memoria del puesto
		delete temporal;//liberar la memoria del nodo
	}
}

//insertar puestos en la lista
void ListaPuestos::insertarPuesto(Puesto* dato)
{
	NodoPuesto* nuevo = new NodoPuesto(dato);//crear un nuevo nodo con el puesto
	
	if(cabeza == NULL)
	{
		cabeza = nuevo;//si esta vacia el nuevo nodo sera el primero
	}
	else
	{
		NodoPuesto* actual = cabeza;//comenzar desde el primer nodo
		
		while(actual->getSiguiente() != NULL)
		{
			actual = actual->getSiguiente();//avanzar al siguiente nodo
		}
		
		actual->setSiguiente(nuevo);//conectar el ultimo nodo con el nuevo
	}
}

//mostrar los puestos de la lista
void ListaPuestos::mostrarPuestos()
{
	NodoPuesto* actual = cabeza;//comenzar desde el primer nodo
	
	while(actual != NULL)
	{
		cout << "Puesto: " << actual->getDato()->getNombre() << endl;
		
		actual = actual->getSiguiente();//avanzar al siguiente nodo
	}
}

//comprobar si la lista esta vacia
bool ListaPuestos::estaVacia()
{
	return cabeza == NULL;
}
//obtener el primer nodo de la lista
NodoPuesto* ListaPuestos::getCabeza()
{
	return cabeza;//devolver el primer nodo
}
