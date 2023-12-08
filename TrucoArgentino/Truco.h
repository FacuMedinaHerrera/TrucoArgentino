#pragma once
#include <windows.h>
#include <iostream>
#include <ctime>
#include<cstdlib>
#include "cartas.h"
#include "mazo.h"
#include "Jugador.h"
#include "probabilidadIA.h"
#include "envido.h"



using namespace std;


class Truco {
public:
	Truco(Jugador& j1, Jugador& ia);
	~Truco();
	int puntaje(Jugador& j);
	void sumarPuntos(Jugador& j, int puntos);
	void repartir(Jugador& j1, Jugador& ia);
	void jugarCarta(Jugador& j1, Jugador& ia, Carta* aJugar, string quienLaJuega);
	void quienGana(Jugador& j1, Carta* cartaJ1, Jugador& ia, Carta* cartaIA);
	void reestablecerMazo();
	int ronda();
	void avanzarRonda();
	void reestablecerJuego();
	void cantarTruco(Jugador& j1, Jugador& ia, string quienCanta);
	void cantarReTruco(Jugador& j1, Jugador& ia, string quienCanta);
	void cantarVale4(Jugador& j1, Jugador& ia, string quienCanta);
	void nuevaMano();
	bool esParda1 = false;
	bool esParda2 = false;
	bool esParda3 = false;
	bool estanEnAlgunaInstanciaTruco();
	bool estanEnInstanciaTruco();
	bool estanEnInstanciaReTruco();
	bool estanEnInstanciaVale4();
private:
	Jugador& _j1;
	Jugador& _ia;
	Mazo mazo;
	//agregare las cartas repartidas para luego reinsertar en el mazo original
	vector<Carta*> pilaDescarte;
	int _ronda = 1;
	bool estanEnTruco = false;
	bool estanEnReTruco = false;
	bool estanEnVale4 = false;

};