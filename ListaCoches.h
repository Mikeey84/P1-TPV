#pragma once
#include "Coche.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class ListaCoches
{
private:
	int numElems;
	int tam = numElems + 10;
	Coche* coche;

public:
	ListaCoches();
	ListaCoches(Coche* coches, int numElems);//no se que es 
	bool leerModelos(ListaCoches& listaCoche);
	int buscarCoche(int código);
	void insertaCoche(Coche nuevoCoche);
	friend ostream& operator<<(ostream& os, const ListaCoches& listaCoches);
	friend istream& operator>>(istream& in, ListaCoches& listaCoches);
};

