#include <iostream>
#include "Truco.h"



Truco::Truco(Jugador& j1, Jugador& ia) : _j1(j1),_ia(ia){
	ordenDeValor.push_back({ Carta(1, "Espada") });
	ordenDeValor.push_back({ Carta(1, "Basto") });
	ordenDeValor.push_back({ Carta(7, "Espada") });
	ordenDeValor.push_back({ Carta(7, "Oro") });
	ordenDeValor.push_back({ Carta(3,"Espada"),Carta(3,"Oro"),Carta(3,"Basto"),Carta(3,"Copa") });
	ordenDeValor.push_back({ Carta(2,"Espada"),Carta(2,"Oro"),Carta(2,"Basto"),Carta(2,"Copa") });
	ordenDeValor.push_back({ Carta(1,"Oro"),Carta(1,"Copa") });
	ordenDeValor.push_back({ Carta(12,"Espada"),Carta(12,"Oro"),Carta(12,"Basto"),Carta(12,"Copa") });
	ordenDeValor.push_back({ Carta(11,"Espada"),Carta(11,"Oro"),Carta(11,"Basto"),Carta(11,"Copa") });
	ordenDeValor.push_back({ Carta(10,"Espada"),Carta(10,"Oro"),Carta(10,"Basto"),Carta(10,"Copa") });
	ordenDeValor.push_back({ Carta(7,"Basto"),Carta(7,"Copa") });
	ordenDeValor.push_back({ Carta(6,"Espada"),Carta(6,"Oro"),Carta(6,"Basto"),Carta(6,"Copa") });
	ordenDeValor.push_back({ Carta(5,"Espada"),Carta(5,"Oro"),Carta(5,"Basto"),Carta(5,"Copa") });
	ordenDeValor.push_back({ Carta(4,"Espada"),Carta(4,"Oro"),Carta(4,"Basto"),Carta(4,"Copa") });
}
Truco::~Truco() {
	for (int i = 0; i < mazo.size(); i++) {
		delete mazo[i];
	}
}
int Truco::puntaje(Jugador& j) {
	return j.puntos();
}
void Truco::sumarPuntos(Jugador& j,int puntos) {
	j.sumarPuntos(puntos);
}
void Truco::repartir(Jugador& j1, Jugador& ia) {
	//Si bien mi mazo esta ordenado, elegire cartas al azar
	//del mazo, lo cual simula la mezcla de este.
	vector<Carta*>aRepartir;
	if (mazo.size()!=0) {
		for (int i = 0; i < 6; i++) {
			int indiceAleatorio = rand() % mazo.size();
			//guardo la carta aleatoria elegida.
			aRepartir.push_back(mazo[indiceAleatorio]);
			pilaDescarte.push_back(mazo[indiceAleatorio]);
			//antes de eliminar el elemento del mazo, cambio
			//con el ultimo elto. del mazo para evitar problemas
			//de indexacion
			mazo.swap(mazo[indiceAleatorio], mazo.back());
			mazo.pop_back();
			//de esta forma quite la carta del mazo original y ademas de agregarla
			//a la mano del jugador(que luego se iran de ahi) quedara en una pila
			//de descarte. 

		}
	}
	int j = 0;
	while (j < 6) {
		if (_j1.esMano()) {
			_j1.repartir(aRepartir[j]);
			_ia.repartir(aRepartir[j + 1]);
			j += 2;
		}
		else {
			_ia.repartir(aRepartir[j]);
			_j1.repartir(aRepartir[j + 1]);
			j += 2;
		}
	}
}
//agrego todas las cartas en una mano al mazo original para volver a repartir
void Truco::reestablecerMazo() {
	for (int i = 0; i < pilaDescarte.size(); i++) {
		mazo.push_back(pilaDescarte[i]);
	}
}
int Truco::ronda() {
	return _ronda;
}
void Truco::reestablecerJuego() {
	reestablecerMazo();
	_ronda = 1;
	_j1.reestablecerPuntaje();
	_ia.reestablecerPuntaje();
}