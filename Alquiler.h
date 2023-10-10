// Marcos Perez y Miguel Angel Lopez - Grupo 10

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
	Coche* coche;
	int días;
	Date fecha;
	

public:
	Alquiler();
	Alquiler(Coche* coche, Date fecha, int días);

	Coche* getCoche() const;
	Date getFecha() const;
	int getDias() const;
	int getCoste() const;


	void leeAlquiler(istream& in, const ListaCoches&);

	friend ostream& operator<<(ostream& os, const Alquiler& alquiler);

	bool operator<(const Alquiler& alquiler) const;

};

