#include "Alquiler.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Coche.h"



Alquiler::Alquiler() : coche(), fecha(), días() {}
Alquiler::Alquiler(Coche* _coche, Date _fecha, int _días) : coche(_coche), fecha(_fecha), días(_días){}

int Alquiler::getDias() const{
	return días;
}
int Alquiler::getCoste() const {
	return coche->GetPrecio() * días;
}
Date Alquiler::getFecha() const {
	return fecha;
}
Coche* Alquiler::getCoche() const {
	return coche;
}
ostream& operator<<(ostream& os, const Alquiler& alquiler) {
	os << alquiler.fecha << " " << alquiler.coche << alquiler.días << " dia(s) por " << alquiler.getCoste() << " euros";
 	return os;
}

