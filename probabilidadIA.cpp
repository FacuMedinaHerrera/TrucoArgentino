#include "probabilidadIA.h"


int obtenerMasAlto(vector<Carta*> mano) {
	//las inicializo en 14 ya que el vector ordenDeValor tiene un tamaño fijo de 14.
	//Por lo que el indice maximo es 13
	int indice1raCarta = 14;
	int indice2daCarta = 14;
	int indice3raCarta = 14;
	for (int i = 0; i < ordenDeValor.size(); i++) {
		for (int j = 0; j < ordenDeValor[i].size(); j++) {
			if (mano.size() == 3) {
				if (*mano[0] == ordenDeValor[i][j]) {
					indice1raCarta = i;
				}
				else if (*mano[1] == ordenDeValor[i][j]) {
					indice2daCarta = i;
				}
				else if (*mano[2] == ordenDeValor[i][j]) {
					indice3raCarta = i;
				}
			}
			else if (mano.size() == 2) {
				if (*mano[0] == ordenDeValor[i][j]) {
					indice1raCarta = i;
				}
				else if (*mano[1] == ordenDeValor[i][j]) {
					indice2daCarta = i;
				}
			}
			else if (mano.size() == 1) {
				if (*mano[0] == ordenDeValor[i][j]) {
					indice1raCarta = i;
				}
			}

		}
	}
	int indiceCartaMasAlta = min(indice1raCarta, min(indice2daCarta, indice3raCarta));
	int res;
	if (indiceCartaMasAlta == indice1raCarta) {
		res = mano[0]->obtenerValor();
	}
	else if (indiceCartaMasAlta == indice2daCarta) {
		res = mano[1]->obtenerValor();
	}
	else {
		res = mano[2]->obtenerValor();
	}

	return res;
}

int respuestaEnvido(int cantOpciones) {//la cantidad maxima de opciones seran 5
	int proba = rand() % 100;
	if (cantOpciones == 2) {//sera solo por quiero/no quiero
		if (proba < 50) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else if (cantOpciones == 3) {
		if (proba < 45) {
			return 0;
		}
		else if (proba >= 45 && proba < 90) {
			return 1;
		}
		else {
			return 2;
		}
	}
	else if (cantOpciones == 4) {
		if (proba < 40) {
			return 0;
		}
		else if (proba >= 40 && proba < 80) {
			return 1;
		}
		else if (proba >= 80 && proba < 95) {
			return 2;
		}
		else {
			return 3;
		}
	}
	else {//5opciones
		if (proba < 35) {
			return 0;
		}
		else if (proba >= 35 && proba < 70) {
			return 1;
		}
		else if (proba >= 70 && proba < 85) {
			return 2;
		}
		else if (proba >= 85 && proba < 95) {
			return 3;
		}
		else {
			return 4;
		}
	}
}

int respuestaTruco(int cantOpciones) {
	int proba = rand() % 100;
	if (cantOpciones == 4) {
		if (proba < 25) {
			return 1;
		}
		else if (proba >= 25 && proba < 50) {
			return 2;
		}
		else if (proba >= 50 && proba < 75) {
			return 3;
		}
		else {
			return 4;
		}
	}
	//respuesta retruco
	if (cantOpciones == 3) {
		if (proba < 45) {
			return 1;
		}
		else if (proba >= 45 && proba < 90) {
			return 2;
		}
		else {
			return 3;
		}

	}
	//respuesta vale 4
	if (cantOpciones == 2) {
		if (proba < 60) {
			return 1;
		}
		else {
			return 2;
		}
	}
}

int respuestaPrimeraMano() {
	int proba = rand() % 100;
	if (proba < 60) {//proba de respuesta envido
		return 1;
	}
	else if (proba >= 60 < 90) {//proba de responder con una carta
		return 2;
	}
	else {
		//proba de cantar truco
		return 3;
	}
}

int eleccionDeCarta(vector<Carta*> manoIA) {
	int max = obtenerMasAlto(manoIA);
	bool encontre = false;
	int res = 0;
	while (res < manoIA.size() && !encontre) {
		if (manoIA[res]->obtenerValor() == max) {
			encontre = true;
		}
		else {
			res++;
		}

	}
	return res;
}

int decisionSegundaMano() {
	int proba = rand() % 100;
	if (proba < 50) {
		return 1;
	}
	else {
		return 2;
	}
}