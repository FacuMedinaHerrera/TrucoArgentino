#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include "cartas.h"
using namespace std;


class Jugador {
public:
	Jugador();
	bool estaEnBuenas();
	int puntos();
	void sumarPuntos(int puntos);
	void repartir(Carta* carta);
	bool flor();
	vector<Carta*> mano();
	bool esMano();
private:
	int puntaje;
	bool buenas;
	vector<Carta*> manoDelJugador;
	bool _esMano = false;
	
};