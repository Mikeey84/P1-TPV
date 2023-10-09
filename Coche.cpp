#include "Coche.h"
#include <iostream>
#include <fstream>
#include <string>


Coche::Coche() : código(), precio(), nombre() {}
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
	return in >> coche.código >> coche.precio;
}

istream& getline(istream& in, Coche& coche)
{
	return getline(in, coche.nombre); // Utiliza getline para leer en un std::string
}
ostream& operator<<(ostream& os, const Coche& coche) {
	os << coche.código << " " << coche.nombre << " por " << coche.precio << " euros/días ";
	return os;
}



