#include "ListaAlquileres.h"
#include "ListaCoches.h"
#include "Alquiler.h"
#include "Coche.h"
#include <algorithm>
#include <iostream>
#include <fstream>

ListaAlquileres::ListaAlquileres() : numElems(){}
ListaAlquileres::ListaAlquileres(size_t numElems) {
	alquileres = new Alquiler* [tam];
}
ListaAlquileres:: ~ListaAlquileres() {
	for (int i = 0; i < numElems; i++) {
		delete alquileres[i];
	}
	delete[] alquileres;
}
bool operator<(const Alquiler& izq, const Alquiler& der) {
	return izq.getFecha() < der.getFecha();
}

/*-------------------------------------*/
//Se como se hace, esperate a que lloegue ;P;P
bool ListaAlquileres::leeAlquileres(const ListaCoches& listaCoches) {
	ifstream entrada;
	entrada.open("rent.txt");
	if (!entrada.is_open()) {
		return false;
	}
	else {
		entrada >> numElems;
		tam = numElems + 10;
		alquileres = new Alquiler*[tam];
		int i = 0;

		while (!entrada.eof()) {
			/*entrada >> alquiler[i];*/
			int index = listaCoches.buscarCoche(alquiler[i].getCoche()->GetCódigo());
			if (index == -1) alquiler[i].getCoche(nullptr);
			else alquiler[i].getCoche(&listaCoches.getCoche()[index]);
		}
		numElems++;
	}
	return true;
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

void intercambiar(Alquiler** a, Alquiler** b) {
	Alquiler* temp = *a;
	*a = *b;
	*b = temp;
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
		*alquileres[numElems] = nuevoAlquiler;
		numElems++;
	}
}