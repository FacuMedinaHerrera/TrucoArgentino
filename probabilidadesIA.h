#pragma once
#include <Windows.h>
#include<iostream>
#include<vector>
#include "Truco.h"

using namespace std;
int obtenerMasAlto(vector<Carta*>mano);
int respuestaEnvido(int cantOpciones);


int respuestaTruco(int cantOpciones);
int respuestaPrimeraMano();

int eleccionDeCarta(vector<Carta*> manoIA);//siempre jugara su carta mas alta