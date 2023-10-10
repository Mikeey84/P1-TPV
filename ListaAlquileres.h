#pragma once
#include "Alquiler.h"
#include "ListaCoches.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

class ListaAlquileres
{
private:
	size_t numElems = 0;
	size_t tam = numElems + 20;
	Alquiler** alquileres;
public:
	ListaAlquileres();
	ListaAlquileres(Alquiler** alquileres, size_t numElems, size_t tam);
	~ListaAlquileres();

	void ordenar();
	bool insertaAlquiler(const Alquiler& nuevoAlquiler); 
	void leeAlquileres(istream& in, const ListaCoches& listaCoches);
	
	friend ostream& operator<<(ostream& os, const ListaAlquileres& listaAlquileres);
};

