#include <iostream>
#include "Truco.h"



Truco::Truco() {
	ordenDeValor.push_back({ Carta(1, espada) });
	ordenDeValor.push_back({ Carta(1, basto) });
	ordenDeValor.push_back({ Carta(7, espada) });
	ordenDeValor.push_back({ Carta(7, oro) });
	ordenDeValor.push_back({ Carta(3,espada),Carta(3,oro),Carta(3,basto),Carta(3,copa) });
	ordenDeValor.push_back({ Carta(2,espada),Carta(2,oro),Carta(2,basto),Carta(2,copa) });
	ordenDeValor.push_back({ Carta(1,oro),Carta(1,copa) });
	ordenDeValor.push_back({ Carta(12,espada),Carta(12,oro),Carta(12,basto),Carta(12,copa) });
	ordenDeValor.push_back({ Carta(11,espada),Carta(11,oro),Carta(11,basto),Carta(11,copa) });
	ordenDeValor.push_back({ Carta(10,espada),Carta(10,oro),Carta(10,basto),Carta(10,copa) });
	ordenDeValor.push_back({ Carta(7,basto),Carta(7,copa) });
	ordenDeValor.push_back({ Carta(6,espada),Carta(6,oro),Carta(6,basto),Carta(6,copa) });
	ordenDeValor.push_back({ Carta(5,espada),Carta(5,oro),Carta(5,basto),Carta(5,copa) });
	ordenDeValor.push_back({ Carta(4,espada),Carta(4,oro),Carta(4,basto),Carta(4,copa) });
}
Truco::~Truco() {
	for (int i = 0; i < mazo.size(); i++) {
		delete mazo[i];
	}
}
int Truco::puntaje(Jugador j) {
	return j.puntos();
}
void Truco::sumarPuntos(Jugador j,int puntos) {
	j.sumarPuntos(puntos);
}
void Truco::repartir(Jugador j1, Jugador ia) {
	//Si bien mi mazo esta ordenado, elegire cartas al azar
	//del mazo, lo cual simula la mezcla de este.
	vector<Carta*>aRepartir;
	

	if (mazo.size()!=0) {
		for (int i = 0; i < 6; i++) {
			//establezco la semilla para rand();
			srand(static_cast<unsigned int>(time(0)));
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
		j1.repartir(aRepartir[j]);
		ia.repartir(aRepartir[j+1]);
		j += 2;
	}
}
//agrego todas las cartas en una mano al mazo original para volver a repartir
void Truco::reestablecerMazo() {
	for (int i = 0; i < pilaDescarte.size(); i++) {
		mazo.push_back(pilaDescarte[i]);
	}
}