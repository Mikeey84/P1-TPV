#include "ListaCoches.h"
#include"Coche.h"
#include <fstream>
#include <iostream>

using namespace std;

ListaCoches::ListaCoches() : coches(coches = new Coche*[tam]), numElems(0), tam(numElems + 20) {}
ListaCoches::ListaCoches(Coche** c, size_t numElems, size_t tam) : coches(c), numElems(numElems), tam(numElems + 20){}
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


Coche* ListaCoches::buscarCoche(int c�digo)const {
	int centro;
	int abajo = 0;
	int arriba = numElems;
	//busqueda binaria de elementos con 2 auxiliares
	while (abajo <= arriba)
	{
		centro = (arriba + abajo) / 2;
		if (coches[centro]->GetC�digo() == c�digo)
		{
			return coches[centro];
		}
		else if (c�digo < coches[centro]->GetC�digo())
		{
			arriba = centro - 1;
		}
		else abajo = centro + 1;
	}
	return nullptr;
}
void ListaCoches::insertaCoche(const Coche& nuevoCoche){
	if (numElems < tam) {
		coches[numElems] = new Coche(nuevoCoche.GetC�digo(), nuevoCoche.GetPrecio(), nuevoCoche.GetNombre());
		numElems++;
	}
	else cout << "Capacidad de la lista de coches llena";
}
		
