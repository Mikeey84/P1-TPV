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
	size_t tam = numElems + 10;
	Coche** coches;

public:
	ListaCoches();
	ListaCoches(size_t numElems);//no se que es 
	~ListaCoches();
	//bool leerModelos(ListaCoches& listaCoche);
	Coche* buscarCoche(int código)const;
	void insertaCoche(Coche* nuevoCoche);
	friend ostream& operator<<(ostream& os, const ListaCoches& listaCoches);
	friend istream& operator>>(istream& in, ListaCoches& listaCoches);
};

