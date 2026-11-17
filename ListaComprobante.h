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
   //declarar el metodo para obtener el primer nodo
NodoComprobante* getCabeza();
private:
    NodoComprobante* cabeza;
};

#endif
