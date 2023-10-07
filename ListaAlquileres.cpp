#include "ListaAlquileres.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <windows.h>

void ListaAlquileres::ordenarAlquileres(int numeroAlquileres) {
	sort(Alquiler, Alquiler + numeroAlquileres);
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