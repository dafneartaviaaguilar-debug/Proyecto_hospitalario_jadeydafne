#ifndef NODOPUESTO_H
#define NODOPUESTO_H

#include "Puesto.h" //agregar archivo.h

class NodoPuesto
{
public:
	//const con parametros, recibe un puesto
	NodoPuesto(Puesto* dato);
	
	//declarar los setters para acceder
	void setDato(Puesto* dato);
	void setSiguiente(NodoPuesto* siguiente);
	
	//declarar los getters para devolver info
	Puesto* getDato();
	NodoPuesto* getSiguiente();
	
private:
	Puesto* dato;//guardar la informacion del puesto
	NodoPuesto* siguiente;//apuntar al siguiente nodo
};

#endif
