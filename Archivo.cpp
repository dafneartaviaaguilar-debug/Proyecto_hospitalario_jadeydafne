#include "Archivo.h"
#include <fstream> //libreria para trabajar con archivos

//guardar informacion en un archivo de texto
bool Archivo::guardar(string nombreArchivo, string contenido)
{
	ofstream archivo(nombreArchivo.c_str());//abrir el archivo para escribir
	
	if (!archivo)
	{
		return false;//si no se pudo abrir devolver falso
	}
	
	archivo << contenido;//escribir la informacion en el archivo
	
	archivo.close();//cerrar el archivo
	
	return true;//indicar que se guardo correctamente
}

//leer informacion de un archivo de texto
string Archivo::leer(string nombreArchivo)
{
	ifstream archivo(nombreArchivo.c_str());//abrir el archivo para leer
	
	string contenido = "";//guardar la informacion leida
	string linea;//guardar cada linea que se lea
	
	if (!archivo)
	{
		return contenido;//devolver el contenido vacio si no se pudo abrir
	}
	
	while (getline(archivo, linea))
	{
		contenido += linea + " ";//agregar la linea leida
	}
	
	archivo.close();//cerrar el archivo
	
	return contenido;//devolver la informacion leida
}
