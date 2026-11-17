#ifndef LISTACOMPROBANTES_H
#define LISTACOMPROBANTES_H

#include "NodoComprobante.h"

class ListaComprobantes
{
public:
    ListaComprobantes();
    ~ListaComprobantes();
    void insertarComprobante(ComprobantePago* dato);
    void mostrarComprobantes();
    bool estaVacia();

private:
    NodoComprobante* cabeza;
};

#endif
