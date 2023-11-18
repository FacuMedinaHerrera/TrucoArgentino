#pragma once
#include <windows.h>
#include <iostream>

using namespace std;
enum PaloEnum{espada, basto, copa, oro};
class Palo {
public:
	Palo(PaloEnum palo);
	PaloEnum obtenerPalo();
	bool operator ==(const Palo& otro)const;
private:
	PaloEnum _palo;
};

class Carta {
public:
	Carta(int valor,Palo palo);
	int obtenerValor();
	Palo obtenerPalo();
private:
	int _valor;
	Palo _palo;
};