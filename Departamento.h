#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string> //libreria
#include "ListaPuestos.h" //agregar archivo.h
using namespace std;

class Departamento
{
public:
	//const con parametros
	Departamento(string nombre);
	
	//declarar los setters para acceder
	void setNombre(string nombre);
	
	//declarar los getters para devolver info
	string getNombre();
	
	//declarar los metodos para trabajar con los puestos
	void agregarPuesto(Puesto* dato);
	void mostrarPuestos();
	//declarar el metodo para obtener el primer puesto
	NodoPuesto* getCabezaPuestos();
private:
	string nombre;//guardar el nombre del departamento
	ListaPuestos puestos;//guardar los puestos del departamento
};

#endif
