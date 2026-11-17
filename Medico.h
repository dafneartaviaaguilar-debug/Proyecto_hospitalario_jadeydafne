#ifndef MEDICO_H
#define MEDICO_H

#include "Empleado.h" //agregar archivo.h

class Medico : public Empleado
{
public:
	//const con parametros, hereda de empleado
	Medico(string cedula, string nombre, double salarioBase, double horasExtra, double pagoHoraExtra, double bonificacionNocturna, double deducciones);
	
	//declarar el metodo para devolver el tipo de empleado
	string obtenerTipo();
	
};

#endif
