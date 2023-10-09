#include "ListaAlquileres.h"
#include "ListaCoches.h"
#include "Alquiler.h"
#include <algorithm>
#include <iostream>
#include <fstream>

ListaAlquileres::ListaAlquileres() : alquiler(), numElems(), tam(){}
ListaAlquileres::ListaAlquileres(Alquiler* alquiler, int numElems, int tam) : alquiler(alquiler), numElems(numElems), tam(tam){}

bool operator<(const Alquiler& izq, const Alquiler& der) {
	return izq.getFecha() < der.getFecha();
}

bool ListaAlquileres::leerAlquileres(const ListaCoches& listaCoches) {
	ifstream entrada;
	entrada.open("rent.txt");
	if (!entrada.is_open()) {
		return false;
	}
	else {
		entrada >> tam;
		tam += 10;
		alquiler = new Alquiler[tam];
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


ostream& operator<<(ostream& os, const ListaAlquileres& listaAlquileres) {
	for (int i = 0; i < listaAlquileres.numElems; i++)
	{
		os << listaAlquileres.alquiler[i] << endl;
	}
	return os;
}

void ListaAlquileres::ordenarAlquileres(int numeroAlquileres) {
	sort(alquiler, alquiler + numeroAlquileres); //repasar si este metodo funciona o hay que pasar al metodo alquiler
}
void ListaAlquileres::mostrarAlquileres() {
	for (int i = 0; i < tam; i++)
	{
		int pos;
		if (alquiler[i].getCoche() == nullptr)
		{
			cout << alquiler[i].getFecha() << " ERROR: Modelo inexistente" << endl;
		}
		else
			cout << alquiler[i].getFecha() << " " << alquiler[i].getCoche()->GetNombre() << " " << alquiler[i].getDias() << " día(s) por " << alquiler[i].getCoste() << " euros" << endl;
	}
}