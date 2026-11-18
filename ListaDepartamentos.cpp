#include "ListaDepartamentos.h"
#include <iostream> //libreria para mostrar informacion
using namespace std;

//constructor para iniciar la lista vacia
ListaDepartamentos::ListaDepartamentos()
{
	cabeza = NULL;//iniciar la cabeza vacia
}

//destructor para liberar la memoria
ListaDepartamentos::~ListaDepartamentos()
{
	NodoDepartamento* temporal;//crear un puntero temporal
	
	while(cabeza != NULL)
	{
		temporal = cabeza;//guardar el primer nodo
		cabeza = cabeza->getSiguiente();//avanzar al siguiente nodo
		delete temporal->getDato();//liberar la memoria del departamento
		delete temporal;//liberar la memoria del nodo
	}
}

//insertar departamentos en la lista
void ListaDepartamentos::insertarDepartamento(Departamento* dato)
{
	NodoDepartamento* nuevo = new NodoDepartamento(dato);//crear un nuevo nodo con el departamento
	
	if(cabeza == NULL)
	{
		cabeza = nuevo;//si esta vacia el nuevo nodo sera el primero
	}
	else
	{
		NodoDepartamento* actual = cabeza;//comenzar desde el primer nodo
		
		while(actual->getSiguiente() != NULL)
		{
			actual = actual->getSiguiente();//avanzar al siguiente nodo
		}
		
		actual->setSiguiente(nuevo);//conectar el ultimo nodo con el nuevo
	}
}

//mostrar los departamentos de la lista
void ListaDepartamentos::mostrarDepartamentos()
{
	NodoDepartamento* actual = cabeza;//comenzar desde el primer nodo
	
	while(actual != NULL)
	{
		cout << "Departamento: " << actual->getDato()->getNombre() << endl;
		
		actual = actual->getSiguiente();//avanzar al siguiente nodo
	}
}

//comprobar si la lista esta vacia
bool ListaDepartamentos::estaVacia()
{
	return cabeza == NULL;
}

//obtener el primer nodo de la lista
NodoDepartamento* ListaDepartamentos::getCabeza()
{
	return cabeza;//devolver el primer nodo
}
