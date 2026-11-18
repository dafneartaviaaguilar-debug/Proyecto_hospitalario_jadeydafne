#ifndef LISTADEPARTAMENTOS_H
#define LISTADEPARTAMENTOS_H

#include "NodoDepartamento.h" //agregar archivo.h

class ListaDepartamentos
{
public:
	//constructor para iniciar la lista vacia
	ListaDepartamentos();
	
	//destructor para liberar la memoria
	~ListaDepartamentos();
	
	//declarar los metodos para trabajar con la lista
	void insertarDepartamento(Departamento* dato);
	void mostrarDepartamentos();
	bool estaVacia();
	//declarar el metodo para obtener el primer nodo
	NodoDepartamento* getCabeza();
private:
	NodoDepartamento* cabeza;//apunta al primer nodo de la lista
};

#endif
