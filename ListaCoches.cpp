#include "ListaCoches.h"
#include"Coche.h"
#include <fstream>
#include <iostream>

using namespace std;

ListaCoches::ListaCoches() : numElems() {} //no se que hay que meter en la constructora de ListaCoches
ListaCoches::ListaCoches(size_t numElemes) {
	coches = new Coche * [numElemes];
}
ListaCoches::~ListaCoches() {
	for (int i = 0; i < numElems; i++) {
		delete coches[i];
	}
	delete[] coches;
}

ostream& operator<<(ostream& os, const ListaCoches& listaCoches) {
	for (int i = 0; i < listaCoches.numElems; i++)
	{
		os << listaCoches.coches[i] << endl;
	}
	return os;
}
/*ya veremos su uso*/
istream& operator>>(istream& in, ListaCoches& listaCoches) {
	for (int i = 0; i < listaCoches.numElems; i++) {
	}
	return in;
}


Coche* ListaCoches::buscarCoche(int código)const {
	int centro;
	int abajo = 0;
	int arriba = tam;
	//busqueda binaria de elementos con 2 auxiliares
	while (abajo <= arriba)
	{
		centro = (arriba + abajo) / 2;
		if (coches[centro]->GetCódigo() == código)
		{
			return coches[centro];
		}
		else if (código < coches[centro]->GetCódigo())
		{
			arriba = centro - 1;
		}
		else abajo = centro + 1;
	}
	return nullptr;
}
void ListaCoches::insertaCoche(Coche* nuevoCoche){
	if (numElems < tam) {
		coches[numElems] = nuevoCoche;
		numElems++;
	}
	else cout << "Capacidad de la lista de coches llena";
}
		
