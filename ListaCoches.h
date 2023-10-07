#pragma once
#include "Coche.h"

using namespace std;

class ListaCoches
{
private:
	int contador;
	int tam = contador + 10;
	Coche* Coche;

public:
	bool leerModelos();
	int buscarCoche(int);
};

