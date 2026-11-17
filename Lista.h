#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h" //agregar archivo.h

class Lista
{
public:
	//constructor para iniciar la lista vacia
	Lista();
	
	//destructor para liberar la memoria
	~Lista();
	
	//declarar los metodos para trabajar con la lista
	void insertarEmpleado(Empleado* dato);
	void mostrarEmpleados();
	bool estaVacia();
	//declarar el metodo para obtener el primer nodo
Nodo* getCabeza();
private:
	Nodo* cabeza;//apunta al primer nodo de la lista
};

#endif
