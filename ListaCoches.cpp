#include "ListaCoches.h"
#include <fstream>
#include <iostream>

using namespace std;

ListaCoches::ListaCoches() : coche(), numElems() {} //no se que hay que meter en la constructora de ListaCoches
ListaCoches::ListaCoches(Coche* coches, int numElemes): coche(coches), numElems(numElemes){}

ostream& operator<<(ostream& os, const ListaCoches& listaCoches) {
	for (int i = 0; i < listaCoches.numElems; i++)
	{
		os << listaCoches.coche[i] << endl;
	}
	return os;
}
istream& operator>>(istream& in, ListaCoches& listaCoches) {
	//no se que hay que meter en in (puede que meter un nuevo coche en la lista)
	return in;
}

bool ListaCoches::leerModelos(ListaCoches& listaCoches)
{
	//apertura de txt
	ifstream entrada;
	entrada.open("coches.txt");

	//si no se ha abierto, retorna false, si no, guarda los datos de entrada
	if (!entrada.is_open()) return false;
	else {
		
		entrada >> listaCoches.numElems;
		Coche* nuevoCoche;
		ListaCoches listaC(nuevoCoche,listaCoches.numElems);
		

		int i = 0;
		while (!entrada.eof() && i < listaCoches.tam)
		{
			entrada >> 
			entrada >> 
			
			//debug
			/*cout << listaCoches.Coche[i].código << " " << listaCoches.Coche[i].precio << " " << listaCoches.Coche[i].nombre << "\n";*/
			i++;
		}

	}
	return true;
}

int ListaCoches::buscarCoche(int código) {
	int centro;
	int abajo = 0;
	int arriba = tam;
	//busqueda binaria de elementos con 2 auxiliares
	while (abajo <= arriba)
	{
		centro = (arriba + abajo) / 2;
		if (coche[centro].GetCódigo() == código)
		{
			return centro;
		}
		else if (código < coche[centro].GetCódigo())
		{
			arriba = centro - 1;
		}
		else abajo = centro + 1;
	}
	return -1;
}
void ListaCoches::insertaCoche(Coche nuevoCoche){
	
}
