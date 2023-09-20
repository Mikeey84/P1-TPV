// TPV Práctica1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <windows.h>
#include "Date.h"
#include <string>

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
	ifstream entrada("coches.txt");
	entrada.open("coches.txt");

	//si no se ha abierto, retorna false, si no, guarda los dato en entra
	if (!entrada.is_open()) return false;
	else {
		entrada >> listaCoches.tam;
		string nombre1, nombre2;
		int i = 0;
		while (!entrada.eof())
		{
			entrada >> listaCoches.Coche[i].código;
			entrada >> listaCoches.Coche[i].precio;
			cout << listaCoches.Coche[i].código << listaCoches.Coche[i].precio;
			i++;
		}
	}
	return true;
}
int main()
{
	//funcion para usar tildes
	SetConsoleOutputCP(CP_UTF8);
	ListaCoches listaCoches;
	bool a = leerModelos(listaCoches);
}

