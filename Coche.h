#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class Coche
{
private:
	int código;
	string nombre;
	int precio;

public:
	Coche();
	Coche(int código, int precio, string nombre);
	/*bool LeerModelo(int);*/
	int GetCódigo() const;
	int GetPrecio() const;
	string GetNombre() const;

	friend istream& operator>>(istream& in, Coche& coche);

	friend ostream& operator<<(ostream& os, const Coche& coche);
};

