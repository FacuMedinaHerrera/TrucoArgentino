#include "cartas.h"

vector<vector<Carta>> ordenDeValor =
{ { Carta(1, "Espada") },
    { Carta(1, "Basto")},
    { Carta(7, "Espada")},
    { Carta(7, "Oro") },
    { Carta(3,"Espada"),Carta(3,"Oro"),Carta(3,"Basto"),Carta(3,"Copa") },
    { Carta(2,"Espada"),Carta(2,"Oro"),Carta(2,"Basto"),Carta(2,"Copa") },
    { Carta(1,"Oro"),Carta(1,"Copa") } ,
    { Carta(12,"Espada"),Carta(12,"Oro"),Carta(12,"Basto"),Carta(12,"Copa") } ,
    { Carta(11,"Espada"),Carta(11,"Oro"),Carta(11,"Basto"),Carta(11,"Copa") } ,
    { Carta(10,"Espada"),Carta(10,"Oro"),Carta(10,"Basto"),Carta(10,"Copa") } ,
    { Carta(7,"Basto"),Carta(7,"Copa") } ,
    { Carta(6,"Espada"),Carta(6,"Oro"),Carta(6,"Basto"),Carta(6,"Copa") } ,
    { Carta(5,"Espada"),Carta(5,"Oro"),Carta(5,"Basto"),Carta(5,"Copa") } ,
    {Carta(4,"Espada"),Carta(4,"Oro"),Carta(4,"Basto"),Carta(4,"Copa")}
};

Carta::Carta(int valor, string palo) :_valor(valor), _palo(palo) {}
int Carta::obtenerValor() {
    return _valor;
}
string Carta::obtenerPalo() {
    return _palo;
}
int Carta::obtenerValorRelativo() {
    int valorRelativo=0;
    for (int i = 0; i < ordenDeValor.size(); i++) {
        for (int j = 0; j < ordenDeValor[i].size(); j++) {
            if ((this->obtenerValor() == ordenDeValor[i][j].obtenerValor()) && (this->obtenerPalo() == ordenDeValor[i][j].obtenerPalo())) {
                valorRelativo = i;
            }
        }
    }
    return valorRelativo;
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
    }
    else if (carta.obtenerPalo() == "Oro") {
        palo = "Oro";
    }
    else {
        palo = "no palo"; //solo por motivos de debugeo, no deberia de llegar nunca a esta instancia
    }

    os << carta.obtenerValor() << " de " << palo;
    return os;
}