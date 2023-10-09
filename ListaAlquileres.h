#pragma once
#include "Alquiler.h"
#include "ListaCoches.h"
#include <fstream>
#include <iostream>

using namespace std;

class ListaAlquileres
{
private:
	size_t numElems;
	size_t tam = numElems + 10;
	Alquiler** alquileres;
public:
	ListaAlquileres();
	ListaAlquileres(size_t numElems);
	~ListaAlquileres();

	void ordenar();
	//void mostrarAlquileres();
	void insertaAlquiler(const Alquiler& nuevoAlquiler); //no se como pillar Alquiler
	bool leeAlquileres(const ListaCoches& listaCoches); //no se como pillar ListaCoches
	
	friend ostream& operator<<(ostream& os, const ListaAlquileres& listaAlquileres);
};

