#include "ListaAlquileres.h"
#include "ListaCoches.h"
#include "Alquiler.h"
#include "Coche.h"
#include <algorithm>
#include <iostream>
#include <fstream>

ListaAlquileres::ListaAlquileres() : alquileres(nullptr), numElems(0), tam(numElems) {}
ListaAlquileres::ListaAlquileres(Alquiler* alquileres ,size_t numElems, size_t tam) : alquileres(alquileres = new Alquiler[tam] ), numElems(numElems),tam(tam) {}
ListaAlquileres:: ~ListaAlquileres() {
	delete[] alquileres;
}
//bool operator<(const Alquiler& izq, const Alquiler& der) {
//	return izq.getFecha() < der.getFecha();
//}

/*-------------------------------------*/
//Por terminar 
void ListaAlquileres::leeAlquileres(istream& in, const ListaCoches& listaCoches) {
	cin >> numElems;
	for (int i = 0; i < numElems; i++) {
		alquileres[i].leeAlquiler(in, listaCoches);
	}
}
/*-----------------------------------*/

ostream& operator<<(ostream& os, const ListaAlquileres& listaAlquileres) {
	for (int i = 0; i < listaAlquileres.numElems; i++)
	{
		os << listaAlquileres.alquileres[i] << endl;
	}
	return os;
}

/*----------------*/
//Funcion que intercambia posiciones de elemntos en un array dinamico
//Util para metodo -->>>> ordenar()

void intercambiar(Alquiler* a, Alquiler* b) {
	Alquiler *temp = a;
	a = b;
	b = temp;
}
/*---------------*/

void ListaAlquileres::ordenar() {
	for (int i = 0; i < numElems - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < numElems; j++) {
			if (alquileres[j] < alquileres[minIndex]) minIndex = j;
		}
		if (minIndex != i) intercambiar(&alquileres[i], &alquileres[minIndex]);
	}
}
void ListaAlquileres::insertaAlquiler(const Alquiler& nuevoAlquiler) {
	if (numElems < tam) {
		alquileres[numElems] = nuevoAlquiler;
		numElems++;
	}
}