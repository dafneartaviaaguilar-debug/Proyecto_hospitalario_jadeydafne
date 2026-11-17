#include "Medico.h"

//const con parametros-->:-->hereda los datos de empleado
Medico::Medico(string cedula, string nombre, double salarioBase, double horasExtra, double pagoHoraExtra, double bonificacionNocturna, double deducciones): Empleado(cedula, nombre, salarioBase, horasExtra, pagoHoraExtra, bonificacionNocturna, deducciones)
{
}

//declarar el tipo de empleado
string Medico::obtenerTipo()
{
	return "Medico";
}
