#include "mazo.h"

Mazo::Mazo() {
	//Cartas de "Espada"
	for (int i = 1; i <= 7; i++) {
		_mazo.push_back(new Carta(i, "Espada"));
	}
	for (int i = 10; i <= 12; i++) {
		_mazo.push_back(new Carta(i, "Espada"));
	}
	//Cartas de "Basto"
	for (int i = 1; i <= 7; i++) {
		_mazo.push_back(new Carta(i, "Basto"));
	}
	for (int i = 10; i <= 12; i++) {
		_mazo.push_back(new Carta(i, "Basto"));
	}
	//Cartas de "Oro"
	for (int i = 1; i <= 7; i++) {
		_mazo.push_back(new Carta(i, "Oro"));
	}
	for (int i = 10; i <= 12; i++) {
		_mazo.push_back(new Carta(i, "Oro"));
	}
	//Cartas de ""Copa""
	for (int i = 1; i <= 7; i++) {
		_mazo.push_back(new Carta(i, "Copa"));
	}
	for (int i = 10; i <= 12; i++) {
		_mazo.push_back(new Carta(i, "Copa"));
	}
}
int Mazo::size() {
	return _mazo.size();
}
Carta* Mazo::operator[](int indice) const {
	if (indice < _mazo.size()) {
		return _mazo[indice];
	}
	else {
		return nullptr;
	}
}
Carta* Mazo::back() {
	return (*this)[(*this).size() - 1];
}
void Mazo::swap(Carta* carta1, Carta* carta2) {
	//busqueda lineal de los elementos ya que puede no estar ordenada
	//si ya swapie antes otras cartas.
	bool encontre1 = false;
	bool encontre2 = false;
	int indice1;
	int indice2;
	for (int i = 0; i < _mazo.size() && !encontre1; i++) {
		if (_mazo[i] == carta1) {
			encontre1 = true;
			indice1 = i;
		}
	}
	for (int j = 0; j < _mazo.size() && !encontre2; j++) {
		if (_mazo[j] == carta2) {
			encontre2 = true;
			indice2 = j;
		}
	}
	if (encontre1 && encontre2) {
		Carta* aux = _mazo[indice1];
		_mazo[indice1] = _mazo[indice2];
		_mazo[indice2] = aux;
	}

}
void Mazo::pop_back() {
	_mazo.pop_back();
}
void Mazo::push_back(Carta* c) {
	_mazo.push_back(c);
}