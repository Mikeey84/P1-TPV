#pragma once
#include "Alquiler.h"
#include "ListaCoches.h"
#include <fstream>
#include <iostream>

using namespace std;

class ListaAlquileres
{
private:
	int numElems;
	int tam = numElems + 10;
	Alquiler* alquiler;
public:
	ListaAlquileres();
	ListaAlquileres(Alquiler* alquiler, int cont, int tam);
	void ordenarAlquileres(int numElems);
	void mostrarAlquileres();
	void insertaAlquiler(const Alquiler& nuevoAlquiler, const ListaCoches& listaCoches); //no se como pillar Alquiler
	bool leerAlquileres(const ListaCoches& listaCoches); //no se como pillar ListaCoches
	
	friend ostream& operator<<(ostream& os, const ListaAlquileres& listaAlquileres);
};

