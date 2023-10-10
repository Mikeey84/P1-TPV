// Marcos Perez y Miguel Angel Lopez - Grupo 10

#pragma once
#include "Coche.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class ListaCoches
{
private:
	size_t numElems;
	size_t tam = numElems + 20;
	Coche** coches;

public:
	ListaCoches();
	~ListaCoches();
	//bool leerModelos(ListaCoches& listaCoche);
	Coche* buscarCoche(int código)const;
	bool insertaCoche(const Coche&);
	friend ostream& operator<<(ostream& os, const ListaCoches& listaCoches);
	friend istream& operator>>(istream& in, ListaCoches& listaCoches);
};

