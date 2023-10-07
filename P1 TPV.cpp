// TPV Práctica1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "Date.h"
#include <string>
#include <vector>

using namespace std;

struct Coche
{
	int código;
	string nombre;
	int precio;
};

struct Alquiler
{
	int código;
	int días;
	Date fecha;
	Coche* Coche;
};

struct ListaCoches
{
	int contador;
	int tam = contador + 10;
	Coche* Coche;
};

struct ListaAlquileres
{
	int contador;
	int tam = contador + 10;
	Alquiler* Alquiler;
};
bool leerModelos(ListaCoches& listaCoches)
{
	//apertura de txt
	ifstream entrada;
	entrada.open("coches.txt");

	//si no se ha abierto, retorna false, si no, guarda los datos de entrada
	if (!entrada.is_open()) return false;
	else {
		entrada >> listaCoches.tam;
		listaCoches.Coche = new Coche[listaCoches.tam];

		int i = 0;
		while (!entrada.eof() && i < listaCoches.tam)
		{
			entrada >> listaCoches.Coche[i].código;
			entrada >> listaCoches.Coche[i].precio;
			getline(entrada, listaCoches.Coche[i].nombre);
			//debug
			/*cout << listaCoches.Coche[i].código << " " << listaCoches.Coche[i].precio << " " << listaCoches.Coche[i].nombre << "\n";*/
			i++;
		}

	}
	return true;
}


//int buscarCoche(const ListaCoches& listaCoches, int& código) {
//	int centro;
//	int abajo = 0;
//	int arriba = listaCoches.tam - 1;
//	//busqueda binaria de elementos con 2 auxiliares
//	while (abajo <= arriba)
//	{
//		centro = (arriba + abajo) / 2;
//		if (listaCoches.Coche[centro].código == código)
//		{
//			return centro;
//		}
//		else if (código < listaCoches.Coche[centro].código)
//		{
//			arriba = centro - 1;
//		}
//		else abajo = centro + 1;
//	}
//	return -1;
//}

bool leerAlquileres(ListaAlquileres& listaAlquileres, ListaCoches& listaCoches)
{
	ifstream entrada;
	entrada.open("rent.txt");

	//si no se encuentra, retorna false, si se encuentra, guarda los datos de entrada

	if (!entrada.is_open()) return false;
	else
	{
		entrada >> listaAlquileres.tam;

		listaAlquileres.Alquiler = new Alquiler[listaAlquileres.tam];
		int i = 0;
		while (!entrada.eof() && i < listaAlquileres.tam)
		{
			entrada >> listaAlquileres.Alquiler[i].código;
			entrada >> listaAlquileres.Alquiler[i].fecha;
			entrada >> listaAlquileres.Alquiler[i].días;

			//debug
			//cout << listaAlquileres.Alquiler[i].código << " " << listaAlquileres.Alquiler[i].fecha << " " << listaAlquileres.Alquiler[i].días << "\n";


			int indice = buscarCoche(listaCoches, listaAlquileres.Alquiler[i].código);
			if (indice == -1)
			{
				listaAlquileres.Alquiler[i].Coche = nullptr;
			}
			else
			{
				listaAlquileres.Alquiler[i].Coche = &listaCoches.Coche[indice];
			}

			i++;
		}

	}
	return true;
}
bool operator<(const Alquiler& izqu, const Alquiler& derech)
{
	return izqu.fecha < derech.fecha;
}

void ordenarAlquileres(Alquiler* alquiler, int todosAlquileres) {
	sort(alquiler, alquiler + todosAlquileres);
}

void mostrarAlquileres(const ListaAlquileres &listaAlquileres)
{
	for (int i = 0; i < listaAlquileres.tam; i++)
	{
		
		if (listaAlquileres.Alquiler[i].Coche == nullptr)
		{
			cout << listaAlquileres.Alquiler[i].fecha << " ERROR: Modelo inexistente" << endl;
		}
		else
			cout << listaAlquileres.Alquiler[i].fecha << " " << listaAlquileres.Alquiler[i].Coche->nombre << " " << listaAlquileres.Alquiler[i].días << " día(s) por " << listaAlquileres.Alquiler[i].días * listaAlquileres.Alquiler[i].Coche->precio << " euros" << endl;
	}
}

int main()
{
	//funcion para usar tildes
	SetConsoleOutputCP(CP_UTF8);
	ListaCoches listaCoches;
	ListaAlquileres listaAlquileres;
	
	

	leerModelos(listaCoches);
	leerAlquileres(listaAlquileres, listaCoches);

	

	ordenarAlquileres(listaAlquileres.Alquiler, listaAlquileres.tam);
	
	mostrarAlquileres(listaAlquileres);

	delete[] listaAlquileres.Alquiler;
	listaAlquileres.Alquiler = nullptr;

	delete[] listaCoches.Coche;
	listaCoches.Coche = nullptr;

}

