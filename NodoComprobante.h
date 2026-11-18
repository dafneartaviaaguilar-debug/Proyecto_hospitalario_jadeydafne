#ifndef NODOCOMPROBANTE_H
#define NODOCOMPROBANTE_H

#include "ComprobantePago.h"

class NodoComprobante
{
public:
	NodoComprobante(ComprobantePago* dato);
	void setDato(ComprobantePago* dato);
	void setSiguiente(NodoComprobante* siguiente);
	ComprobantePago* getDato();
	NodoComprobante* getSiguiente();
	
private:
	ComprobantePago* dato;
	NodoComprobante* siguiente;
};

#endif
