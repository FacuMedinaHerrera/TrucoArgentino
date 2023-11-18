// ProyectoFinal-Truco.cpp : Defines the entry point for the application.
//
//TODO: reestableces mazo y pensar en que momento debo restablecerlo dentro del codigo
#include <windows.h>
#include "Truco.h"



using namespace std;

int main()
{
	
	cout << "Truco Argentino por consola!" << endl;
	Jugador j1;
	Jugador ia;
	Truco truco = Truco();
	truco.repartir(j1,ia);
	cout << j1.mano()[0]->obtenerValor() << endl;

	return 0;
}