#include "Jugador.h"

Jugador::Jugador() : puntaje(0), buenas(false) {}

bool Jugador::estaEnBuenas() {
	return buenas;
}

int Jugador::puntos() {
	return puntaje;
}
void Jugador::sumarPuntos(int puntos) {
	puntaje += puntos;
	if (puntaje >= 15 && !(this->estaEnBuenas())) { // 15 porque son los puntos incluidos en las "Malas"
		puntaje = puntaje - 15;
		buenas = true;
	}
}
void Jugador::repartir(Carta* carta) {
	manoDelJugador.push_back(carta);
}
bool Jugador::flor() {
	bool res = false;
	if (manoDelJugador[0]->obtenerPalo() == manoDelJugador[1]->obtenerPalo() && manoDelJugador[1]->obtenerPalo() == manoDelJugador[2]->obtenerPalo()) {
		res = true;
	}
	return res;
}
vector<Carta*>& Jugador::mano() {
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
	int valorJugada = jugada->obtenerValor();
	while (i < manoDelJugador.size() && !encontre) {
		int valorCarta = manoDelJugador[i]->obtenerValor();
		if (valorJugada == valorCarta) {
			encontre = true;
		}
		else {
			i++;
		}
	}
	Carta* aux = manoDelJugador[i];
	manoDelJugador[i] = manoDelJugador.back();
	manoDelJugador[manoDelJugador.size() - 1] = aux;
	manoDelJugador.pop_back();
}
bool Jugador::gano() {
	return _ganoAnterior;
}
void Jugador::cambiarGanadorRonda() {
	_ganoAnterior = !_ganoAnterior;
}
void Jugador::ganoMano(int rondaACambiar) {
	if (rondaACambiar == 1) {
		_ganoPrimera = true;
	}
	else if (rondaACambiar == 2) {
		_ganoSegunda = true;
	}
	else if (rondaACambiar == 3) {
		_ganoTercera = true;
	}
}
bool Jugador::ganoPrimera() {
	return _ganoPrimera;
}
void Jugador::resetManos() {
	_ganoAnterior = false;
	_ganoPrimera = false;
	_ganoSegunda = false;
	_ganoTercera = false;
}
void Jugador::vaciarManoJugador() {
	for (int i = 0; i < manoDelJugador.size(); i++){
		manoDelJugador.pop_back();
	}
}