#include "envido.h"
int obtenerMasAlto(vector<Carta*> mano) {
	int max = mano[0]->obtenerValor();
	for (int i = 1; i < mano.size(); i++) {
		if (max < mano[i]->obtenerValor()) {
			max = mano[i]->obtenerValor();
		}
	}
	return max;
}

Jugador quienGanaEnvido(Jugador j1, Jugador j2) {
	int sumaJugador1;
	int sumaJugador2;
	//primero veo ninguno tenga flor.
	if (!j1.flor() && !j2.flor()) {
		//primero veo si el jugador 1 tiene algun tipo de envido
		if (j1.mano()[0]->obtenerPalo() == j1.mano()[1]->obtenerPalo()) {
			int primeraCarta = j1.mano()[0]->obtenerValor();
			int segundaCarta = j1.mano()[1]->obtenerValor();
			//en caso de que las cartas sean figuras valen 0
			if (primeraCarta > 9 && primeraCarta < 13)primeraCarta = 0;
			if (segundaCarta > 9 && segundaCarta < 13)segundaCarta = 0;
			sumaJugador1 = 20 + primeraCarta + segundaCarta;
		}
		else if (j1.mano()[0]->obtenerPalo() == j1.mano()[2]->obtenerPalo()) {
			int primeraCarta = j1.mano()[0]->obtenerValor();
			int segundaCarta = j1.mano()[2]->obtenerValor();
			//en caso de que las cartas sean figuras valen 0
			if (primeraCarta > 9 && primeraCarta < 13)primeraCarta = 0;
			if (segundaCarta > 9 && segundaCarta < 13)segundaCarta = 0;
			sumaJugador1 = 20 + primeraCarta + segundaCarta;
		}
		else if (j1.mano()[1]->obtenerPalo() == j1.mano()[2]->obtenerPalo()) {
			int primeraCarta = j1.mano()[1]->obtenerValor();
			int segundaCarta = j1.mano()[2]->obtenerValor();
			//en caso de que las cartas sean figuras valen 0
			if (primeraCarta > 9 && primeraCarta < 13)primeraCarta = 0;
			if (segundaCarta > 9 && segundaCarta < 13)segundaCarta = 0;
			sumaJugador1 = 20 + primeraCarta + segundaCarta;
		}
		else/*No hay palos iguales en la mano*/ {
			sumaJugador1 = obtenerMasAlto(j1.mano());
		}

		if (j2.mano()[0]->obtenerPalo() == j2.mano()[1]->obtenerPalo()) {
			int primeraCarta = j2.mano()[0]->obtenerValor();
			int segundaCarta = j2.mano()[1]->obtenerValor();
			//en caso de que las cartas sean figuras valen 0
			if (primeraCarta > 9 && primeraCarta < 13)primeraCarta = 0;
			if (segundaCarta > 9 && segundaCarta < 13)segundaCarta = 0;
			sumaJugador2 = 20 + primeraCarta + segundaCarta;
		}else if (j2.mano()[0]->obtenerPalo() == j2.mano()[2]->obtenerPalo()) {
			int primeraCarta = j2.mano()[0]->obtenerValor();
			int segundaCarta = j2.mano()[2]->obtenerValor();
			//en caso de que las cartas sean figuras valen 0
			if (primeraCarta > 9 && primeraCarta < 13)primeraCarta = 0;
			if (segundaCarta > 9 && segundaCarta < 13)segundaCarta = 0;
			sumaJugador2 = 20 + primeraCarta + segundaCarta;
		}else if (j2.mano()[1]->obtenerPalo() == j2.mano()[2]->obtenerPalo()) {
			int primeraCarta = j2.mano()[1]->obtenerValor();
			int segundaCarta = j2.mano()[2]->obtenerValor();
			//en caso de que las cartas sean figuras valen 0
			if (primeraCarta > 9 && primeraCarta < 13)primeraCarta = 0;
			if (segundaCarta > 9 && segundaCarta < 13)segundaCarta = 0;
			sumaJugador2 = 20 + primeraCarta + segundaCarta;
		}else/*No hay palos iguales en la mano*/ {
			sumaJugador2 = obtenerMasAlto(j2.mano());
		}
	}
	else/*es flor */if (j1.flor() && !j2.flor()) {
		return j1;
	}
	else if (!j1.flor() && j2.flor()) {
		return j2;
	}else/*ambos tienen flor, se canta contraflor automaticamente y se calcula quien tiene la flor mas alta*/ {
		int valorPrimera = j1.mano()[0]->obtenerValor();
		int valorSegunda = j1.mano()[1]->obtenerValor();
		int valorTercera = j1.mano()[2]->obtenerValor();

		if (9 < valorPrimera && valorPrimera < 13)valorPrimera = 0;
		if (9 < valorSegunda && valorSegunda < 13)valorSegunda = 0;
		if (9 < valorTercera && valorTercera < 13)valorTercera = 0;
		sumaJugador1 = valorPrimera + valorSegunda + valorTercera;

		int valorPrimera2 = j2.mano()[0]->obtenerValor();
		int valorSegunda2 = j2.mano()[1]->obtenerValor();
		int valorTercera2 = j2.mano()[2]->obtenerValor();

		if (9 < valorPrimera2 && valorPrimera2 < 13)valorPrimera2 = 0;
		if (9 < valorSegunda2 && valorSegunda2 < 13)valorSegunda2 = 0;
		if (9 < valorTercera2 && valorTercera2 < 13)valorTercera2 = 0;
		sumaJugador2 = valorPrimera2 + valorSegunda2 + valorTercera2;
	}
	
	if(sumaJugador1 > sumaJugador2){
		return j1;
	}
	else if (sumaJugador1 < sumaJugador1) {
		return j2;
	}
	else {
		if (j1.esMano()) {
			return j1;
		}
		else {
			//por descarte j2 es mano, pero pongo la condicion para asegurarme la correctitud
			//del funcionamiento de la estructura
			if (j2.esMano()) {
				return j2;
			}
			else {
				cout << "Ninguno es Mano, chequea que va mal" << endl;
				return j2;
			}
		}
	}
}