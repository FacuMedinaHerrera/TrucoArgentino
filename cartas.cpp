#include "cartas.h"

Palo::Palo(PaloEnum palo) : _palo(palo) {}
PaloEnum Palo::obtenerPalo() {
	return _palo;
}

Carta::Carta(int valor,Palo palo):_valor(valor),_palo(palo){}
int Carta::obtenerValor() {
	return _valor;
}
Palo Carta::obtenerPalo() {
	return _palo;
}
bool Palo::operator==(const Palo& otro)const {
	return _palo == otro._palo;
}