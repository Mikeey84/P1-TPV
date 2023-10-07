#pragma once
#include "Alquiler.h"


using namespace std;

class ListaAlquileres
{
private:
	int contador;
	int tam = contador + 10;
	Alquiler* Alquiler;
public:
	void ordenarAlquileres(int);
	void mostrarAlquileres();
};

