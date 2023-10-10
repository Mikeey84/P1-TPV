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
	
	entrada.open("rent.txt");
	listaAlquileres.leeAlquileres(entrada, listaCoches);
	entrada.close();
	listaAlquileres.ordenar();

	int aux = 0;


	//Inicio bucle ppal
	while (aux != 5) {
		cout << "\n** Alquiler de coches **" << endl
			<< endl
			<< "  1. Mostrar los coches\n  2. Mostrar los alquileres\n  3. Añadir un coche\n  4. Añadir un alquiler\n  5. Salir" << endl
			<< endl << "Opción> ";
		cin >> aux;

		if (aux == 1)cout << listaCoches;

		else if (aux == 2) cout << listaAlquileres;

		else if (aux == 3) {
			int cod, prec;
			string nom;
			Coche coche;
			do {
				cout << "Codigo: ";
				cin >> cod;
				if (listaCoches.buscarCoche(cod) != nullptr) cout << "Ya exite un coche con ese código\n";
			} while (listaCoches.buscarCoche(cod) != nullptr);


			cout << "Precio: ";
			cin >> prec;
			cout << "Modelo: ";
			cin.ignore();
			getline(cin, nom);
			coche = Coche(cod, prec, nom);
			if (listaCoches.insertaCoche(coche)) cout << "Coche insertado\n";
		}
		else if(aux == 4){
			int cod, dias;
			Date date = Date();
			Alquiler alq;
			do {
				cout << "Código del coche: "; 
				cin >> cod;
				if (listaCoches.buscarCoche(cod) == nullptr) cout << "No existe un coche con ese código\n";
			} while (listaCoches.buscarCoche(cod) == nullptr);

			cout << "Elegido " << *listaCoches.buscarCoche(cod);
			cout << "Fecha de inicio (d/m/a): ";
			cin >> date;
			cout << "Número de días: ";
			cin >> dias;
			alq = Alquiler(listaCoches.buscarCoche(cod), date, dias);
			if(listaAlquileres.insertaAlquiler(alq)) cout << "Alquiler insertado.\n";
			
		}
		
	}
	//Fin bucle ppal
	
	//Borra arrays dinamicos de memoria y los punteros que contienen
	listaCoches.~ListaCoches();
	listaAlquileres.~ListaAlquileres();


	return 0;
}

