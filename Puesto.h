#ifndef PUESTO_H
#define PUESTO_H

#include <string> //libreria
using namespace std;

class Puesto
{
public:
	//const con parametros
	Puesto(string nombre);
	
	//declarar los setters para acceder
	void setNombre(string nombre);
	
	//declarar los getters para devolver info
	string getNombre();
	
private:
	string nombre;//guardar el nombre del puesto
};

#endif
