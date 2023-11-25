#pragma once
#include <iostream>
#include "Truco.h"
#include "probabilidadesIA.h"
#include "envido.h"




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
//agrego todas las cartas en una mano al mazo original para volver a repartir y limpio las manos de los jugadores
void Truco::reestablecerMazo() {
	for (int i = 0; i < pilaDescarte.size(); i++) {
		mazo.push_back(pilaDescarte[i]);
	}
	for (int j = 0; j < _j1.mano().size(); j++) {
		_j1.mano().pop_back();
	}
	for (int k = 0; k < _ia.mano().size(); k++) {
		_ia.mano().pop_back();
	}
	for (int x = 0; x < pilaDescarte.size(); x++) {
		pilaDescarte.pop_back();
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
void Truco::nuevaMano() {
	estanEnTruco = false;
	estanEnReTruco = false;
	estanEnVale4 = false;
	_ronda = 1;
	reestablecerMazo();
	repartir(_j1, _ia);

}

void Truco::jugarCarta(Jugador& j1, Jugador& ia,Carta* aJugar, int quienLaJuega) {
	//el que juega la carta es el jugador
	if (quienLaJuega == 0) {
		//si la ronda es la primera, y el jugador es mano, eso quiere decir que no se jugo carta
		//Se juega la carta y se da una respuesta de la IA.

		if (_ronda == 1 && j1.esMano()) {
			cout << "Tu juegas:" << *aJugar << endl;
			j1.tirarCartaJugada(aJugar);
			int respuestaIA=respuestaPrimeraMano(); // las posibles respuestas son: Jugar una carta, cantar envido, cantar truco.
			//se canta envido
			if (respuestaIA == 1) {
				cout << "IA: Fuiste a la pesca?... Envido!" << endl;
				cantarEnvido(j1, ia, 1);
				//luego del envido la IA juega una carta.
				int cartaAJugar =eleccionDeCarta(ia.mano());
				cout << "IA juega: " << *(ia.mano()[cartaAJugar])<< endl;
				ia.tirarCartaJugada(ia.mano()[cartaAJugar]);
				_ronda++;
			}
			//se tira una carta
			else if (respuestaIA == 2) {
				int cartaAJugar = eleccionDeCarta(ia.mano());
				cout << "IA juega: " << *(ia.mano()[cartaAJugar]) << endl;
				ia.tirarCartaJugada(ia.mano()[cartaAJugar]);
				_ronda++;
			}
			//IA canta truco
			else {
				cantarTruco(j1, ia, 1);
				//una vez que se canta el truco y se define que sucedio veo si se tira un carta o no.
				//con que estemos en alguna instancia de truco, continua el juego.
				if (estanEnTruco || estanEnReTruco || estanEnVale4) {
					int cartaAJugar = eleccionDeCarta(ia.mano());
					cout << "IA juega: " << *(ia.mano()[cartaAJugar]) << endl;
					ia.tirarCartaJugada(ia.mano()[cartaAJugar]);
					_ronda++;
				}
				else {
					//como no se quiso el truco, termina la mano.
					nuevaMano();
				}
			}
		}
		//esto significa que la primera carta la jugo la IA
		else if (_ronda == 1 && !j1.esMano()) {
			cout << "Tu juegas: " << *aJugar<<endl;
			j1.tirarCartaJugada(aJugar);
		}
		else if (_ronda == 2 && j1.esMano()) {

		}
	}
	//juega la carta la IA
	else {

	}
}


void Truco::cantarTruco(Jugador& j1, Jugador& ia, int quienCanta) {
	//si canta la IA
	if (quienCanta == 1) {
		cout << "IA: Truco!" << endl;
		cout << "Que desea hacer?" << endl;
		cout << "1. Quiero 2. No quiero 3.Retruco" << endl;
		int respuesta;
		cin >> respuesta;
		while (1 > respuesta && respuesta > 3) {
			cout << "Entrada invalida, ingrese nuevamente" << endl;
			cin >> respuesta;
		}

		if (respuesta == 1) {
			cout << "Vos: Quiero." << endl;
			estanEnTruco = true;
		}
		else if (respuesta == 2) {
			cout << "Vos: No quiero." << endl;
			ia.sumarPuntos(1);
			cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
		}
		else {
			cout << "Vos: Quiero retruco." << endl;
			//la IA Tiene 3 respuestas: Quiero, no quiero, quiero vale 4.
			int respuestaIA = respuestaTruco(3);
			if (respuestaIA == 1) {
				cout << "IA: Quiero!" << endl;
				estanEnReTruco = true;
			}
			else if (respuestaIA == 2) {
				cout << "IA: No, no quiero." << endl;
				j1.sumarPuntos(2);
				cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
			}
			else {
				cout << "IA: Quiero vale 4, te animas?" << endl;
				cout << "Que desea hacer?" << endl;
				cout << "1. Quiero 2.No quiero" << endl;
				cin >> respuesta;
				while (1 > respuesta && respuesta > 2) {
					cout << "Entrada invalida, ingrese nuevamente" << endl;
					cin >> respuesta;
				}

				if (respuesta == 1) {
					cout << "Vos: Quiero, me la banco." << endl;
					estanEnVale4 = true;
				}
				else if (respuesta == 2) {
					cout << "Vos: Ni loco, no quiero" << endl;
					ia.sumarPuntos(3);
					cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
				}
			}
		}
	}
	//canta el jugador
	else {
		cout << "Vos: Truco..." << endl;
		//la IA puede responder quiero, no quiero, o reTruco
		int respuestaIA = respuestaTruco(3);
		if (respuestaIA == 1) {
			cout << "IA: Quiero" << endl;
			estanEnTruco = true;
		}
		else if(respuestaIA==2) {
			cout << "IA: No quiero" << endl;
			j1.sumarPuntos(1);
			cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
		}
		else {
			cout << "IA: Quiero re truco!" << endl;
			//el jugador puede responder quiero, no quiero o quiero vale 4.
			cout << "Que desea hacer?" << endl;
			cout << "1. Quiero 2. No quiero 3.Vale 4" << endl;
			int respuesta;
			cin >> respuesta;
			while (1 > respuesta && respuesta > 3) {
				cout << "Entrada invalida, ingrese nuevamente" << endl;
				cin >> respuesta;
			}
			if (respuesta == 1) {
				cout << "Vos: Quiero." << endl;
				estanEnVale4 == true;
			}
			else if (respuesta == 2) {
				cout << "Vos: No quiero." << endl;
				ia.sumarPuntos(2);
				cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
			}
			else {
				cout << "Vos: Quiero vale 4" << endl;
				respuestaIA = respuestaTruco(2);
				if (respuestaIA == 1) {
					cout << "IA: Quiero." << endl;
					estanEnVale4 = true;
				}
				else if (respuestaIA == 2) {
					cout << "IA: No quiero." << endl;
					j1.sumarPuntos(3);
					cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;

				}
			}
		}
	}
}