#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string> //libreria
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
	
private:
	string nombre;//guardar el nombre del departamento
};

#endif
