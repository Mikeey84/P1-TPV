#include "Coche.h"
#include <iostream>
#include <fstream>
#include <string>


Coche::Coche() : código(0), precio(0), nombre("") {}
Coche::Coche(int _código, int _precio, string _nombre) : código(_código), precio(_precio), nombre(_nombre){}
int Coche::GetCódigo() const {
	return código;
}
int Coche::GetPrecio() const {
	return precio;
}
string Coche::GetNombre() const {
	return nombre;
}

istream& operator>>(istream& in, Coche& coche)
{
	in >> coche.código >> coche.precio;
	in.ignore();
	getline(in, coche.nombre);
	return in;
}
ostream& operator<<(ostream& os, const Coche& coche) {
	return os <<  coche.código << " " << coche.nombre << " por " << coche.precio << " euros/dias ";
}



