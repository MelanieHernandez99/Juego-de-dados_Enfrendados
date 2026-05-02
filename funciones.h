#pragma once
#include <string>
#include <iostream>


void jugar();
void NombreJugadores(std::string &jugadores1, std::string &jugadores2);
void dibujarDados(int dados[], int cant);
void dibujarDadosObjetivos(int dados[], std::string jugadores[], int cant);
void jugadorganador(std::string jugadores[], bool turnojugador1);
void estadistica(const std::string &nombre, int puntaje, bool mostrar);
void primeraRondaEmpieza(std::string jugadores[], bool &turnoJugador1);
int TirarDado12Caras();
int TirarDado6Caras();
bool turnoJugador(std::string jugadores[], bool turnojugador1, int dadosStock[], int &cantidadDados, int dadosRival[], int &cantidadRival, int &puntaje, int &ronda);
