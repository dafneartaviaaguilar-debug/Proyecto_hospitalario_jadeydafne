#ifndef LISTAPUESTOS_H
#define LISTAPUESTOS_H

#include "NodoPuesto.h" //agregar archivo.h

class ListaPuestos
{
public:
	//constructor para iniciar la lista vacia
	ListaPuestos();
	
	//destructor para liberar la memoria
	~ListaPuestos();
	
	//declarar los metodos para trabajar con la lista
	void insertarPuesto(Puesto* dato);
	void mostrarPuestos();
	bool estaVacia();
	//declarar el metodo para obtener el primer nodo
	NodoPuesto* getCabeza();
	
private:
	NodoPuesto* cabeza;//apunta al primer nodo de la lista
};

#endif
