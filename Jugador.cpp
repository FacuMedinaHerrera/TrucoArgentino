#include "Jugador.h"

Jugador::Jugador() : puntaje(0), buenas(false) {}

bool Jugador::estaEnBuenas() {
	return buenas;
}

int Jugador::puntos(){
	return puntaje;
}
void Jugador::sumarPuntos(int puntos) {
	puntaje += puntos;
	if (puntaje >= 15 && !(this->estaEnBuenas())) { // 15 porque son los puntos incluidos en las "Malas"
		puntaje = puntaje-15;
		buenas = true;
	}
}
void Jugador:: repartir(Carta* carta) {
	manoDelJugador.push_back(carta);
}
bool Jugador::flor() {
	bool res = false;
	if (manoDelJugador[0]->obtenerPalo() == manoDelJugador[1]->obtenerPalo() && manoDelJugador[1]->obtenerPalo() == manoDelJugador[2]->obtenerPalo()){
		res = true;
	}
	return res;
}
vector<Carta*> Jugador::mano() {
	return manoDelJugador;
}
void Jugador::cambiarMano() {
	_esMano = !_esMano;
}
bool Jugador::esMano() {
	return _esMano;
}
void Jugador::reestablecerPuntaje() {
	puntaje = 0;
}
void Jugador::tirarCartaJugada(Carta* jugada) {
	bool encontre = false;
	int i = 0;
	for (i; i < this->mano().size() && !encontre; i++) {
		if (jugada->obtenerValor() == (*this).mano()[i]->obtenerValor()) {
			encontre == true;
		}
	}
	Carta* aux = this->mano()[i];
	this->mano()[i] = this->mano().back();
	this->mano()[this->mano().size() - 1] = aux;
	manoDelJugador.pop_back();
}