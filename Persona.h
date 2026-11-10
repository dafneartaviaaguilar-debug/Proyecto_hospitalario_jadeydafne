#ifndef PERSONA_H//evita que se procese mas de una vez
#define PERSONA_H

#include <string> //librería 
using namespace std;

class Persona
{
public://publico todos pueden acceder
	Persona(string cedula, string nombre);//declara las variables 
	
	void setCedula(string cedula);//declarar los metodos setters para accerder
	void setNombre(string nombre);
	
	string getCedula();//declarar los metodos getters para devolver
	string getNombre();
	
protected://protected para que las hijas puedan acceder a ella 
	string cedula;//proteger las variables iniciales 
	string nombre;
};

#endif
