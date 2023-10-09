#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class Coche
{
private:
	int c�digo;
	string nombre;
	int precio;

public:
	Coche();
	Coche(int c�digo, int precio, string nombre);
	/*bool LeerModelo(int);*/
	int GetC�digo() const;
	int GetPrecio() const;
	string GetNombre() const;

	friend istream& operator>>(istream& in, Coche& coche);

	friend ostream& operator<<(ostream& os, const Coche& coche);
};

