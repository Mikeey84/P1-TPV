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
	string nombre;
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
bool leerModelos(ListaCoches listaCoches)
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
			/*cout << listaCoches.Coche[i].código << " " << listaCoches.Coche[i].precio << " " << listaCoches.Coche[i].nombre << "\n";*/
			i++;
		}
		delete[]listaCoches.Coche;
	}
	return true;
}


int buscarCoche(ListaCoches listaCoches, int código) {
	return 0;
}

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
			
		

			if (buscarCoche(listaCoches, listaAlquileres.Alquiler[i].código) == -1)
			{
				listaAlquileres.Alquiler[i].Coche = nullptr;
			}
			else
			{
				listaAlquileres.Alquiler[i].Coche = &listaCoches.Coche[buscarCoche(listaCoches, listaAlquileres.Alquiler[i].código)];
			}

			i++;
		}
		//delete[]listaAlquileres.Alquiler;
	}
	return true;
}



void ordenarAlquileres(const ListaAlquileres& listaAlquileres) {
	//vector para ordenar de fechas
	vector<Date> fechas(listaAlquileres.tam);

	//for para rellenar el vector
	for (int i = 0; i < listaAlquileres.tam; i++)
	{
		fechas[i] = listaAlquileres.Alquiler[i].fecha;
	}
	//metodo que ordena de menor a mayor
	sort(fechas.begin(), fechas.end());
	//debug
	for (auto& elem : fechas)
		std::cout << elem << " " << std::endl;


}



int main()
{
	//funcion para usar tildes
	SetConsoleOutputCP(CP_UTF8);
	ListaCoches listaCoches;
	ListaAlquileres listaAlquileres;
	bool a = leerModelos(listaCoches);
	bool b = leerAlquileres(listaAlquileres, listaCoches);
	ordenarAlquileres(listaAlquileres);


}

