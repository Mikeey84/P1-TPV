// TPV Práctica1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "Date.h"
#include"ListaAlquileres.h"
#include"ListaCoches.h"
#include "Alquiler.h"
#include "Coche.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
	//funcion para usar tildes
	SetConsoleOutputCP(CP_UTF8);
	//Inicializacion listaCoches
	ListaCoches listaCoches;
	ListaAlquileres listaAlquileres;

	ifstream entrada;
	entrada.open("coches.txt");
	if (!entrada.is_open()) {
		return false;
	}
	else {
		entrada >> listaCoches;
	}
	entrada.close();
	cout << listaCoches;
	/*entrada.open("rent.txt");
	listaAlquileres.leeAlquileres(entrada, listaCoches);
	entrada.close();
	listaAlquileres.ordenar();*/
	
	

	/*leerModelos(listaCoches);
	leerAlquileres(listaAlquileres, listaCoches);

	

	ordenarAlquileres(listaAlquileres.Alquiler, listaAlquileres.tam);
	
	mostrarAlquileres(listaAlquileres);

	delete[] listaAlquileres.Alquiler;
	listaAlquileres.Alquiler = nullptr;

	delete[] listaCoches.Coche;
	listaCoches.Coche = nullptr;*/

}

