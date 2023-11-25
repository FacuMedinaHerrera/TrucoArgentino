#pragma once

#include "probabilidadesIA.h"


int obtenerMasAlto(vector<Carta*> mano) {
	int max = mano[0]->obtenerValor();
	for (int i = 1; i < mano.size(); i++) {
		if (max < mano[i]->obtenerValor()) {
			max = mano[i]->obtenerValor();
		}
	}
	return max;
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
	int res=0;
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