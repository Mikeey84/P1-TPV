// Marcos Perez y Miguel Angel Lopez - Grupo 10

#include "Alquiler.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Coche.h"

Alquiler::Alquiler() : coche(nullptr), fecha(Date()), d�as(0) {}
Alquiler::Alquiler(Coche* _coche, Date _fecha, int _d�as) : coche(_coche), fecha(_fecha), d�as(_d�as){}

int Alquiler::getDias() const{
	return d�as;
}
int Alquiler::getCoste() const {
	return coche->GetPrecio() * d�as;
}
Date Alquiler::getFecha() const {
	return fecha;
}
Coche* Alquiler::getCoche() const {
	return coche;
}
ostream& operator<<(ostream& os, const Alquiler& alquiler) {
	if (alquiler.coche == nullptr) os << alquiler.fecha << " ERROR: Coche inexistente";
	else os << alquiler.fecha << " " << *alquiler.coche << alquiler.d�as << " dia(s) por " << alquiler.getCoste() << " euros";
 	return os;
}
bool Alquiler:: operator<(const Alquiler& alquiler) const {
	return fecha< alquiler.fecha;
}
void Alquiler::leeAlquiler(istream& in , const ListaCoches& listaCoches) {
	int codigo;
	Coche* co;
	Date f;
	int d;
	in >> codigo;
	co = listaCoches.buscarCoche(codigo);
	in >> f;
	in >> d;
	*this = Alquiler(co , f, d);
}
