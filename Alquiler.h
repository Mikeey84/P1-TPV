#pragma once
#include <string>
#include "Date.h"
#include "Coche.h"
#include "ListaCoches.h"
#include <iostream>
#include <fstream>

class Alquiler
{
private:
	int d�as;
	Date fecha;
	Coche* coche;

public:
	Alquiler();
	Alquiler(Coche* coche, Date fecha, int d�as);

	Coche* getCoche() const;
	Date getFecha() const;
	int getDias() const;
	int getCoste() const;


	void leeAlquiler(const ListaCoches&);

	friend ostream& operator<<(ostream& os, const Alquiler& alquiler);

	bool operator<(const Alquiler& alquiler) const;

};

