#include "envido.h"

using namespace std;

void sort(int arr[3]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int quienGanaEnvido(Jugador& j1, Jugador& j2) {
	int sumaJugador1;
	int sumaJugador2;


	//si cante envido y tengo flor, me quedo con la suma de las dos mas altas:

	if (j1.mano()[0]->obtenerPalo() == j1.mano()[1]->obtenerPalo() && j1.mano()[0]->obtenerPalo() == j1.mano()[2]->obtenerPalo()) {
		int primeraCarta = j1.mano()[0]->obtenerValor();
		int segundaCarta = j1.mano()[1]->obtenerValor();
		int terceraCarta = j1.mano()[2]->obtenerValor();
		//en caso de que las cartas sean figuras valen 0
		if (primeraCarta > 9 && primeraCarta < 13)primeraCarta = 0;
		if (segundaCarta > 9 && segundaCarta < 13)segundaCarta = 0;
		if (terceraCarta > 9 && terceraCarta < 13)terceraCarta = 0;
		int valoresCarta[] = { primeraCarta,segundaCarta,terceraCarta };
		sort(valoresCarta); //ordena de menor a mayor, solo queda sumar las ultimas 2 posiciones
		sumaJugador1 = 20 + valoresCarta[1] + valoresCarta[2];

	}//si no tengo flor, busco cuales son iguales:
	else if (j1.mano()[0]->obtenerPalo() == j1.mano()[1]->obtenerPalo()) {
		int primeraCarta = j1.mano()[0]->obtenerValor();
		int segundaCarta = j1.mano()[1]->obtenerValor();
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
	else if (j1.mano()[0]->obtenerPalo() == j1.mano()[2]->obtenerPalo()) {
		int primeraCarta = j1.mano()[0]->obtenerValor();
		int segundaCarta = j1.mano()[2]->obtenerValor();
		//en caso de que las cartas sean figuras valen 0
		if (primeraCarta > 9 && primeraCarta < 13)primeraCarta = 0;
		if (segundaCarta > 9 && segundaCarta < 13)segundaCarta = 0;
		sumaJugador1 = 20 + primeraCarta + segundaCarta;
	}
	else/*No hay palos iguales en la mano*/ {
		int arr[3] = { j1.mano()[0]->obtenerValor() ,j1.mano()[1]->obtenerValor() ,j1.mano()[2]->obtenerValor() };
		if (j1.mano()[0]->obtenerValor() >= 10) {
			arr[0] = 0;
		}
		if (j1.mano()[1]->obtenerValor() >= 10) {
			arr[1] = 0;
		}
		if (j1.mano()[2]->obtenerValor() >= 10) {
			arr[2] = 0;
		}
		sumaJugador1 = max(arr[0], max(arr[1], arr[2]));
	}
	//ahora para j2:
	if (j2.mano()[0]->obtenerPalo() == j2.mano()[1]->obtenerPalo() && j2.mano()[0]->obtenerPalo() == j2.mano()[2]->obtenerPalo()) {
		int primeraCarta = j2.mano()[0]->obtenerValor();
		int segundaCarta = j2.mano()[1]->obtenerValor();
		int terceraCarta = j2.mano()[2]->obtenerValor();
		//en caso de que las cartas sean figuras valen 0
		if (primeraCarta > 9 && primeraCarta < 13)primeraCarta = 0;
		if (segundaCarta > 9 && segundaCarta < 13)segundaCarta = 0;
		if (terceraCarta > 9 && terceraCarta < 13)terceraCarta = 0;
		int valoresCarta[] = { primeraCarta,segundaCarta,terceraCarta };
		sort(valoresCarta); //ordena de menor a mayor, solo queda sumar las ultimas 2 posiciones
		sumaJugador2 = 20 + valoresCarta[1] + valoresCarta[2];

	}//si no tengo flor, busco cuales son iguales:
	else if (j2.mano()[0]->obtenerPalo() == j2.mano()[1]->obtenerPalo()) {
		int primeraCarta = j2.mano()[0]->obtenerValor();
		int segundaCarta = j2.mano()[1]->obtenerValor();
		//en caso de que las cartas sean figuras valen 0
		if (primeraCarta > 9 && primeraCarta < 13)primeraCarta = 0;
		if (segundaCarta > 9 && segundaCarta < 13)segundaCarta = 0;
		sumaJugador2 = 20 + primeraCarta + segundaCarta;
	}
	else if (j2.mano()[1]->obtenerPalo() == j2.mano()[2]->obtenerPalo()) {
		int primeraCarta = j2.mano()[1]->obtenerValor();
		int segundaCarta = j2.mano()[2]->obtenerValor();
		//en caso de que las cartas sean figuras valen 0
		if (primeraCarta > 9 && primeraCarta < 13)primeraCarta = 0;
		if (segundaCarta > 9 && segundaCarta < 13)segundaCarta = 0;
		sumaJugador2 = 20 + primeraCarta + segundaCarta;
	}
	else if (j2.mano()[0]->obtenerPalo() == j2.mano()[2]->obtenerPalo()) {
		int primeraCarta = j2.mano()[0]->obtenerValor();
		int segundaCarta = j2.mano()[2]->obtenerValor();
		//en caso de que las cartas sean figuras valen 0
		if (primeraCarta > 9 && primeraCarta < 13)primeraCarta = 0;
		if (segundaCarta > 9 && segundaCarta < 13)segundaCarta = 0;
		sumaJugador2 = 20 + primeraCarta + segundaCarta;
	}
	else/*No hay palos iguales en la mano*/ {
		int arr[3] = { j2.mano()[0]->obtenerValor() ,j2.mano()[1]->obtenerValor() ,j2.mano()[2]->obtenerValor() };
		if (j2.mano()[0]->obtenerValor() >= 10) {
			arr[0] = 0;
		}
		if (j2.mano()[1]->obtenerValor() >= 10) {
			arr[1] = 0;
		}
		if (j2.mano()[2]->obtenerValor() >= 10) {
			arr[2] = 0;
		}
		sumaJugador2 = max(arr[0], max(arr[1], arr[2]));
	}
	//entonces, quien gana el envido?
	if (sumaJugador1 > sumaJugador2) {
		if (j1.esMano()) {
			cout << "Vos: " << sumaJugador1 << endl;
			cout << "IA: Son Buenas..." << endl;
		}
		else {
			cout << "IA: " << sumaJugador2 << endl;
			cout << "Vos: " << sumaJugador1 << " son mejores!" << endl;
		}
		return 1;
	}
	else if (sumaJugador1 < sumaJugador2) {
		if (j1.esMano()) {
			cout << "Vos: " << sumaJugador1 << endl;
			cout << "IA: " << sumaJugador2 << " son mejores!" << endl;
		}
		else {
			cout << "IA: " << sumaJugador2 << endl;
			cout << "Vos: Son Buenas...";
		}
		return 2;
	}
	else {
		if (j1.esMano()) {
			cout << "Vos: " << sumaJugador1 << endl;
			cout << "IA: Son buenas..." << endl;
			return 1;
		}
		else if (j2.esMano()) {//por descarte seria true pero para corroborar el correcto funcionamiento hago el if
			cout << "IA: " << sumaJugador2 << endl;
			cout << "Vos: Son buenas..." << endl;
			return 2;
		}
		else {
			cout << "ninguno es mano, debugea";
			return 2;
		}
	}

}

void cantarEnvido(Jugador& jugador, Jugador& ia, string quienCanto) {
	
	//si el envido lo canta la IA
	if (quienCanto == "ia") {
		ia.cantoEnvido = true;
		cout << "IA: Envido!" << endl;
		int eleccionJugador;
		cout << "Cual es su respuesta?" << endl;
		cout << "1. Quiero 2. No quiero 3.Envido 4. Real Envido 5.Falta Envido" << endl;
		cin >> eleccionJugador;
		while (1 > eleccionJugador && eleccionJugador > 5) {
			cout << "Entrada no valida, ingrese nuevamente su respuesta" << endl;
			cin >> eleccionJugador;
		}
		if (eleccionJugador == 1) {
			cout << "Vos: Quiero!" << endl;
			if (1 == quienGanaEnvido(jugador, ia)) {
				jugador.sumarPuntos(2);
				cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
			}
			else {
				ia.sumarPuntos(2);
				cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
			}
		}
		else if (eleccionJugador == 2) {
			cout << "Vos: No quiero..." << endl;
			ia.sumarPuntos(1);
			cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
		}
		else if (eleccionJugador == 3) {//instancia envido envido.
			cout << "Vos: Envido!" << endl;

			int respuestaIA = respuestaEnvido(/*opciones*/4); //puede responder quiero no quiero real envido y falta envido.

			if (respuestaIA == 0) {//Quiere el envido envido
				cout << "IA: Quiero!" << endl;
				if (1 == quienGanaEnvido(jugador, ia)) {
					jugador.sumarPuntos(4);
					cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
				}
				else {
					ia.sumarPuntos(4);
					cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
				}
			}
			else if (respuestaIA == 1) {//No quiere
				cout << "IA: No quiero!" << endl;
				jugador.sumarPuntos(2);
				cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
			}
			else if (respuestaIA == 2) {//canta Real Envido, instancia envido envido real envido.
				cout << "IA: Real Envido!" << endl;
				int eleccion2;

				cout << "Cual es su respuesta?" << endl;
				cout << "1. Quiero 2. No quiero 3.Falta Envido" << endl;
				cin >> eleccion2;

				while (1 > eleccion2 && eleccion2 > 3) {
					cout << "Entrada no valida, ingrese nuevamente su respuesta" << endl;
					cin >> eleccion2;
				}

				if (eleccion2 == 1) {//se quiere el envido envido real envido
					cout << "Vos: Quiero!" << endl;
					if (1 == quienGanaEnvido(jugador, ia)) {
						jugador.sumarPuntos(7);
						cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
					}
					else {
						ia.sumarPuntos(7);
						cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
					}
				}
				else if (eleccion2 == 2) {//no se quiere el envido envido real envido
					cout << "Vos: No quiero" << endl;
					ia.sumarPuntos(4);
					cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
				}
				else {//canto la falta, instancia envido envido real envido falta envido.
					cout << "Vos: Falta Envido!" << endl;
					int IA_resFaltaEnv = respuestaEnvido(2);
					if (IA_resFaltaEnv) {//quiere la falta.
						cout << "IA: Quiero!" << endl;
						if (1 == quienGanaEnvido(jugador, ia)) {
							int aSumar;
							if (!ia.estaEnBuenas()) {
								aSumar = 30 - ia.puntos();
								jugador.sumarPuntos(aSumar);
							}
							else {
								aSumar = 15 - ia.puntos();
								jugador.sumarPuntos(aSumar);
							}
						}
						else {
							int aSumar;
							if (!jugador.estaEnBuenas()) {
								aSumar = 30 - jugador.puntos();
								ia.sumarPuntos(aSumar);
							}
							else {
								aSumar = 15 - jugador.puntos();
								ia.sumarPuntos(aSumar);
							}
						}
					}
					else { //no quiere la falta
						cout << "IA: No quiero!" << endl;
						jugador.sumarPuntos(7);
						cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
					}
				}
			}
			else {//La IA canta falta Envido. es instancia envido envido falta envido.
				cout << "IA: Falta Envido!" << endl;
				int eleccion3;

				cout << "Cual es su respuesta?" << endl;
				cout << "1. Quiero 2. No quiero" << endl;
				cin >> eleccion3;
				while (1 > eleccion3 && eleccion3 > 2) {
					cout << "Entrada no valida, ingrese nuevamente su respuesta" << endl;
					cin >> eleccion3;
				}

				if (eleccion3 == 1) {// quiero la falta
					cout << "Vos: Quiero!" << endl;
					if (1 == quienGanaEnvido(jugador, ia)) {
						int aSumar;
						if (!ia.estaEnBuenas()) {
							aSumar = 30 - ia.puntos();
							jugador.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
						else {
							aSumar = 15 - ia.puntos();
							jugador.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
					}
					else {
						int aSumar;
						if (!jugador.estaEnBuenas()) {
							aSumar = 30 - jugador.puntos();
							ia.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
						else {
							aSumar = 15 - jugador.puntos();
							ia.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
					}
				}
				else {//no quiero la falta
					cout << "Vos: No quiero." << endl;
					ia.sumarPuntos(4);
					cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
				}
			}
		}
		else if (eleccionJugador == 4) {//instancia envido real envido
			cout << "Vos: Real envido!" << endl;
			//aca la IA solo tiene 3 respuestas: quiero, no quiero, o falta envido.
			int respuestaIA2 = respuestaEnvido(3);
			if (respuestaIA2) {
				cout << "IA: No quiero" << endl;
				jugador.sumarPuntos(2);
				cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
			}
			else if (respuestaIA2 == 1) {
				cout << "IA: Quiero." << endl;
				if (1 == quienGanaEnvido(jugador, ia)) {
					jugador.sumarPuntos(5);
					cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
				}
				else {
					ia.sumarPuntos(5);
					cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
				}
			}
			else {//instancia envido real envido falta envido
				cout << "IA: Falta envido." << endl;
				int eleccion4;

				cout << "Cual es su respuesta?" << endl;
				cout << "1. Quiero 2. No quiero" << endl;
				cin >> eleccion4;
				while (1 > eleccion4 && eleccion4 > 2) {
					cout << "Entrada no valida, ingrese nuevamente su respuesta" << endl;
					cin >> eleccion4;
				}

				if (eleccion4 == 1) {// quiero la falta
					cout << "Vos: Quiero!" << endl;
					if (1 == quienGanaEnvido(jugador, ia)) {
						int aSumar;
						if (!ia.estaEnBuenas()) {
							aSumar = 30 - ia.puntos();
							jugador.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
						else {
							aSumar = 15 - ia.puntos();
							jugador.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
					}
					else {
						int aSumar;
						if (!jugador.estaEnBuenas()) {
							aSumar = 30 - jugador.puntos();
							ia.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
						else {
							aSumar = 15 - jugador.puntos();
							ia.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
					}
				}
				else {//no quiero la falta
					cout << "Vos: No quiero." << endl;
					ia.sumarPuntos(4);
					cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
				}
			}
		}
		else {//canto falta envido. Instancia envido falta envido.
			cout << "Vos: Falta envido!" << endl;
			int respuestaIA3 = respuestaEnvido(2);
			if (respuestaIA3) {
				cout << "IA: No quiero" << endl;
				jugador.sumarPuntos(2);
				cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
			}
			else {//quiere la falta
				cout << "IA: Quiero..." << endl;
				if (1 == quienGanaEnvido(jugador, ia)) {
					int aSumar;
					if (!ia.estaEnBuenas()) {
						aSumar = 30 - ia.puntos();
						jugador.sumarPuntos(aSumar);
						cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
					}
					else {
						aSumar = 15 - ia.puntos();
						jugador.sumarPuntos(aSumar);
						cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
					}
				}
				else {
					int aSumar;
					if (!jugador.estaEnBuenas()) {
						aSumar = 30 - jugador.puntos();
						ia.sumarPuntos(aSumar);
						cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
					}
					else {
						aSumar = 15 - jugador.puntos();
						ia.sumarPuntos(aSumar);
						cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
					}
				}
			}
		}
	}
	//el que canto el envido fue el jugador
	else {
		jugador.cantoEnvido = true;
		cout << "Vos: Envido!" << endl;
		int eleccionIA = respuestaEnvido(5);
		//IA quiere
		if (eleccionIA == 0) {
			cout << "IA: Quiero!" << endl;
			if (1 == quienGanaEnvido(jugador, ia)) {
				jugador.sumarPuntos(2);
				cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
			}
			else {
				ia.sumarPuntos(2);
				cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
			}
		}
		//IA no quiere
		else if (eleccionIA == 1) {
			cout << "IA: No quiero..." << endl;
			jugador.sumarPuntos(1);
			cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
		}
		//IA canta envido. instancia envido envido
		else if (eleccionIA == 2) {
			cout << "IA: Envido!" << endl;

			int eleccionJugador;

			cout << "Cual es su respuesta?" << endl;
			cout << "1. Quiero 2. No quiero 3.Real Envido 4.Falta Envido" << endl;
			cin >> eleccionJugador;
			while (1 > eleccionJugador && eleccionJugador > 4) {
				cout << "Entrada no valida, ingrese nuevamente su respuesta" << endl;
				cin >> eleccionJugador;
			}

			//Quiero el envido envido
			if (eleccionJugador == 1) {
				cout << "Vos: Quiero!" << endl;
				if (1 == quienGanaEnvido(jugador, ia)) {
					jugador.sumarPuntos(4);
					cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
				}
				else {
					ia.sumarPuntos(4);
					cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
				}
			}
			//No quiero envido envido
			else if (eleccionJugador == 2) {
				cout << "Vos: No quiero!" << endl;
				ia.sumarPuntos(2);
				cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
			}
			//canto Real Envido, instancia envido envido real envido.
			else if (eleccionJugador == 3) {
				cout << "Vos: Real Envido!" << endl;
				int respuestaIA = respuestaEnvido(3);
				//IA no quiere
				if (respuestaIA == 0) {
					cout << "IA: No quiero!" << endl;
					jugador.sumarPuntos(4);
					cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
				}
				//IA quiere
				else if (respuestaIA == 1) {
					cout << "IA: Quiero..." << endl;
					if (1 == quienGanaEnvido(jugador, ia)) {
						jugador.sumarPuntos(7);
						cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
					}
					else {
						ia.sumarPuntos(7);
						cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
					}
				}
				//Ia canta la falta, instancia envido envido real envido falta envido.
				else if (respuestaIA == 2) {
					cout << "IA: Falta Envido!" << endl;
					int eleccion2;
					cout << "Cual es su respuesta?" << endl;
					cout << "1. Quiero 2. No quiero" << endl;
					cin >> eleccion2;
					while (1 > eleccion2 && eleccion2 > 2) {
						cout << "Entrada no valida, ingrese nuevamente su respuesta" << endl;
						cin >> eleccion2;
					}
					//quiero la falta.
					if (eleccion2 == 1) {
						cout << "Vos: Quiero!" << endl;
						if (1 == quienGanaEnvido(jugador, ia)) {
							int aSumar;
							if (!ia.estaEnBuenas()) {
								aSumar = 30 - ia.puntos();
								jugador.sumarPuntos(aSumar);
							}
							else {
								aSumar = 15 - ia.puntos();
								jugador.sumarPuntos(aSumar);
							}
						}
						else {
							int aSumar;
							if (!jugador.estaEnBuenas()) {
								aSumar = 30 - jugador.puntos();
								ia.sumarPuntos(aSumar);
							}
							else {
								aSumar = 15 - jugador.puntos();
								ia.sumarPuntos(aSumar);
							}
						}
					}
					//no quiero la falta
					else {
						cout << "Vos: No quiero!" << endl;
						ia.sumarPuntos(7);
						cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
					}
				}
			}
			//Canto falta Envido, instancia envido envido falta envido.
			else/*eleccionJugador == 4*/ {
				cout << "Vos: Falta Envido!" << endl;
				int respuestaIA2 = respuestaEnvido(2);
				// IA quiere la falta
				if (respuestaIA2 == 0) {
					cout << "IA: Quiero!" << endl;
					if (1 == quienGanaEnvido(jugador, ia)) {
						int aSumar;
						if (!ia.estaEnBuenas()) {
							aSumar = 30 - ia.puntos();
							jugador.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
						else {
							aSumar = 15 - ia.puntos();
							jugador.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
					}
					else {
						int aSumar;
						if (!jugador.estaEnBuenas()) {
							aSumar = 30 - jugador.puntos();
							ia.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
						else {
							aSumar = 15 - jugador.puntos();
							ia.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
					}
				}
				//IA no quiere la falta
				else {
					cout << "IA: No quiero." << endl;
					jugador.sumarPuntos(4);
					cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
				}
			}
		}
		//IA canta real envido, es instancia envido real envido
		else if (eleccionIA == 3) {
			cout << "IA: Real envido!" << endl;
			//aca tenes solo 3 respuestas: quiero, no quiero, o falta envido.
			int respuestaJugador;
			cout << "Cual es su respuesta?" << endl;
			cout << "1. Quiero 2. No quiero 3. Falta envido" << endl;
			cin >> respuestaJugador;
			while (1 > respuestaJugador && respuestaJugador > 3) {
				cout << "Entrada no valida, ingrese nuevamente su respuesta" << endl;
				cin >> respuestaJugador;
			}
			//jugador quiere
			if (respuestaJugador == 1) {
				cout << "Vos: Quiero!" << endl;
				if (1 == quienGanaEnvido(jugador, ia)) {
					jugador.sumarPuntos(5);
					cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
				}
				else {
					ia.sumarPuntos(5);
					cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
				}
			}
			//jugador no quiere
			else if (respuestaJugador == 2) {
				ia.sumarPuntos(2);
				cout << "Vos: No quiero ni ahi." << endl;
				cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;

			}
			//jugador canta falta envido, es instancia envido real envido falta envido
			else {
				cout << "Vos: Falta envido." << endl;
				int respuestaIA2 = respuestaEnvido(2);

				// IA quiere la falta
				if (respuestaIA2 == 0) {
					cout << "IA: Quiero!" << endl;
					if (1 == quienGanaEnvido(jugador, ia)) {
						int aSumar;
						if (!ia.estaEnBuenas()) {
							aSumar = 30 - ia.puntos();
							jugador.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
						else {
							aSumar = 15 - ia.puntos();
							jugador.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
					}
					else {
						int aSumar;
						if (!jugador.estaEnBuenas()) {
							aSumar = 30 - jugador.puntos();
							ia.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
						else {
							aSumar = 15 - jugador.puntos();
							ia.sumarPuntos(aSumar);
							cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
						}
					}
				}
				//IA no quiere la falta
				else {
					cout << "IA: No quiero." << endl;
					jugador.sumarPuntos(4);
					cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
				}
			}
		}
		//eleccionIA==4. IA canta falta envido. Instancia envido falta envido.
		else {
			cout << "IA: Falta envido!" << endl;
			int respuestaJugador2;
			cout << "Cual es su respuesta?" << endl;
			cout << "1. Quiero 2. No quiero" << endl;
			cin >> respuestaJugador2;
			while (1 > respuestaJugador2 && respuestaJugador2 > 2) {
				cout << "Entrada no valida, ingrese nuevamente su respuesta" << endl;
				cin >> respuestaJugador2;
			}
			//Jugador no quiere la falta
			if (respuestaJugador2 == 2) {
				cout << "Vos: No quiero" << endl;
				ia.sumarPuntos(2);
				cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
			}
			//Jugador quiere la falta
			else {
				cout << "Vos: Quiero..." << endl;
				if (1 == quienGanaEnvido(jugador, ia)) {
					int aSumar;
					if (!ia.estaEnBuenas()) {
						aSumar = 30 - ia.puntos();
						jugador.sumarPuntos(aSumar);
						cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
					}
					else {
						aSumar = 15 - ia.puntos();
						jugador.sumarPuntos(aSumar);
						cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
					}
				}
				else {
					int aSumar;
					if (!jugador.estaEnBuenas()) {
						aSumar = 30 - jugador.puntos();
						ia.sumarPuntos(aSumar);
						cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
					}
					else {
						aSumar = 15 - jugador.puntos();
						ia.sumarPuntos(aSumar);
						cout << "Vos: " << jugador.puntos() << ", IA: " << ia.puntos() << endl;
					}
				}
			}
		}

	}
}