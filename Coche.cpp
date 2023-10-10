#include "Coche.h"
#include <iostream>
#include <fstream>
#include <string>


Coche::Coche() : c�digo(0), precio(0), nombre("") {}
Coche::Coche(int _c�digo, int _precio, string _nombre) : c�digo(_c�digo), precio(_precio), nombre(_nombre){}
int Coche::GetC�digo() const {
	return c�digo;
}
int Coche::GetPrecio() const {
	return precio;
}
string Coche::GetNombre() const {
	return nombre;
}

istream& operator>>(istream& in, Coche& coche)
{
	in >> coche.c�digo >> coche.precio;
	in.ignore();
	getline(in, coche.nombre);
	return in;
}
ostream& operator<<(ostream& os, const Coche& coche) {
	return os <<  coche.c�digo << " " << coche.nombre << " por " << coche.precio << " euros/dias ";
}



