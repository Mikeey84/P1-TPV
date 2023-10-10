// Marcos Perez y Miguel Angel Lopez - Grupo 10

#include "ListaAlquileres.h"
#include "ListaCoches.h"
#include "Alquiler.h"
#include "Coche.h"
#include <algorithm>
#include <iostream>
#include <fstream>

ListaAlquileres::ListaAlquileres() : alquileres(nullptr), numElems(0), tam(numElems + 20) {}

ListaAlquileres:: ~ListaAlquileres() {
	for (int i = 0; i < numElems; i++) {
		delete alquileres[i];
		alquileres[i] = nullptr;
	}
	delete[] alquileres;
	alquileres = nullptr;
}
//bool operator<(const Alquiler& izq, const Alquiler& der) {
//	return izq.getFecha() < der.getFecha();
//}

/*-------------------------------------*/
//Por terminar 
void ListaAlquileres::leeAlquileres(istream& in, const ListaCoches& listaCoches) {
	in >> numElems;
	alquileres = new Alquiler * [tam];
	in.ignore();
	for (int i = 0; i <= numElems; i++) {
		int codigo;
		Coche* co;
		Date f;
		int d;
		in >> codigo;
		co = listaCoches.buscarCoche(codigo);
		in >> f;
		in >> d;
		alquileres[i] = new Alquiler(co, f, d);
	}
}
/*-----------------------------------*/

ostream& operator<<(ostream& os, const ListaAlquileres& listaAlquileres) {
	for (int i = 0; i < listaAlquileres.numElems; i++)
	{
		os << *listaAlquileres.alquileres[i] << endl;
	}
	return os;
}

/*----------------*/
//Funcion que intercambia posiciones de elemntos en un array dinamico
//Util para metodo -->>>> ordenar()

void intercambiar(Alquiler*& a, Alquiler*& b) {
	Alquiler *temp = a;
	a = b;
	b = temp;
}
/*---------------*/

void ListaAlquileres::ordenar() {

	for (int i = 0; i < numElems - 1; i++) {
		
		for (int j = 0; j < numElems - i - 1; j++) {
			if (*alquileres[j+1] < *alquileres[j])
				intercambiar(alquileres[j], alquileres[j + 1]);
		}
	}
	
}
bool ListaAlquileres::insertaAlquiler(const Alquiler& nuevoAlquiler) {
	if (numElems < tam) {
		alquileres[numElems] = new Alquiler(nuevoAlquiler);
		numElems++;
		ordenar();
		return true;
	}
	else {
		cout << "No caben más alquileres";
		return false;
	}
}