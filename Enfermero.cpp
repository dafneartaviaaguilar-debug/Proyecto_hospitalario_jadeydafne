#include "Enfermero.h"

//const con parametros-->:-->hereda los datos de empleado
Enfermero::Enfermero(string cedula, string nombre, double salarioBase, double horasExtra, double pagoHoraExtra, double bonificacionNocturna, double deducciones): Empleado(cedula, nombre, salarioBase, horasExtra, pagoHoraExtra, bonificacionNocturna, deducciones)
{
}

//declarar el tipo de empleado
string Enfermero::obtenerTipo()
{
	return "Enfermero";
}
