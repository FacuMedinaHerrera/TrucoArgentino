#pragma once
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
	void cambiarMano();
	bool esMano();
	void reestablecerPuntaje();
	void tirarCartaJugada(Carta* jugada);
	bool gano();
	void cambiarGanadorRonda();
	bool ganoPrimera();
	void ganoMano(int rondaACambiar);
	void resetManos();
	bool cantoAnteriorTruco = false;

private:
	int puntaje;
	bool buenas;
	vector<Carta*> manoDelJugador;
	bool _esMano = false;
	bool _ganoAnterior = false;
	bool _ganoPrimera = false;
	bool _ganoSegunda = false;
	bool _ganoTercera = false;



};