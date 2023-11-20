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
	if (puntaje >= 15) { // 15 porque son los puntos incluidos en las "Malas"
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
bool Jugador::esMano() {
	return _esMano;
}