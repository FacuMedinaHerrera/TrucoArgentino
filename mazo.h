#pragma once
#include <windows.h>
#include <iostream>
#include<vector>
#include "cartas.h"


using namespace std;

class Mazo {
public:
	Mazo();
	int size();
	Carta* operator [](int indice) const;
	void swap(Carta* i, Carta* j);
	Carta* back();
	void pop_back();
	void push_back(Carta* c);
private:
	vector<Carta*> _mazo;
};