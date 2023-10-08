#pragma once
#include "Alquiler.h"
#include <Windows.h>
#include <fstream>
#include <iostream>

using namespace std;

class ListaAlquileres
{
private:
	int numElems;
	int tam = numElems + 10;
	Alquiler* Alquiler;
public:
	ListaAlquileres();
	void ordenarAlquileres(int numElems);
	void mostrarAlquileres();
	void insertaAlquiler(const Alquiler&); //no se como pillar Alquiler
	bool leerAlquileres(const ListaCoches&); //no se como pillar ListaCoches
	friend ostream& operator<<(ostream& os, const ListaAlquileres& listaAlquileres);
};

