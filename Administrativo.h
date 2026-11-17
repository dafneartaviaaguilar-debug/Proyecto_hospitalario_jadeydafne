#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include "Empleado.h" //agregar archivo.h

class Administrativo : public Empleado
{
public:
	//const con parametros, hereda los datos de empleado
	Administrativo(string cedula, string nombre, double salarioBase, double horasExtra, double pagoHoraExtra, double bonificacionNocturna, double deducciones);
	
	//declarar el metodo para devolver el tipo de empleado
	string obtenerTipo();
	
};

#endif
