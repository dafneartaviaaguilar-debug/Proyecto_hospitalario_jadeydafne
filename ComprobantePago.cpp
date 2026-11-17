#include "ComprobantePago.h"
#include <iostream>
using namespace std;

ComprobantePago::ComprobantePago(Empleado* empleado, Departamento* departamento)
{
    this->empleado = empleado;
    this->departamento = departamento;
}

void ComprobantePago::setEmpleado(Empleado* empleado)
{
    this->empleado = empleado;
}

void ComprobantePago::setDepartamento(Departamento* departamento)
{
    this->departamento = departamento;
}

Empleado* ComprobantePago::getEmpleado()
{
    return empleado;
}

Departamento* ComprobantePago::getDepartamento()
{
    return departamento;
}

void ComprobantePago::mostrarComprobante()
{
    if (empleado != NULL && departamento != NULL)
    {
        cout << "----- COMPROBANTE DE PAGO -----" << endl;
        cout << "Cedula: " << empleado->getCedula() << endl;
        cout << "Nombre: " << empleado->getNombre() << endl;
        cout << "Tipo de empleado: " << empleado->obtenerTipo() << endl;
        cout << "Departamento: " << departamento->getNombre() << endl;
        cout << "Salario bruto: " << empleado->calcularSalarioBruto() << endl;
        cout << "Deducciones: " << empleado->getDeducciones() << endl;
        cout << "Salario neto: " << empleado->calcularSalarioNeto() << endl;
        cout << "-------------------------------" << endl;
    }
    else
    {
        cout << "No se puede mostrar el comprobante." << endl;
    }
}
