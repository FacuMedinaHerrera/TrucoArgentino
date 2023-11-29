// TrucoArgentino.cpp : Defines the entry point for the application.
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
	//truco.repartir(j1,ia);
	//cout << *(j1.mano()[0]);
	srand(static_cast<unsigned int>(time(0)));//para arrancar eventos aleatorios
	cout << "Truco Argentino por consola!" << endl;

	Jugador j1;
	Jugador ia;
	Truco truco = Truco(j1, ia);
	bool seguirJugando = false;
	cout << "Presiona 1 para iniciar el juego" << endl;
	cin >> seguirJugando;
	if (seguirJugando == 0)seguirJugando = 1;

	while (seguirJugando) {
		quienSeraMano(j1, ia);
		while (!(j1.puntos() <= 15 && j1.estaEnBuenas()) && !(ia.puntos() <= 15 && ia.estaEnBuenas())) {
			truco.nuevaMano();
			cout << "Estas son tus cartas:" << endl;
			cout << "1. " << *(j1.mano()[0]) << " , 2. " << *(j1.mano()[1]) << " , 3. " << *(j1.mano()[2]) << endl;
			if (j1.esMano()) {
				cout << "Sos mano, que queres hacer?" << endl;
				while (truco.ronda() < 4) {
					if (truco.ronda() == 1) {
						int decision;
						cout << "1. Cantar envido 2.Jugar una carta 3. Cantar truco" << endl;
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
								//else {si no estan en truco, termina la ronda.}							
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
					else if (truco.ronda() == 2) {
						/*hay que ver quien gano la ronda anterior.
						luego hay que ver si estan en alguna instancia de truco.
						si estan en truco, hay que ver en que instancia de truco estan para ver si se quiere
						cantar una instancia nueva o simplemente jugar una carta.
						si no estan en truco, hay que dar la posibilidad de cantarlo.*/
						if (j1.gano()) {
							if (truco.estanEnInstanciaTruco() && ia.cantoAnteriorTruco) {
								int decision;
								cout << "1. Jugar Carta 2.Cantar Re Truco";
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
									truco.cantarReTruco(j1, ia, "jugador");
									//si se llega a alguna instancia de truco, jugador juega una carta
									if (truco.estanEnAlgunaInstanciaTruco()) {
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
										truco.jugarCarta(j1, ia, j1.mano()[eleccionJugador], "jugador");
									}
								}
							}
							else if (truco.estanEnInstanciaTruco() && j1.cantoAnteriorTruco) {
								
							}
							else if (truco.estanEnInstanciaReTruco() && j1.cantoAnteriorTruco) {

							}
							else if (truco.estanEnInstanciaReTruco() && ia.cantoAnteriorTruco) {

							}
							else if (truco.estanEnInstanciaVale4()) {

							}
							//no se canto truco
							else {

							}
						}
						//gano la ia
						else if (ia.gano()) {
							if (truco.estanEnInstanciaTruco() && ia.cantoAnteriorTruco) {
								//IA solo puede jugar una carta.
								int cartaElegidaIA = eleccionDeCarta(ia.mano());
								cout << "IA juega: " << ia.mano()[cartaElegidaIA] << endl;
								//el jugador puede responder con Retruco o solo tirar una carta
								cout << "Que va a hacer?\n1.Jugar carta 2.Cantar retruco" << endl;
								int decisionJugador;
								cin >> decisionJugador;
								//jugador juega carta
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
									//calculo que carta gano
									truco.quienGana(j1, j1.mano()[eleccionJugador], ia, ia.mano()[cartaElegidaIA]);
									truco.jugarCarta(j1, ia, ia.mano()[cartaElegidaIA], "ia");
									
								}
								//jugador canta retruco
								else if (decisionJugador == 2) {
									truco.cantarReTruco(j1, ia, "jugador");
									//si se llega a una instancia truco, se juega una carta
									if (truco.estanEnAlgunaInstanciaTruco()) {
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
										truco.quienGana(j1, j1.mano()[eleccionJugador], ia, ia.mano()[cartaElegidaIA]);
										truco.jugarCarta(j1, ia, ia.mano()[cartaElegidaIA], "ia");
									}
								}
							}
							else if (truco.estanEnInstanciaTruco()&&j1.cantoAnteriorTruco) {
								//Ia puede tirar carta o cantar re truco.
								int decisionIA = decisionSegundaMano();
								if (decisionIA == 1) {
									int cartaElegidaIA = eleccionDeCarta(ia.mano());
									truco.jugarCarta(j1, ia, ia.mano()[cartaElegidaIA], "ia");
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
									truco.jugarCarta(j1, ia, j1.mano()[eleccionJugador], "jugador");

								}
									//IA canta retruco
								else if (decisionIA==2) {
									truco.cantarReTruco(j1, ia, "ia");
									//si se llega a una instancia de truco, se juega una carta.
									if (truco.estanEnAlgunaInstanciaTruco()) {
										int cartaElegidaIA = eleccionDeCarta(ia.mano());
										truco.jugarCarta(j1, ia, ia.mano()[cartaElegidaIA], "ia");
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
										truco.jugarCarta(j1, ia, j1.mano()[eleccionJugador], "jugador");
									}
								}
							}
							else if (truco.estanEnInstanciaReTruco() && j1.cantoAnteriorTruco) {
								//la ia puede tirar carta o cantar vale 4
								int decisionIA = decisionSegundaMano();
								//IA juega carta:
								if (decisionIA == 1) {
									int cartaElegidaIA = eleccionDeCarta(ia.mano());
									truco.jugarCarta(j1, ia, ia.mano()[cartaElegidaIA], "ia");
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
									truco.jugarCarta(j1, ia, j1.mano()[eleccionJugador], "jugador");

								}
								//IA canta vale 4:
								else if (decisionIA == 2) {
									truco.cantarVale4(j1, ia, "ia");
									//si se llega a una instancia de truco, se juega una carta.
									if (truco.estanEnAlgunaInstanciaTruco()) {
										int cartaElegidaIA = eleccionDeCarta(ia.mano());
										truco.jugarCarta(j1, ia, ia.mano()[cartaElegidaIA], "ia");
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
										truco.jugarCarta(j1, ia, j1.mano()[eleccionJugador], "jugador");
									}
								}

							}
							else if (truco.estanEnInstanciaReTruco() && ia.cantoAnteriorTruco) {
								//solo puede jugar una carta normalmente
								int cartaElegidaIA = eleccionDeCarta(ia.mano());
								cout << "IA juega: " << *(ia.mano()[cartaElegidaIA]) << endl;
								//el jugador puede responder con vale 4 o solo tirar una carta
								cout << "Que va a hacer?\n1.Jugar carta 2.Cantar vale 4" << endl;
								int decisionJugador;
								cin >> decisionJugador;
								//jugador juega carta
								if (decisionJugador == 1) {
									cout << "Que carta juegas?" << endl;
									for (int i = 0; i < j1.mano().size(); i++) {
										cout << i + 1 << "." << *(j1.mano()[i]);
										if (i != j1.mano().size())cout << ", ";
									}
									cout << endl;
									int eleccionJugador;
									cin >> eleccionJugador;
									while (1 > eleccionJugador && eleccionJugador > 2) {
										cout << "Entrada invalida, ingrese nuevamente." << endl;
										cin >> eleccionJugador;
									}
									truco.quienGana(j1, j1.mano()[eleccionJugador], ia, ia.mano()[cartaElegidaIA]);
									j1.tirarCartaJugada(j1.mano()[eleccionJugador]);
									truco.jugarCarta(j1, ia, ia.mano()[cartaElegidaIA], "ia");
								}
								//JUGADOR canta vale 4
								else if (decisionJugador == 2) {
									truco.cantarVale4(j1, ia, "jugador");
								}
							}
							else if (truco.estanEnInstanciaVale4()) {
								//en vale 4 solo queda jugar las cartas.
								int cartaElegidaIA = eleccionDeCarta(ia.mano());
								cout << "IA juega: " << *(ia.mano()[cartaElegidaIA]) << endl;
								cout << "Que carta juegas?" << endl;
								for (int i = 0; i < j1.mano().size(); i++) {
									cout << i + 1 << "." << *(j1.mano()[i]);
									if (i != j1.mano().size())cout << ", ";
								}
								cout << endl;
								int eleccionJugador;
								cin >> eleccionJugador;
								while (1 > eleccionJugador && eleccionJugador > 2) {
									cout << "Entrada invalida, ingrese nuevamente." << endl;
									cin >> eleccionJugador;
								}
								truco.quienGana(j1, j1.mano()[eleccionJugador], ia, ia.mano()[cartaElegidaIA]);
								j1.tirarCartaJugada(j1.mano()[eleccionJugador]);
								truco.jugarCarta(j1, ia, ia.mano()[cartaElegidaIA], "ia");

							}
							//no se canto truco
							else{
								//La IA puede entonce jugar una carta o cantar Truco
								int decisionIA = decisionSegundaMano();
								//la IA juega una carta
								if (decisionIA == 1) {
									int cartaElegidaIA = eleccionDeCarta(ia.mano());
									cout << "IA juega: " << *(ia.mano()[cartaElegidaIA]) << endl;
									cout << "Que carta juegas?" << endl;
									for (int i = 0; i < j1.mano().size(); i++) {
										cout << i + 1 << "." << *(j1.mano()[i]);
										if (i != j1.mano().size()-1)cout << ", ";
									}
									cout << endl;
									int eleccionJugador;
									cin >> eleccionJugador;
									while (1 > eleccionJugador && eleccionJugador > 2) {
										cout << "Entrada invalida, ingrese nuevamente." << endl;
										cin >> eleccionJugador;
									}
									truco.quienGana(j1, j1.mano()[eleccionJugador], ia, ia.mano()[cartaElegidaIA]);
									j1.tirarCartaJugada(j1.mano()[eleccionJugador]);
									truco.jugarCarta(j1, ia, ia.mano()[cartaElegidaIA], "ia");
								}
								//IA canta truco
								else if (decisionIA == 2) {
									truco.cantarTruco(j1, ia, "ia");
									//si se llega a una instancia de truco, se juega una carta.
									if (truco.estanEnAlgunaInstanciaTruco()) {
										int cartaElegidaIA = eleccionDeCarta(ia.mano());
										cout << "IA juega: " << *(ia.mano()[cartaElegidaIA]) << endl;
										cout << "Que carta juegas?" << endl;
										for (int i = 0; i < j1.mano().size(); i++) {
											cout << i + 1 << "." << *(j1.mano()[i]);
											if (i != j1.mano().size()-1)cout << ", ";
										}
										cout << endl;
										int eleccionJugador;
										cin >> eleccionJugador;
										while (1 > eleccionJugador && eleccionJugador > 2) {
											cout << "Entrada invalida, ingrese nuevamente." << endl;
											cin >> eleccionJugador;
										}
										truco.quienGana(j1, j1.mano()[eleccionJugador], ia, ia.mano()[cartaElegidaIA]);
										j1.tirarCartaJugada(j1.mano()[eleccionJugador]);
										truco.jugarCarta(j1, ia, ia.mano()[cartaElegidaIA], "ia");
										
									}
								}
								
							}
						}
					}
					else if (truco.ronda() == 3) {

					}

				}
			}
			else {
				break;
			}
		}
		cout << "Iniciar nueva partida? Presione 0 para termiar el juego o presione cualquier otra tecla para volver a jugar" << endl;
		cin >> seguirJugando;
		truco.reestablecerJuego();
	}
	return 0;
}