﻿// TrucoArgentino.cpp : Defines the entry point for the application.
//
#pragma once
#include "TrucoArgentino.h"

using namespace std;

void quienSeraMano(Jugador& j1, Jugador& ia) {
	bool moneda = rand() % 2;
	if (moneda) {
		j1.cambiarMano();
	}
	else {
		ia.cambiarMano();
	}
}

int main()
{
	/*TODO: REESTRUCTURAR LAS INSTANCIAS DE PARDAS. GUARDAR EN QUE RONDA SE EMPARDÓ*/
	srand(static_cast<unsigned int>(time(0)));//para arrancar eventos aleatorios
	cout << "Truco Argentino por consola!" << endl;

	Jugador j1;
	Jugador ia;
	Truco truco = Truco(j1, ia);
	bool seguirJugando = false;
	cout << "Presiona 1 para iniciar el juego" << endl;
	cin >> seguirJugando;
	if (!seguirJugando)cout << "Reinicie el programa para volver a jugar" << endl;
	
	while (seguirJugando) {
		while (!(j1.puntos() <= 15 && j1.estaEnBuenas()) && !(ia.puntos() <= 15 && ia.estaEnBuenas())) {
			quienSeraMano(j1, ia);
			truco.nuevaMano();
			while (truco.ronda() < 4) {
				if (truco.ronda()==1) {
					//Jugador es mano.
					if (j1.esMano()) {
						cout << "Sos mano" << endl;
						cout << "Nueva mano arranca:\n" <<  endl;
						cout << "Estas son tus cartas:" << endl;
						cout << "1. " << *(j1.mano()[0]) << ", 2. " << *(j1.mano()[1]) << ", 3. " << *(j1.mano()[2]) << endl;
						cout << "1. Cantar envido 2.Jugar una carta 3. Cantar truco" << endl;
						int decision;
						cin >> decision;
						if (decision == 1) {
							cantarEnvido(j1, ia, "jugador");//esto resuelve todo el envido.
							cout << "Que quieres hacer?\n" << "1. Jugar carta 2. Cantar truco" << endl;
							cin >> decision;
							if (decision == 1) {
								int cartaAJugar;
								cout << "Que carta quieres jugar?" << endl;
								for (int i = 0; i < j1.mano().size(); i++) {
									cout << i + 1 << ". " << *(j1.mano()[i]);
									if (i != 2)cout << ", ";
								}
								cout << endl;
								cin >> cartaAJugar;
								truco.jugarCarta(j1, ia, j1.mano()[cartaAJugar - 1], "jugador");

							}
							else if (decision == 2) {
								truco.cantarTruco(j1, ia, "jugador");//se canta truco y si se llega
								//a alguna instancia de este, siguen las manos/rondas.
								if (truco.estanEnAlgunaInstanciaTruco()) {
									int cartaAJugar;
									cout << "Que carta quieres jugar?" << endl;
									for (int i = 0; i < j1.mano().size(); i++) {
										cout << i + 1 << ". " << *(j1.mano()[i]);
										if (i != 2)cout << ", ";
									}
									cout << endl;
									cin >> cartaAJugar;
									truco.jugarCarta(j1, ia, j1.mano()[cartaAJugar - 1], "jugador");
								}
								
							}

						}
						else if (decision == 2) {
							int cartaAJugar;
							cout << "Que carta quieres jugar?" << endl;
							for (int i = 0; i < j1.mano().size(); i++) {
								cout << i + 1 << ". " << *(j1.mano()[i]);
								if (i != 2)cout << ", ";
							}
							cout << endl;
							cin >> cartaAJugar;


							truco.jugarCarta(j1, ia, j1.mano()[cartaAJugar - 1], "jugador");

						}//se canta truco
						else if (decision == 3) {
							truco.cantarTruco(j1, ia, "jugador");//se canta truco y si se llega
							//a alguna instancia de este, siguen las manos/rondas.
							if (truco.estanEnAlgunaInstanciaTruco()) {
								int cartaAJugar;
								cout << "Que carta quieres jugar?" << endl;
								for (int i = 0; i < j1.mano().size(); i++) {
									cout << i + 1 << ". " << *(j1.mano()[i]);
									if (i != 2)cout << ", ";
								}
								cout << endl;
								cin >> cartaAJugar;
								truco.jugarCarta(j1, ia, j1.mano()[cartaAJugar - 1], "jugador");
							}
							//else {si no estan en truco, termina la ronda.}

						}

					}

					//la IA es mano
					else if (ia.esMano()) {
						
						cout << "IA es mano." << endl;
						int decisionIA = respuestaPrimeraMano();
						cout << "Estas son tus cartas:\n" << "1. " << *(j1.mano()[0]) << " 2. " << *(j1.mano()[1]) << " 3. " << *(j1.mano()[2]) << endl;

						//IA canta envido
						if (decisionIA == 1) {
							cantarEnvido(j1, ia, "ia");
						}//IA canta truco
						else if (decisionIA == 3) {
							truco.cantarTruco(j1, ia, "ia");
						}
						//luego de que se haya cantado envido o truco, se juega carta. Hay que ver si se llego a alguna intancia truco.
						if ((decisionIA == 3 && truco.estanEnAlgunaInstanciaTruco()) || decisionIA == 1 || decisionIA == 2) {
							Carta* cartaIA = ia.mano()[eleccionDeCarta(ia.mano())];
							cout << "IA juega: " << *cartaIA << endl;

							if (decisionIA == 2 || decisionIA == 1) {
								cout << "Que quieres hacer?\n1.Jugar carta 2.Cantar Truco" << endl;
								int decisionJugador;
								cin >> decisionJugador;
								if (decisionJugador == 2)truco.cantarTruco(j1, ia, "jugador");
							}
							else {
								cout << "Que carta juegas?" << endl;
								for (int i = 0; i < j1.mano().size(); i++) {
									cout << i + 1 << "." << *(j1.mano()[i]);
									if (i != j1.mano().size() - 1)cout << ", ";
								}
								cout << endl;
								int eleccionJugador;
								cin >> eleccionJugador;
								while (1 > eleccionJugador && eleccionJugador > 2) {
									cout << "Entrada invalida, ingrese nuevamente." << endl;
									cin >> eleccionJugador;
								}

								Carta* cartaJugador = j1.mano()[eleccionJugador - 1];

								truco.jugarCarta(j1, ia, cartaIA, "ia");
								truco.quienGana(j1, cartaJugador, ia, cartaIA);
								j1.tirarCartaJugada(cartaJugador);

							}
						}//se canto truco y no se quiso
			
					}

				}
				else if (truco.ronda() == 2) {
					/*hay que ver quien gano la ronda anterior.
					luego hay que ver si estan en alguna instancia de truco.
					si estan en truco, hay que ver en que instancia de truco estan para ver si se quiere
					cantar una instancia nueva o simplemente jugar una carta.
					si no estan en truco, hay que dar la posibilidad de cantarlo.*/
					if (j1.gano() || (truco.esParda && j1.esMano())) {//tambien vale si estan en parda pues j1 es mano y se repetiria el codigo con algunas cosas extra que las puedo incluir aca con un condicional.
						if (truco.estanEnAlgunaInstanciaTruco() && ia.cantoAnteriorTruco) {
							int decision = 0;
							if (truco.estanEnInstanciaTruco()) {
								cout << "1. Jugar Carta 2.Cantar Re Truco" << endl;
								cin >> decision;
							}
							else if (truco.estanEnInstanciaReTruco()) {
								cout << "1. Jugar Carta 2.Cantar Vale 4";
								cin >> decision;
							}
							//estan en vale4. Se accede solo cuando no hay decision
							else {
								cout << "Que carta juegas?" << endl;
								for (int i = 0; i < j1.mano().size(); i++) {
									cout << i + 1 << "." << *(j1.mano()[i]);
									if (i != j1.mano().size())cout << ", ";
								}
								int eleccionJugador;
								cin >> eleccionJugador;
								while (1 > eleccionJugador || eleccionJugador > 2) {
									cout << "Entrada invalida, ingrese nuevamente." << endl;
									cin >> eleccionJugador;
								}
								cout << endl;

								truco.jugarCarta(j1, ia, j1.mano()[eleccionJugador - 1], "jugador");

								if (truco.esParda && j1.ganoPrimera()) {//significa que empardaron primera y j1 gano segunda.
									j1.sumarPuntos(4);
									j1.cambiarMano();
									ia.cambiarMano();
									truco.nuevaMano();
								}
								else if (truco.esParda && ia.ganoPrimera()) {

									ia.sumarPuntos(4);
									j1.cambiarMano();
									ia.cambiarMano();
									truco.nuevaMano();

								}
								//esto significa que empardaron 1ra y segunda.
								else if (truco.esParda) {
									//no se hace nada, queda ver que sucede en la 3ra ronda.
								}

							}
							//si no hubo desicion no se accede al siguiente codigo.
							if (decision == 1) {
								int cartaAJugar;
								cout << "Que carta quieres jugar?" << endl;
								for (int i = 0; i < j1.mano().size(); i++) {
									cout << i + 1 << ". " << *(j1.mano()[i]);
									if (i != 2)cout << ", ";
								}
								cout << endl;
								cin >> cartaAJugar;
								Carta* cartaJugador = j1.mano()[cartaAJugar - 1];
								truco.jugarCarta(j1, ia, cartaJugador, "jugador");


							}
							else if (decision == 2) {
								if (truco.estanEnInstanciaTruco()) {
									truco.cantarReTruco(j1, ia, "jugador");
								}
								else {
									truco.cantarVale4(j1, ia, "jugador");
								}
								//si se llega a alguna instancia de truco, jugador juega una carta
								if (truco.estanEnAlgunaInstanciaTruco()) {
									cout << "Que carta juegas?" << endl;
									for (int i = 0; i < j1.mano().size(); i++) {
										cout << i + 1 << "." << *(j1.mano()[i]);
										if (i < j1.mano().size() - 1)cout << ", ";
									}
									cout << endl;
									int eleccionJugador;
									cin >> eleccionJugador;
									while (1 > eleccionJugador || eleccionJugador > 2) {
										cout << "Entrada invalida, ingrese nuevamente." << endl;
										cin >> eleccionJugador;
									}
									Carta* cartaJugador = j1.mano()[eleccionJugador - 1];
									truco.jugarCarta(j1, ia, cartaJugador, "jugador");

									if (truco.esParda && j1.ganoPrimera()) {
										if (truco.estanEnInstanciaReTruco())j1.sumarPuntos(3);
										if (truco.estanEnInstanciaVale4())j1.sumarPuntos(4);
										j1.cambiarMano();
										ia.cambiarMano();
										truco.nuevaMano();
									}
									else if (truco.esParda && ia.ganoPrimera()) {
										if (truco.estanEnInstanciaReTruco())ia.sumarPuntos(3);
										if (truco.estanEnInstanciaVale4())ia.sumarPuntos(4);
										j1.cambiarMano();
										ia.cambiarMano();
										truco.nuevaMano();
									}
									//si se emparda la segunda tambien, se ve en la 3ra.
								}
								//si no se llega a nada, se termina la mano.
								
							}
						}
						else if (truco.estanEnAlgunaInstanciaTruco() && j1.cantoAnteriorTruco) {
							cout << "Que carta juegas?" << endl;
							for (int i = 0; i < j1.mano().size(); i++) {
								cout << i + 1 << "." << *(j1.mano()[i]);
								if (i != j1.mano().size())cout << ", ";
							}
							int eleccionJugador;
							cin >> eleccionJugador;
							while (1 > eleccionJugador || eleccionJugador > 2) {
								cout << "Entrada invalida, ingrese nuevamente." << endl;
								cin >> eleccionJugador;
							}
							Carta* cartaJugador = j1.mano()[eleccionJugador - 1];
							truco.jugarCarta(j1, ia, cartaJugador, "jugador");

							if (truco.esParda && j1.ganoPrimera()) {
								if (truco.estanEnInstanciaReTruco())j1.sumarPuntos(3);
								if (truco.estanEnInstanciaVale4())j1.sumarPuntos(4);
								j1.cambiarMano();
								ia.cambiarMano();
								truco.nuevaMano();
							}
							else if (truco.esParda && ia.ganoPrimera()) {
								if (truco.estanEnInstanciaReTruco())ia.sumarPuntos(3);
								if (truco.estanEnInstanciaVale4())ia.sumarPuntos(4);
								j1.cambiarMano();
								ia.cambiarMano();
								truco.nuevaMano();
							}
							//si se emparda la segunda tambien, se ve en la 3ra.

						}
						//no se canto truco
						else {
							cout << "Que quieres hacer?\n1.Jugar carta 2.Cantar Truco" << endl;
							int decision;
							cin >> decision;
							while (1 > decision || 3 < decision) {
								cout << "Entrada invalida, ingrese nuevamente" << endl;
								cin >> decision;
							}
							//Jugador Juega carta
							if (decision == 1) {
								cout << "Que carta juegas?" << endl;
								for (int i = 0; i < j1.mano().size(); i++) {
									cout << i + 1 << "." << *(j1.mano()[i]);
									if (i != j1.mano().size())cout << ", ";
								}
								int eleccionJugador;
								cin >> eleccionJugador;
								while (1 > eleccionJugador || eleccionJugador > 2) {
									cout << "Entrada invalida, ingrese nuevamente." << endl;
									cin >> eleccionJugador;
								}
								cout << endl;
								Carta* cartaJugador = j1.mano()[eleccionJugador - 1];
								truco.jugarCarta(j1, ia, cartaJugador, "jugador");

								if (truco.esParda && j1.ganoPrimera()) {
									if (truco.estanEnInstanciaTruco())j1.sumarPuntos(2);
									if (truco.estanEnInstanciaReTruco())j1.sumarPuntos(3);
									if (truco.estanEnInstanciaVale4())j1.sumarPuntos(4);
									j1.cambiarMano();
									ia.cambiarMano();
									truco.nuevaMano();
								}
								else if (truco.esParda && ia.ganoPrimera()) {
									if (truco.estanEnInstanciaTruco())ia.sumarPuntos(2);
									if (truco.estanEnInstanciaReTruco())ia.sumarPuntos(3);
									if (truco.estanEnInstanciaVale4())ia.sumarPuntos(4);
									j1.cambiarMano();
									ia.cambiarMano();
									truco.nuevaMano();
								}
								//si se emparda la segunda tambien, se ve en la 3ra.

							}
							//Jugadro canta truco
							else if (decision == 2) {
								truco.cantarTruco(j1, ia, "jugador");
								//si se llega a una intancia de truco se juega una carta.
								if (truco.estanEnAlgunaInstanciaTruco()) {
									cout << "Que carta juegas?" << endl;
									for (int i = 0; i < j1.mano().size(); i++) {
										cout << i + 1 << "." << *(j1.mano()[i]);
										if (i != j1.mano().size() - 1)cout << ", ";
									}
									cout << endl;
									int eleccionJugador;
									cin >> eleccionJugador;
									while (1 > eleccionJugador || eleccionJugador > 2) {
										cout << "Entrada invalida, ingrese nuevamente." << endl;
										cin >> eleccionJugador;
									}
									Carta* cartaJugador = j1.mano()[eleccionJugador - 1];
									truco.jugarCarta(j1, ia, cartaJugador, "jugador");

									//si se gano la primera ronda y se empardo la segunda:
									if (truco.esParda && (j1.ganoPrimera()||j1.gano())) {
										if (truco.estanEnInstanciaTruco())j1.sumarPuntos(2);
										if (truco.estanEnInstanciaReTruco())j1.sumarPuntos(3);
										if (truco.estanEnInstanciaVale4())j1.sumarPuntos(4);
										j1.cambiarMano();
										ia.cambiarMano();
										truco.nuevaMano();
									}
									else if (truco.esParda && (ia.ganoPrimera())||ia.gano()) {
										if (truco.estanEnInstanciaTruco())ia.sumarPuntos(2);
										if (truco.estanEnInstanciaReTruco())ia.sumarPuntos(3);
										if (truco.estanEnInstanciaVale4())ia.sumarPuntos(4);
										j1.cambiarMano();
										ia.cambiarMano();
										truco.nuevaMano();
									}
									//si se emparda la segunda tambien, se ve en la 3ra.
								}
								//si no quiso se termina la mano.
								

							}
						}
					}
					//gano la ia la primera ronda

					else if (ia.gano()||(truco.esParda && ia.esMano())) {
						if (truco.estanEnAlgunaInstanciaTruco() && ia.cantoAnteriorTruco) {
							//IA solo puede jugar una carta.
							Carta* cartaElegidaIA = ia.mano()[eleccionDeCarta(ia.mano())];
							cout << "IA juega: " << *cartaElegidaIA << endl;
							//el jugador puede responder con otro truco o solo tirar una carta
							int decisionJugador = 0;

							if (truco.estanEnInstanciaTruco()) {
								cout << "Que va a hacer?\n1.Jugar carta 2.Cantar retruco" << endl;
								cin >> decisionJugador;
							}
							else if (truco.estanEnInstanciaReTruco()) {
								cout << "Que va a hacer?\n1.Jugar carta 2.Cantar Vale 4" << endl;
								cin >> decisionJugador;
							}
							//estan en vale 4, solo se accede si no hubo decision.
							else {
								cout << "IA juega: " << *cartaElegidaIA << endl;
								cout << "Que carta quieres jugar?" << endl;
								for (int i = 0; i < j1.mano().size(); i++) {
									cout << i + 1 << "." << *(j1.mano()[i]);
									if (i != j1.mano().size())cout << ", ";
								}
								int cartaAJugar;
								cin >> cartaAJugar;
								Carta* cartaJugador = j1.mano()[cartaAJugar - 1];

								truco.jugarCarta(j1, ia, cartaElegidaIA, "ia");
								truco.quienGana(j1, cartaJugador, ia, cartaElegidaIA);
								j1.tirarCartaJugada(cartaJugador);

								if (truco.esParda && j1.ganoPrimera()) {
									j1.sumarPuntos(4);
									j1.cambiarMano();
									ia.cambiarMano();
									truco.nuevaMano();
								}
								else if (truco.esParda && ia.ganoPrimera()) {
									ia.sumarPuntos(4);
									j1.cambiarMano();
									ia.cambiarMano();
									truco.nuevaMano();
								}
								//si se emparda la segunda tambien, se ve en la 3ra.

							}
							//jugador juega carta, si no se decidio nada, no se ejecuta esta parte.
							if (decisionJugador == 1) {
								cout << "Que carta juegas?" << endl;
								for (int i = 0; i < j1.mano().size(); i++) {
									cout << i + 1 << "." << *(j1.mano()[i]);
									if (i != j1.mano().size())cout << ", ";
								}
								int eleccionJugador;
								cin >> eleccionJugador;
								while (1 > eleccionJugador && eleccionJugador > 2) {
									cout << "Entrada invalida, ingrese nuevamente." << endl;
									cin >> eleccionJugador;
								}
								Carta* cartaJugador = j1.mano()[eleccionJugador - 1];
								//calculo que carta gano
								truco.jugarCarta(j1, ia, cartaElegidaIA, "ia");
								truco.quienGana(j1, cartaJugador, ia, cartaElegidaIA);
								j1.tirarCartaJugada(cartaJugador);

								if (truco.esParda && j1.ganoPrimera()) {
									if (truco.estanEnInstanciaTruco())j1.sumarPuntos(2);
									if (truco.estanEnInstanciaReTruco())j1.sumarPuntos(3);
									if (truco.estanEnInstanciaVale4())j1.sumarPuntos(4);
									j1.cambiarMano();
									ia.cambiarMano();
									truco.nuevaMano();
								}
								else if (truco.esParda && ia.ganoPrimera()) {
									if (truco.estanEnInstanciaTruco())ia.sumarPuntos(2);
									if (truco.estanEnInstanciaReTruco())ia.sumarPuntos(3);
									if (truco.estanEnInstanciaVale4())ia.sumarPuntos(4);
									j1.cambiarMano();
									ia.cambiarMano();
									truco.nuevaMano();
								}
								//si se emparda la segunda tambien, se ve en la 3ra.

							}
							//jugador canta retruco/vale 4
							else if (decisionJugador == 2) {
								if (truco.estanEnInstanciaTruco()) {
									truco.cantarReTruco(j1, ia, "jugador");
								}
								else {
									truco.cantarVale4(j1, ia, "jugador");
								}
								//si se llega a alguna instancia de truco, jugador juega una carta
								if (truco.estanEnAlgunaInstanciaTruco()) {
									cout << "Que carta juegas?" << endl;
									for (int i = 0; i < j1.mano().size(); i++) {
										cout << i + 1 << "." << *(j1.mano()[i]);
										if (i != j1.mano().size())cout << ", ";
									}
									int eleccionJugador;
									cin >> eleccionJugador;
									while (1 > eleccionJugador || eleccionJugador > 2) {
										cout << "Entrada invalida, ingrese nuevamente." << endl;
										cin >> eleccionJugador;
									}
									Carta* cartaJugador = j1.mano()[eleccionJugador - 1];
									truco.jugarCarta(j1, ia, cartaElegidaIA, "ia");
									truco.quienGana(j1, cartaJugador, ia, cartaElegidaIA);
									j1.tirarCartaJugada(cartaJugador);


									if (truco.esParda && j1.ganoPrimera()) {
										if (truco.estanEnInstanciaReTruco())j1.sumarPuntos(3);
										if (truco.estanEnInstanciaVale4())j1.sumarPuntos(4);
										j1.cambiarMano();
										ia.cambiarMano();
										truco.nuevaMano();
									}
									else if (truco.esParda && ia.ganoPrimera()) {
										if (truco.estanEnInstanciaReTruco())ia.sumarPuntos(3);
										if (truco.estanEnInstanciaVale4())ia.sumarPuntos(4);
										j1.cambiarMano();
										ia.cambiarMano();
										truco.nuevaMano();
									}
									//si se emparda la segunda tambien, se ve en la 3ra.

								}
								//si no se llega a nada, se termina la mano.
								
							}
						}
						else if (truco.estanEnAlgunaInstanciaTruco() && j1.cantoAnteriorTruco) {
							//Ia puede tirar carta o cantar re truco.
							int decisionIA = decisionSegundaMano();
							//IA juega carta
							if (decisionIA == 1) {
								int cartaElegidaIA = eleccionDeCarta(ia.mano());
								Carta* eleccionIA = ia.mano()[cartaElegidaIA];
								cout << "IA juega: " << *eleccionIA << endl;
								cout << "Que carta juegas?" << endl;
								for (int i = 0; i < j1.mano().size(); i++) {
									cout << i + 1 << "." << *(j1.mano()[i]);
									if (i != j1.mano().size())cout << ", ";
								}
								int eleccionJugador;
								cin >> eleccionJugador;
								while (1 > eleccionJugador && eleccionJugador > 2) {
									cout << "Entrada invalida, ingrese nuevamente." << endl;
									cin >> eleccionJugador;
								}
								Carta* eleccionJ1 = j1.mano()[eleccionJugador - 1];
								truco.jugarCarta(j1, ia, eleccionIA, "ia");
								truco.quienGana(j1, eleccionJ1, ia, eleccionIA);
								j1.tirarCartaJugada(eleccionJ1);

							}
							//IA canta retruco
							else if (decisionIA == 2) {
								truco.cantarReTruco(j1, ia, "ia");
								//si se llega a una instancia de truco, se juega una carta.
								if (truco.estanEnAlgunaInstanciaTruco()) {
									int cartaElegidaIA = eleccionDeCarta(ia.mano());
									Carta* eleccionIA = ia.mano()[cartaElegidaIA];
									cout << "Que carta juegas?" << endl;
									for (int i = 0; i < j1.mano().size(); i++) {
										cout << i + 1 << "." << *(j1.mano()[i]);
										if (i != j1.mano().size())cout << ", ";
									}
									int eleccionJugador;
									cin >> eleccionJugador;
									while (1 > eleccionJugador && eleccionJugador > 2) {
										cout << "Entrada invalida, ingrese nuevamente." << endl;
										cin >> eleccionJugador;
									}
									Carta* eleccionJ1 = j1.mano()[eleccionJugador - 1];
									truco.quienGana(j1, eleccionJ1, ia, eleccionIA);
									j1.tirarCartaJugada(eleccionJ1);
									truco.jugarCarta(j1, ia, eleccionIA, "ia");
								}
								
							}
						}
						//no se canto truco
						else {
							//La IA puede entonce jugar una carta o cantar Truco
							int decisionIA = decisionSegundaMano();
							//la IA juega una carta
							if (decisionIA == 1) {
								Carta* cartaElegidaIA = ia.mano()[eleccionDeCarta(ia.mano())];
								cout << "IA juega: " << *cartaElegidaIA << endl;
								//TODO: el jugador puede cantar truco en esta instancia.

								cout << "1.Jugar carta 2.Cantar truco" << endl;
								int decision;
								cin >> decision;
								if (decision == 2) {
									truco.cantarTruco(j1, ia, "jugador");
								}
								if (decision == 1 || truco.estanEnAlgunaInstanciaTruco()) {
									cout << "Que carta juegas?" << endl;
									for (int i = 0; i < j1.mano().size(); i++) {
										cout << i + 1 << "." << *(j1.mano()[i]);
										if (i != j1.mano().size() - 1)cout << ", ";
									}
									cout << endl;
									int eleccionJugador;
									cin >> eleccionJugador;
									while (1 > eleccionJugador && eleccionJugador > 2) {
										cout << "Entrada invalida, ingrese nuevamente." << endl;
										cin >> eleccionJugador;
									}

									Carta* cartaJugador = j1.mano()[eleccionJugador - 1];
									cout << "Tu juegas: " << *cartaJugador << endl;

									truco.jugarCarta(j1, ia, cartaElegidaIA, "ia");
									truco.quienGana(j1, cartaJugador, ia, cartaElegidaIA);
									j1.tirarCartaJugada(cartaJugador);
								}
								
							}
							//IA canta truco
							else if (decisionIA == 2) {
								truco.cantarTruco(j1, ia, "ia");
								//si se llega a una instancia de truco, se juega una carta.
								if (truco.estanEnAlgunaInstanciaTruco()) {
									Carta* cartaElegidaIA = ia.mano()[eleccionDeCarta(ia.mano())];
									cout << "IA juega: " << *cartaElegidaIA << endl;
									cout << "Que carta juegas?" << endl;
									for (int i = 0; i < j1.mano().size(); i++) {
										cout << i + 1 << "." << *(j1.mano()[i]);
										if (i != j1.mano().size() - 1)cout << ", ";
									}
									cout << endl;
									int eleccionJugador;
									cin >> eleccionJugador;
									while (1 > eleccionJugador && eleccionJugador > 2) {
										cout << "Entrada invalida, ingrese nuevamente." << endl;
										cin >> eleccionJugador;
									}

									Carta* cartaJugador = j1.mano()[eleccionJugador - 1];

									truco.jugarCarta(j1, ia, cartaElegidaIA, "ia");
									truco.quienGana(j1, cartaJugador, ia, cartaElegidaIA);
									j1.tirarCartaJugada(cartaJugador);

								}
								
							}

						}

					}
					else if (ia.gano() && ia.ganoPrimera()) {
						if (truco.estanEnInstanciaTruco()) {
							ia.sumarPuntos(2);
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
						else if (truco.estanEnInstanciaReTruco()) {
							ia.sumarPuntos(3);
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
						else {
							ia.sumarPuntos(4);
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
					}
					else if (j1.gano() && j1.ganoPrimera()) {
						if (truco.estanEnInstanciaTruco()) {
							j1.sumarPuntos(2);
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
						else if (truco.estanEnInstanciaReTruco()) {
							j1.sumarPuntos(3);
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
						else {
							j1.sumarPuntos(4);
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
					}
					}
				else if (truco.ronda() == 3) {
					//si llegue a la 3ra habiendo parda en 1ra y segunda, defino aca.
					if (truco.esParda) {

					}
					
					//jugador gano segunda mano
					if (j1.gano()) {
						if (j1.ganoPrimera()) {

							//significa que el jugador gano tanto primera como segunda, sumo sus puntos y termino la mano.
							if (truco.estanEnInstanciaTruco())j1.sumarPuntos(2);
							if (truco.estanEnInstanciaReTruco())j1.sumarPuntos(3);
							if (truco.estanEnInstanciaVale4())j1.sumarPuntos(4);
							if (!truco.estanEnAlgunaInstanciaTruco())j1.sumarPuntos(1);
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();

						}
						//empieza tirando carta el jugador, analizo en que instancia de truco estoy y quien lo canto.
						else if (truco.estanEnAlgunaInstanciaTruco() && ia.cantoAnteriorTruco) {
							int decision = 0;
							if (truco.estanEnInstanciaTruco()) {
								cout << "1. Jugar Carta 2.Cantar Re Truco" << endl;
								cin >> decision;
							}
							else if (truco.estanEnInstanciaReTruco()) {
								cout << "1. Jugar Carta 2.Cantar Vale 4";
								cin >> decision;
							}
							//estan en vale4. Se accede solo cuando no hay decision
							else {

								truco.jugarCarta(j1, ia, j1.mano()[0], "jugador");

							}
							//si no hubo desicion no se accede al siguiente codigo.
							if (decision == 1) {

								truco.jugarCarta(j1, ia, j1.mano()[0], "jugador");
							}
							else if (decision == 2) {
								if (truco.estanEnInstanciaTruco()) {
									truco.cantarReTruco(j1, ia, "jugador");
								}
								else {
									truco.cantarVale4(j1, ia, "jugador");
								}
								//si se llega a alguna instancia de truco, jugador juega una carta
								if (truco.estanEnAlgunaInstanciaTruco()) {

									truco.jugarCarta(j1, ia, j1.mano()[0], "jugador");
								}
								//si no se llega a nada, se termina la mano.
								
							}
						}
						else if (truco.estanEnAlgunaInstanciaTruco() && j1.cantoAnteriorTruco) {
							truco.jugarCarta(j1, ia, j1.mano()[0], "jugador");
						}
						//no se canto truco
						else {
							cout << "Que quieres hacer?\n1.Jugar carta 2.Cantar Truco" << endl;
							int decision;
							cin >> decision;
							while (1 > decision || 2 < decision) {
								cout << "Entrada invalida, ingrese nuevamente" << endl;
								cin >> decision;
							}
							//Jugador Juega carta
							if (decision == 1) {


								truco.jugarCarta(j1, ia, j1.mano()[0], "jugador");

							}
							//Jugadro canta truco
							else if (decision == 2) {
								truco.cantarTruco(j1, ia, "jugador");
								//si se llega a una intancia de truco se juega una carta.
								if (truco.estanEnAlgunaInstanciaTruco()) {

									truco.jugarCarta(j1, ia, j1.mano()[0], "jugador");
								}
								//si no quiso se termina la mano.
								

							}
						}
					}
					//ia gano segunda mano
					else if (ia.gano()) {
						//empieza tirando carta la IA, hay que analizar en que instancia de truco esta.
						if (ia.ganoPrimera()) {
							//significa que la ia gano tanto primera como segunda, sumo sus puntos y termino la mano.
							if (truco.estanEnInstanciaTruco())ia.sumarPuntos(2);
							if (truco.estanEnInstanciaReTruco())ia.sumarPuntos(3);
							if (truco.estanEnInstanciaVale4())ia.sumarPuntos(4);
							if (!truco.estanEnAlgunaInstanciaTruco())ia.sumarPuntos(1);
							cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
						else if (truco.estanEnAlgunaInstanciaTruco() && ia.cantoAnteriorTruco) {
							//IA solo puede jugar una carta.

							cout << "IA juega: " << *(ia.mano()[0]) << endl;
							//el jugador puede responder con otro truco(a no ser que esten en vale 4) o solo tirar una carta
							int decisionJugador = 0;

							if (truco.estanEnInstanciaTruco()) {
								cout << "Que va a hacer?\n1.Jugar carta 2.Cantar retruco" << endl;
								cin >> decisionJugador;
							}
							else if (truco.estanEnInstanciaReTruco()) {
								cout << "Que va a hacer?\n1.Jugar carta 2.Cantar Vale 4" << endl;
								cin >> decisionJugador;
							}
							//estan en vale 4, solo se accede si no hubo decision.
							else {
								cout << "IA juega: " << *(ia.mano()[0]) << endl;
								cout << "Vos jugas: " << *(j1.mano()[0]) << endl;

								truco.jugarCarta(j1, ia, ia.mano()[0], "ia");
								truco.quienGana(j1, j1.mano()[0], ia, ia.mano()[0]);
								j1.tirarCartaJugada(j1.mano()[0]);
							}
							//jugador juega carta, si no se decidio nada, no se ejecuta esta parte.
							if (decisionJugador == 1) {
								cout << "Vos jugas: " << *(j1.mano()[0]) << endl;

								//calculo que carta gano
								truco.jugarCarta(j1, ia, ia.mano()[0], "ia");
								truco.quienGana(j1, j1.mano()[0], ia, ia.mano()[0]);
								j1.tirarCartaJugada(j1.mano()[0]);
							}
							//jugador canta retruco/vale 4
							else if (decisionJugador == 2) {
								if (truco.estanEnInstanciaTruco()) {
									truco.cantarReTruco(j1, ia, "jugador");
								}
								else {
									truco.cantarVale4(j1, ia, "jugador");
								}
								//si se llega a alguna instancia de truco, jugador juega una carta
								if (truco.estanEnAlgunaInstanciaTruco()) {
									Carta* cartaJugador = j1.mano()[0];
									Carta* cartaIA = ia.mano()[0];

									cout << "Tu juegas: " << *cartaJugador << "\nIA juega: " << *cartaIA << endl;

									truco.quienGana(j1, cartaJugador, ia, cartaIA);
									j1.tirarCartaJugada(cartaJugador);
									truco.jugarCarta(j1, ia, cartaIA, "ia");
								}
								//si no se llega a nada, se termina la mano.
								
							}
						}
						else if (truco.estanEnAlgunaInstanciaTruco() && j1.cantoAnteriorTruco) {
							//Ia puede tirar carta o cantar re truco.
							int decisionIA = decisionSegundaMano();
							//IA juega carta
							if (decisionIA == 1) {

								Carta* eleccionIA = ia.mano()[0];
								Carta* eleccionJ1 = j1.mano()[0];

								cout << "IA juega: " << *eleccionIA << endl;
								cout << "Vos jugas: " << *eleccionJ1 << endl;

								truco.jugarCarta(j1, ia, eleccionIA, "ia");
								truco.quienGana(j1, eleccionJ1, ia, eleccionIA);
								j1.tirarCartaJugada(eleccionJ1);

							}
							//IA canta retruco
							else if (decisionIA == 2) {
								truco.cantarReTruco(j1, ia, "ia");
								//si se llega a una instancia de truco, se juega una carta.
								if (truco.estanEnAlgunaInstanciaTruco()) {

									Carta* eleccionIA = ia.mano()[0];
									Carta* eleccionJ1 = j1.mano()[0];

									cout << "IA juega: " << *eleccionIA << endl;
									cout << "Vos jugas: " << *eleccionJ1 << endl;

									truco.jugarCarta(j1, ia, eleccionIA, "ia");
									truco.quienGana(j1, eleccionJ1, ia, eleccionIA);
									j1.tirarCartaJugada(eleccionJ1);

								}
								
							}
							//no se canto truco
							else {
								//La IA puede entonce jugar una carta o cantar Truco
								int decisionIA = decisionSegundaMano();
								//la IA juega una carta
								if (decisionIA == 1) {
									Carta* eleccionIA = ia.mano()[0];
									Carta* eleccionJ1 = j1.mano()[0];

									cout << "IA juega: " << *eleccionIA << endl;
									cout << "Vos jugas: " << *eleccionJ1 << endl;

									truco.jugarCarta(j1, ia, eleccionIA, "ia");
									truco.quienGana(j1, eleccionJ1, ia, eleccionIA);
									j1.tirarCartaJugada(eleccionJ1);

								}
								//IA canta truco
								else if (decisionIA == 2) {
									truco.cantarTruco(j1, ia, "ia");
									//si se llega a una instancia de truco, se juega una carta.
									if (truco.estanEnAlgunaInstanciaTruco()) {
										Carta* eleccionIA = ia.mano()[0];
										Carta* eleccionJ1 = j1.mano()[0];

										cout << "IA juega: " << *eleccionIA << endl;
										cout << "Vos jugas: " << *eleccionJ1 << endl;

										truco.jugarCarta(j1, ia, eleccionIA, "ia");
										truco.quienGana(j1, eleccionJ1, ia, eleccionIA);
										j1.tirarCartaJugada(eleccionJ1);


									}
									
								}
							}
						}
					}
					//veo quien gano los puntos finales.
					//primero hay que ver si quedaron en parda en la 3ra ronda, en ese caso gana la primera.
					//si no hay parda, entonces sumo los puntos a quien haya ganado la 3ra mano.
					if (truco.esParda && ia.ganoPrimera()) {
						if (truco.estanEnInstanciaTruco()) {
							ia.sumarPuntos(2);
							cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
						else if (truco.estanEnInstanciaReTruco()) {
							ia.sumarPuntos(3);
							cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
						else {
							ia.sumarPuntos(4);
							cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
					}
					else if (truco.esParda && j1.ganoPrimera()) {
						if (truco.estanEnInstanciaTruco()) {
							j1.sumarPuntos(2);
							cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
						else if (truco.estanEnInstanciaReTruco()) {
							j1.sumarPuntos(3);
							cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
						else {
							j1.sumarPuntos(4);
							cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
					}
					else if (ia.gano()) {
						if (truco.estanEnInstanciaTruco()) {
							ia.sumarPuntos(2);
							cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
						else if (truco.estanEnInstanciaReTruco()) {
							ia.sumarPuntos(3);
							cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
						else {
							ia.sumarPuntos(4);
							cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
					}
					else if (j1.gano()) {
						if (truco.estanEnInstanciaTruco()) {
							j1.sumarPuntos(2);
							cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
						else if (truco.estanEnInstanciaReTruco()) {
							j1.sumarPuntos(3);
							cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
						else {
							j1.sumarPuntos(4);
							cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
							truco.nuevaMano();
							j1.cambiarMano();
							ia.cambiarMano();
						}
					}
					}

				//si un jugador ya gano, termino el ciclo.
				if (j1.puntos() == 15 || ia.puntos() == 15) {
					if (j1.estaEnBuenas() || ia.estaEnBuenas()) {
						if (j1.puntos() == 15 && j1.estaEnBuenas()) {
							cout << "Jugador ha ganado la partida" << endl;
						}
						else if (ia.estaEnBuenas() && ia.puntos() == 15) {
							cout << "La IA ha ganado la partida" << endl;
						}
						break;
					}
				}

			}
			break;//hasta que no implemente cuando IA sea mano, lo dejo para debugear mas rapido.
		}
		cout << "Iniciar nueva partida? Presione 0 para termiar el juego o presione cualquier otra tecla para volver a jugar" << endl;
		cin >> seguirJugando;
		if (seguirJugando != 0)seguirJugando = 1;
		truco.reestablecerJuego();
	}
	return 0;
}
	
