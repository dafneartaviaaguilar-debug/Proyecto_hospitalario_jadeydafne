#ifndef NODO_H
#define NODO_H

#include "Empleado.h" //agregar archivo.h

class Nodo
{
public:
	//const con parametros, recibe un empleado
	Nodo(Empleado* dato);
	
	//declarar los setters para acceder
	void setDato(Empleado* dato);
	void setSiguiente(Nodo* siguiente);
	
	//declarar los getters para devolver info
	Empleado* getDato();
	Nodo* getSiguiente();
	
private:
	Empleado* dato;//guardar la informacion del empleado
	Nodo* siguiente;//apuntar al siguiente nodo
};

#endif
