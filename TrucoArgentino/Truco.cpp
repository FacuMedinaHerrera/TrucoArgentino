#include "Truco.h"


Truco::Truco(Jugador& j1, Jugador& ia) : _j1(j1), _ia(ia) {

}

Truco::~Truco() {
	for (int i = 0; i < mazo.size(); i++) {
		delete mazo[i];
	}
}

int Truco::puntaje(Jugador& j) {
	return j.puntos();
}

void Truco::sumarPuntos(Jugador& j, int puntos) {
	j.sumarPuntos(puntos);
}

void Truco::repartir(Jugador& j1, Jugador& ia) {
	//Si bien mi mazo esta ordenado, elegire cartas al azar
	//del mazo, lo cual simula la mezcla de este.
	vector<Carta*>aRepartir;
	if (mazo.size() != 0) {
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
	int sizeJ1 = _j1.mano().size();
	for (int j = 0; j < sizeJ1; j++) {
		_j1.mano().pop_back();
	}
	int sizeIA = _ia.mano().size();
	for (int k = 0; k < sizeIA; k++) {
		_ia.mano().pop_back();
	}
	int sizeDescarte = pilaDescarte.size();
	for (int x = 0; x <sizeDescarte; x++) {
		pilaDescarte.pop_back();
	}
}

int Truco::ronda() {
	return _ronda;
}

void Truco::avanzarRonda() {
	_ronda++;
}

void Truco::reestablecerJuego() {
	reestablecerMazo();
	_ronda = 1;
	_j1.reestablecerPuntaje();
	_ia.reestablecerPuntaje();
	_j1.resetManos();
	_ia.resetManos();
	if (_ia.esMano()) {
		_ia.cambiarMano();
	}
	if (_j1.esMano()) {
		_j1.cambiarMano();
	}
}

void Truco::nuevaMano() {
	estanEnTruco = false;
	estanEnReTruco = false;
	estanEnVale4 = false;
	esParda1 = false;
	esParda2 = false;
	esParda3 = false;
	_j1.cantoEnvido = false;
	_ia.cantoEnvido = false;
	_j1.cantoAnteriorTruco = false;
	_ia.cantoAnteriorTruco = false;
	_ronda = 1;
	_j1.resetManos();
	_ia.resetManos();
	reestablecerMazo();
	repartir(_j1, _ia);

}

void Truco::quienGana(Jugador& j1, Carta* cartaJ1, Jugador& ia, Carta* cartaIA) {
	int valorRelativoJ1 = cartaJ1->obtenerValorRelativo();
	int valorRelativoIA = cartaIA->obtenerValorRelativo();

	if (valorRelativoJ1 < valorRelativoIA) {
		if (!j1.gano() && !ia.gano()) {
			j1.cambiarGanadorRonda();
		}
		else if (!j1.gano() && ia.gano()) {
			j1.cambiarGanadorRonda();
			ia.cambiarGanadorRonda();
		}
		else if (j1.gano() && ia.gano()) {
			ia.cambiarGanadorRonda();
		}
	}
	else if (valorRelativoJ1 > valorRelativoIA) {
		if (!j1.gano() && !ia.gano()) {
			ia.cambiarGanadorRonda();
		}
		else if (j1.gano() && !ia.gano()) {
			j1.cambiarGanadorRonda();
			ia.cambiarGanadorRonda();
		}
		else if (j1.gano() && ia.gano()) {
			j1.cambiarGanadorRonda();
		}
	}
	else {// es parda, por lo que diremos que ambos jugadores no ganaron la anterior.
		if (j1.gano() && ia.gano()) {
			j1.cambiarGanadorRonda();
			ia.cambiarGanadorRonda();
		}
		else if (!j1.gano() && ia.gano()) {
			ia.cambiarGanadorRonda();
		}
		else if (j1.gano() && !ia.gano()) {
			j1.cambiarGanadorRonda();
		}
		//les pongo uno demas ya que la suma de la ronda se hace antes de cambiar la parda.
		if (_ronda == 2)esParda1 = true;
		if (_ronda == 3)esParda2 = true;
		if (_ronda == 4)esParda3 = true;
	}


	if (_ronda == 1 && !esParda1) {
		if (j1.gano()) {
			j1.ganoMano(1);
		}
		else {
			ia.ganoMano(1);
		}
	}
	else if (_ronda == 2 && !esParda2) {
		if (j1.gano()) {
			j1.ganoMano(2);
		}
		else {
			ia.ganoMano(2);
		}
	}
	else if(!esParda3){
		if (j1.gano()) {
			j1.ganoMano(3);
		}
		else {
			ia.ganoMano(3);
		}
	}
}

//falta implementar el resto de rondas:
void Truco::jugarCarta(Jugador& j1, Jugador& ia, Carta* aJugar, string quienLaJuega) {
	//el que juega la carta es el jugador
	if (quienLaJuega == "jugador") {
		//si la ronda es la primera, y el jugador es mano, eso quiere decir que no se jugo carta
		//Se juega la carta y se da una respuesta de la IA.
		if (_ronda == 1 && j1.esMano()) {
			cout << "Tu juegas: " << *aJugar << endl;
			j1.tirarCartaJugada(aJugar);
			int respuestaIA = respuestaPrimeraMano(); // las posibles respuestas son: Jugar una carta, cantar envido, cantar truco.
			//se canta envido, solo si los puntos del jugador y de la IA estan en 0, de otra forma ya se canto anteriormente el envido.
			if (respuestaIA == 1 && (!j1.cantoEnvido || !ia.cantoEnvido)) {
				cout << "IA: Fuiste a la pesca?..." << endl;
				cantarEnvido(j1, ia, "ia");
				//luego del envido la IA juega una carta.
				int cartaAJugar = eleccionDeCarta(ia.mano());
				cout << "IA juega: " << *(ia.mano()[cartaAJugar]) << endl;
				this->quienGana(j1, aJugar, ia, ia.mano()[cartaAJugar]);
				ia.tirarCartaJugada(ia.mano()[cartaAJugar]);
				_ronda++;
			}
			//se tira una carta
			else if (respuestaIA == 2||respuestaIA==1) {
				int cartaAJugar = eleccionDeCarta(ia.mano());
				cout << "IA juega: " << *(ia.mano()[cartaAJugar]) << endl;
				this->quienGana(j1, aJugar, ia, ia.mano()[cartaAJugar]);
				ia.tirarCartaJugada(ia.mano()[cartaAJugar]);
				_ronda++;
			}
			//IA canta truco
			else {
				if(!estanEnAlgunaInstanciaTruco())cantarTruco(j1, ia, "ia");
				//una vez que se canta el truco y se define que sucedio veo si se tira un carta o no.
				//con que estemos en alguna instancia de truco, continua el juego.
				if (estanEnAlgunaInstanciaTruco()) {
					int cartaAJugar = eleccionDeCarta(ia.mano());
					cout << "IA juega: " << *(ia.mano()[cartaAJugar]) << endl;
					this->quienGana(j1, aJugar, ia, ia.mano()[cartaAJugar]);
					ia.tirarCartaJugada(ia.mano()[cartaAJugar]);
					_ronda++;
				}
				//else {
					//como no se quiso el truco, termina la mano.
				//}
			}
		}
		//esto significa que la primera carta la jugo la IA
		else if (_ronda == 1 && !j1.esMano()) {
			cout << "Tu juegas: " << *aJugar << endl;
			j1.tirarCartaJugada(aJugar);
		}
		//Para ronda 2, fijarse ademas si estan en parda para ver quien gano.
		else if (_ronda == 2||_ronda==3) {
			cout << "Tu juegas: " << *aJugar << endl;
			j1.tirarCartaJugada(aJugar);
			
			//Si estamos en alguna instancia de truco, Dependiendo de quien haya cantado, la ia puede cantar truco o no. Si no, puede cantar normalmente, o jugar.
			int respuestaIA = decisionSegundaMano();

			//IA canta algun truco.
			if (respuestaIA == 2) {
				if (estanEnAlgunaInstanciaTruco() && j1.cantoAnteriorTruco) {
					if (estanEnInstanciaTruco()) { 
						cantarReTruco(j1, ia, "ia");
					}
					else if (estanEnInstanciaReTruco()) { 
						cantarVale4(j1, ia, "ia");
					}
				}
				else {
					cantarTruco(j1, ia, "ia");
				}
				
			}
			//luego de cantar algo, la ia debe jugar una carta en caso de llegar a una instancia de truco.
			if ((estanEnAlgunaInstanciaTruco()&&respuestaIA==2)||respuestaIA==1) {
				Carta* cartaIA = ia.mano()[eleccionDeCarta(ia.mano())];
				cout << "IA juega: " << *cartaIA << endl;
				quienGana(j1, aJugar, ia, cartaIA);
				ia.tirarCartaJugada(cartaIA);
				_ronda++;
			}
			
		}
	}
	//juega la carta la IA
	
	else {
		ia.tirarCartaJugada(aJugar);
		
		_ronda++;
	}
}

void Truco::cantarTruco(Jugador& j1, Jugador& ia, string quienCanta) {
	//si canta la IA
	if (quienCanta == "ia") {
		cout << "IA: Truco!" << endl;
		cout << "Que desea hacer?" << endl;
		if (_ronda == 1)cout << "1. Quiero 2. No quiero 3.Retruco 4. Envido" << endl;
		cout << "1. Quiero 2. No quiero 3.Retruco" << endl;
		int respuesta;
		cin >> respuesta;
		while (respuesta < 1 || respuesta>3) {
			cout << "Entrada invalida, ingrese nuevamente" << endl;
			cin >> respuesta;
		}
		

		if (respuesta == 1) {
			cout << "Vos: Quiero." << endl;
			ia.cantoAnteriorTruco = true;
			estanEnTruco = true;
		}
		else if (respuesta == 2) {
			cout << "Vos: No quiero." << endl;
			ia.sumarPuntos(1);
			cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
			nuevaMano();
			ia.cambiarMano();
			j1.cambiarMano();
		}
		else if(respuesta==3){
			cantarReTruco(j1, ia, "jugador");//aca se considera el caso en que la IA quiera cantar vale 4.
		}
		else {
			cout << "Vos: Sabes lo que viene primero?..." << endl;
			if (!ia.cantoEnvido && !ia.cantoEnvido)cantarEnvido(j1, ia, "jugador");
		}
	}
	//canta el jugador
	else {
		cout << "Vos: Truco..." << endl;
		//la IA puede responder quiero, no quiero, o reTruco y si es ronda 1 puede cantar envido.
		int respuestaIA;
		if (_ronda == 1) {
			respuestaIA = respuestaTruco(4);
		}
		else {
			respuestaIA = respuestaTruco(3);
		}
		if (respuestaIA == 1) {
			cout << "IA: Quiero" << endl;
			j1.cantoAnteriorTruco = true;
			estanEnTruco = true;
		}
		else if (respuestaIA == 2) {
			cout << "IA: No quiero" << endl;
			j1.sumarPuntos(1);
			cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
			nuevaMano();
			ia.cambiarMano();
			j1.cambiarMano();
		}
		else if(respuestaIA==3) {
			cantarReTruco(j1, ia, "ia");
		}
		else {
			
			if (!j1.cantoEnvido&&!ia.cantoEnvido) {
				cout << "IA: Sabes lo que viene primero?..." << endl;
				cantarEnvido(j1, ia, "ia");
			}
		}
	}
}

void Truco::cantarReTruco(Jugador& j1, Jugador& ia, string quienCanta) {
	//canta el jugador
	if (quienCanta == "jugador") {
		cout << "Vos: Quiero re truco!" << endl;
		int respuestaIA = respuestaTruco(3);
		if (respuestaIA == 1) {
			cout << "IA: Quiero" << endl;
			j1.cantoAnteriorTruco = true;
			ia.cantoAnteriorTruco = false;
			estanEnTruco = false;
			estanEnReTruco = true;
		}
		else if (respuestaIA == 2) {
			cout << "IA: No quiero" << endl;
			j1.sumarPuntos(2);
			estanEnTruco = false;
			cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
			nuevaMano();
			ia.cambiarMano();
			j1.cambiarMano();
		}
		else {
			cantarVale4(j1, ia, "ia");
		}
	}
	//canta la IA
	else {
		cout << "IA: Quiero re truco!" << endl;
		cout << "Que desea hacer?" << endl;
		cout << "1. Quiero 2. No quiero 3.Vale 4" << endl;
		int respuesta;
		cin >> respuesta;
		while (1 > respuesta || respuesta > 3) {
			cout << "Entrada invalida, ingrese nuevamente" << endl;
			cin >> respuesta;
		}

		if (respuesta == 1) {
			cout << "Vos: Quiero." << endl;
			ia.cantoAnteriorTruco = true;
			j1.cantoAnteriorTruco = false;
			estanEnReTruco = true;
			estanEnTruco = false;
		}
		else if (respuesta == 2) {
			cout << "Vos: No quiero." << endl;
			ia.sumarPuntos(2);
			estanEnTruco = false;
			cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
			nuevaMano();
			ia.cambiarMano();
			j1.cambiarMano();
		}
		else {
			cantarVale4(j1, ia, "jugador");
		}
	}
}

void Truco::cantarVale4(Jugador& j1, Jugador& ia, string quienCanta) {
	//canta el jugador
	if (quienCanta == "jugador") {
		cout << "Vos: Quiero vale 4!" << endl;
		int respuestaIA = respuestaTruco(2);
		if (respuestaIA == 1) {
			cout << "IA: Quiero." << endl;
			j1.cantoAnteriorTruco = true;
			ia.cantoAnteriorTruco = false;
			estanEnReTruco = false;
			estanEnTruco = false;
			estanEnVale4 = true;
		}
		else if (respuestaIA == 2) {
			cout << "IA: No, no quiero..." << endl;
			j1.sumarPuntos(3);
			estanEnTruco = false;
			estanEnReTruco = false;
			cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
			nuevaMano();
			ia.cambiarMano();
			j1.cambiarMano();
		}
	}
	//canta la IA
	else {
		cout << "IA: Quiero Vale 4! Te animas?" << endl;
		cout << "Que desea hacer?" << endl;
		cout << "1. Quiero 2. No quiero" << endl;
		int respuesta;
		cin >> respuesta;
		while (1 > respuesta && respuesta > 2) {
			cout << "Entrada invalida, ingrese nuevamente" << endl;
			cin >> respuesta;
		}

		if (respuesta == 1) {
			cout << "Vos: Obvio, quiero." << endl;
			ia.cantoAnteriorTruco = true;
			j1.cantoAnteriorTruco = false;
			estanEnVale4 = true;
			estanEnReTruco = false;
			estanEnTruco = false;
		}
		else if (respuesta == 2) {
			cout << "Vos: No quiero." << endl;
			ia.sumarPuntos(3);
			estanEnTruco = false;
			estanEnReTruco = false;
			cout << "Vos: " << j1.puntos() << ", IA: " << ia.puntos() << endl;
			nuevaMano();
			ia.cambiarMano();
			j1.cambiarMano();
		}
	}
}

bool Truco::estanEnAlgunaInstanciaTruco() {
	return estanEnReTruco || estanEnTruco || estanEnVale4;
}

bool Truco::estanEnInstanciaTruco() {
	return estanEnTruco;
}

bool Truco::estanEnInstanciaReTruco() {
	return estanEnReTruco;
}

bool Truco::estanEnInstanciaVale4() {
	return estanEnVale4;
}