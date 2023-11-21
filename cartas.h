#pragma once
#include <windows.h>
#include <iostream>

using namespace std;


class Carta {
public:
	Carta(int valor,string palo);
	int obtenerValor();
	string obtenerPalo();
	friend ostream& operator<< (ostream& os, Carta& carta);
private:
	int _valor;
	string _palo;
};
