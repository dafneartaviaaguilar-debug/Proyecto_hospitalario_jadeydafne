#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <string>
using namespace std;

class Archivo
{
public:
	//declarar el metodo para guardar informacion
	bool guardar(string nombreArchivo, string contenido);
	
	//declarar el metodo para leer informacion
	string leer(string nombreArchivo);
};

#endif
