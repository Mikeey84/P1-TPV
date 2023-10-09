#include "Coche.h"
#include <iostream>
#include <fstream>
#include <string>


Coche::Coche() : c�digo(), precio(), nombre() {}
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
	return in >> coche.c�digo >> coche.precio;
}

istream& getline(istream& in, Coche& coche)
{
	return getline(in, coche.nombre); // Utiliza getline para leer en un std::string
}
ostream& operator<<(ostream& os, const Coche& coche) {
	os << coche.c�digo << " " << coche.nombre << " por " << coche.precio << " euros/d�as ";
	return os;
}



