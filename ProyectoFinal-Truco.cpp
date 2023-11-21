// ProyectoFinal-Truco.cpp : Defines the entry point for the application.
//
//TODO: reestableces mazo y pensar en que momento debo restablecerlo dentro del codigo
#include <windows.h>
#include "Truco.h"
#include "envido.h"

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
	Truco truco = Truco(j1,ia);
	bool seguirJugando = false;
	cout << "Presiona 1 para iniciar el juego" << endl;
	cin >> seguirJugando;
	if (seguirJugando == 0)seguirJugando = 1;

	while (seguirJugando) {
		quienSeraMano(j1, ia);
		while (!(j1.puntos() <= 15 && j1.estaEnBuenas()) && !(ia.puntos() <= 15 && ia.estaEnBuenas())) {
			truco.repartir(j1,ia);
			cout << "Estas son tus cartas:" << endl;
			cout << "1. "<< * (j1.mano()[0]) <<" , 2. " << *(j1.mano()[1]) << " , 3. " << *(j1.mano()[2])<<endl;
			if (j1.esMano()) {
				cout << "Sos mano, que queres hacer?" << endl;
				if (truco.ronda() == 1) {
					int decision;
					cout << "1. Cantar envido 2.Jugar una carta 3. Cantar truco" << endl;
					cin >> decision;
					if (decision == 1) {
						cantarEnvido(j1, ia, 0);
					}else if(decision == 2){
						int cartaAJugar;
						cout << "Que carta quieres jugar?" << endl;
						for (int i = 0; i < j1.mano().size();i++) {
							cout << i + 1 << ". " << *(j1.mano()[i]);
							if (i != 2)cout << ", ";
						}
						cout << endl;
						cin >> cartaAJugar;
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