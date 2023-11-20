#include "cartas.h"

Carta::Carta(int valor,string palo):_valor(valor),_palo(palo){}
int Carta::obtenerValor() {
	return _valor;
}
string Carta::obtenerPalo() {
	return _palo;
}

ostream& operator<<(ostream& os, Carta* carta) {
    string palo;
    if (carta->obtenerPalo() == "Espada") palo = "Espada";
    if (carta->obtenerPalo() == "basto") palo = "Basto";
    if (carta->obtenerPalo() == "Copa") palo = "Copa";
    if (carta->obtenerPalo() == "Oro") palo = "Oro";
    os << carta->obtenerValor() << " de " << palo;
    return os;
}