#include "ListaAlquileres.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <windows.h>


ostream& operator<<(ostream& os, const ListaAlquileres& listaAlquileres) {
	for (int i = 0; i < listaAlquileres.numElems; i++)
	{
		os << listaAlquileres.Alquiler[i] << endl;
	}
	return os;
}

void ListaAlquileres::ordenarAlquileres(int numeroAlquileres) {
	sort(Alquiler, Alquiler + numeroAlquileres); //repasar si este metodo funciona o hay que pasar al metodo alquiler
}
void ListaAlquileres::mostrarAlquileres() {
	for (int i = 0; i < tam; i++)
	{
		int pos;
		if (Alquiler[i].Coche == nullptr)
		{
			cout << Alquiler[i].GetFecha() << " ERROR: Modelo inexistente" << endl;
		}
		else
			cout << Alquiler[i].GetFecha() << " " << Alquiler[i].Coche->GetNombre << " " << Alquiler[i].GetDías() << " día(s) por " << Alquiler[i].GetDías() * Alquiler[i].Coche->GetPrecio() << " euros" << endl;
	}
}