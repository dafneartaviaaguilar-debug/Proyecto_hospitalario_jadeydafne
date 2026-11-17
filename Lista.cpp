#include "Lista.h"
#include <iostream> //libreria para mostrar informacion
using namespace std;

//constructor para iniciar la lista vacia
Lista::Lista()
{
	cabeza = NULL;//iniciar la cabeza vacia
}

//destructor para liberar la memoria
Lista::~Lista()
{
	Nodo* temporal;//crear un puntero temporal
	
	while(cabeza != NULL)
	{
		temporal = cabeza;//guardar el primer nodo
		cabeza = cabeza->getSiguiente();//avanzar al siguiente nodo
		delete temporal->getDato();//liberar la memoria del empleado
		delete temporal;//liberar la memoria del nodo
	}
}

//insertar empleados en la lista
void Lista::insertarEmpleado(Empleado* dato)
{
	Nodo* nuevo = new Nodo(dato);//crear un nuevo nodo con el empleado
	
	if(cabeza == NULL)
	{
		cabeza = nuevo;//si esta vacia el nuevo nodo sera el primero
	}
	else
	{
		Nodo* actual = cabeza;//comenzar desde el primer nodo
		
		while(actual->getSiguiente() != NULL)
		{
			actual = actual->getSiguiente();//avanzar al siguiente nodo
		}
		
		actual->setSiguiente(nuevo);//conectar el ultimo nodo con el nuevo
	}
}

//mostrar los empleados de la lista
void Lista::mostrarEmpleados()
{
	Nodo* actual = cabeza;//comenzar desde el primer nodo
	
	while(actual != NULL)
	{
		cout << "Cedula: " << actual->getDato()->getCedula() << endl;
		cout << "Nombre: " << actual->getDato()->getNombre() << endl;
		cout << "Tipo: " << actual->getDato()->obtenerTipo() << endl;
		cout << "Salario bruto: " << actual->getDato()->calcularSalarioBruto() << endl;
		cout << "Salario neto: " << actual->getDato()->calcularSalarioNeto() << endl;
		
		actual = actual->getSiguiente();//avanzar al siguiente nodo
	}
}

//comprobar si la lista esta vacia
bool Lista::estaVacia()
{
	return cabeza == NULL;
}
