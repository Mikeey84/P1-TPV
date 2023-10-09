#include "Alquiler.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Coche.h"



Alquiler::Alquiler() : coche(), fecha(), d�as() {}
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
	os << alquiler.fecha << " " << alquiler.coche << alquiler.d�as << " dia(s) por " << alquiler.getCoste() << " euros";
 	return os;
}

