// Marcos Perez y Miguel Angel Lopez - Grupo 10

#include "ListaCoches.h"
#include"Coche.h"
#include <fstream>
#include <iostream>

using namespace std;

ListaCoches::ListaCoches() : coches(nullptr), numElems(0), tam(numElems + 20) {}

ListaCoches::~ListaCoches() {
	for (int i = 0; i < numElems; i++) {
		delete coches[i];
		coches[i] = nullptr;
	}
	delete[] coches;
	coches = nullptr;
}
ostream& operator<<(ostream& os, const ListaCoches& listaCoches) {
	for (int i = 0; i < listaCoches.numElems; i++)
	{
		os << *listaCoches.coches[i] << endl;
	}
	return os;
}
istream& operator>>(istream& in, ListaCoches& listaCoches) {
	in >> listaCoches.numElems;
	listaCoches.coches = new Coche* [listaCoches.tam];
	in.ignore();
	
	for (int i = 0; i < listaCoches.numElems; i++) {
		
		int cod, prec;
		string nombre;
		in >> cod >> prec;
		in.ignore();
		getline(in, nombre);
		
		listaCoches.coches[i] = new Coche(cod, prec, nombre);
	}
	return in;
}


Coche* ListaCoches::buscarCoche(int código)const {
	int izq = 0, der = numElems - 1;
	//busqueda binaria de elementos con 2 auxiliares
	while (izq <= der)
	{
		int centro = izq + (der - izq) / 2;
		if (coches[centro]->GetCódigo() == código)
		{
			return coches[centro];
		}
		if (código < coches[centro]->GetCódigo())
		{
			der = centro - 1;
		}
		else izq = centro + 1;
	}
	return nullptr;
}
bool ListaCoches::insertaCoche(const Coche& nuevoCoche) {
	if (numElems < tam) {
		coches[numElems] = new Coche(nuevoCoche);
		int i = numElems;
		while (coches[i]->GetCódigo() < coches[i - 1]->GetCódigo() && i > 0) {
			Coche* aux = coches[i - 1];
			coches[i - 1] = coches[i];
			coches[i] = aux;
			if(i > 1)i--;
			
		}
		numElems++;
		return true;
	}
	else {
		cout << "Capacidad de la lista de coches llena";
		return false;
	}
}
		
