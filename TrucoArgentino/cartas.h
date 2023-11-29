#pragma once
#include<Windows.h>
#include <iostream>
#include<vector>


using namespace std;


class Carta {
public:
	Carta(int valor, string palo);
	int obtenerValor();
	string obtenerPalo();
	friend ostream& operator<< (ostream& os, Carta& carta);
	bool operator==(const Carta& otra)const {
		return (this->_valor == otra._valor) && (this->_palo == otra._palo);
	}
	int obtenerValorRelativo();
private:
	int _valor;
	string _palo;
};

extern vector<vector<Carta>>ordenDeValor;