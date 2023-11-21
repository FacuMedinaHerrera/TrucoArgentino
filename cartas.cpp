#include "cartas.h"

Carta::Carta(int valor,string palo):_valor(valor),_palo(palo){}
int Carta::obtenerValor() {
	return _valor;
}
string Carta::obtenerPalo() {
	return _palo;
}

ostream& operator<<(ostream& os, Carta& carta) {
    string palo;
    if (carta.obtenerPalo() == "Espada") {
        palo = "Espada";
    }
    else if (carta.obtenerPalo() == "Basto") {
        palo = "Basto";
    }
    else if (carta.obtenerPalo() == "Copa") {
        palo = "Copa";
    }else if (carta.obtenerPalo() == "Oro") {
        palo = "Oro";
    }else { 
        palo = "no palo"; //solo por motivos de debugeo, no deberia de llegar nunca a esta instancia
    }
    
    os << carta.obtenerValor() << " de " << palo;
    return os;
}