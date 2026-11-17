#ifndef COMPROBANTEPAGO_H
#define COMPROBANTEPAGO_H

#include "Empleado.h"
#include "Departamento.h"

class ComprobantePago
{
public:
    ComprobantePago(Empleado* empleado, Departamento* departamento);
    void setEmpleado(Empleado* empleado);
    void setDepartamento(Departamento* departamento);
    Empleado* getEmpleado();
    Departamento* getDepartamento();
    void mostrarComprobante();

private:
    Empleado* empleado;
    Departamento* departamento;
};

#endif
