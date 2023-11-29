#pragma once
#include <windows.h>
#include <iostream>
#include "Truco.h"

using namespace std;

int quienGanaEnvido(Jugador& j1, Jugador& ia);

void cantarEnvido(Jugador& j1, Jugador& ia, string quienCanto);//0 si canta el jugador