#ifndef NODODEPARTAMENTO_H
#define NODODEPARTAMENTO_H

#include "Departamento.h" //agregar archivo.h

class NodoDepartamento
{
public:
	//const con parametros, recibe un departamento
	NodoDepartamento(Departamento* dato);
	
	//declarar los setters para acceder
	void setDato(Departamento* dato);
	void setSiguiente(NodoDepartamento* siguiente);
	
	//declarar los getters para devolver info
	Departamento* getDato();
	NodoDepartamento* getSiguiente();
	
private:
	Departamento* dato;//guardar la informacion del departamento
	NodoDepartamento* siguiente;//apuntar al siguiente nodo
};

#endif
