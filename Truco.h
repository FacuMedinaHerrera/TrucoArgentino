﻿// ProyectoFinal-Truco.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <windows.h>
#include <iostream>
#include <ctime>
#include<cstdlib>
#include "Jugador.h"
#include "mazo.h"


using namespace std;


class Truco{
public:
	Truco(Jugador& j1, Jugador& ia);
	~Truco();
	int puntaje(Jugador& j);
	void sumarPuntos(Jugador& j,int puntos);
	void repartir(Jugador& j1, Jugador& ia);
	void reestablecerMazo();
	int ronda();
	void reestablecerJuego();
private:
	Jugador& _j1;
	Jugador& _ia;
	Mazo mazo;
	//agregare las cartas repartidas para luego reinsertar en el mazo original
	vector<Carta*> pilaDescarte;
	//vector para establecer la relacion de valores de las cartas
	vector<vector<Carta>> ordenDeValor;
	int _ronda = 1;
};

