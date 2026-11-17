#include "Administrativo.h"

//const con parametros-->:-->hereda los datos de empleado
Administrativo::Administrativo(string cedula, string nombre, double salarioBase, double horasExtra, double pagoHoraExtra, double bonificacionNocturna, double deducciones): Empleado(cedula, nombre, salarioBase, horasExtra, pagoHoraExtra, bonificacionNocturna, deducciones)
{
}

//declarar el tipo de empleado
string Administrativo::obtenerTipo()
{
	return "Administrativo";
}
