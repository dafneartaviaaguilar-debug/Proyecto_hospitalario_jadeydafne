#ifndef ENFERMERO_H
#define ENFERMERO_H

#include "Empleado.h" //agregar archivo.h

class Enfermero : public Empleado
{
public:
	//const con parametros, hereda los datos de empleado
	Enfermero(string cedula, string nombre, double salarioBase, double horasExtra, double pagoHoraExtra, double bonificacionNocturna, double deducciones);
	
	//declarar el metodo para devolver el tipo de empleado
	string obtenerTipo();
	
};

#endif
